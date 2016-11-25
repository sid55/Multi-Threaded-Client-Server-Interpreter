#include "Connection.h"

Connection::Connection(TCPSocket * p_tcpSocket) : Thread(){
    tcpSocket = p_tcpSocket;
    next_connection = NULL;
}

void Connection::setNextConnection(Connection * connection){
    next_connection = connection; 
}

Connection * Connection::getNextConnection(){
    return next_connection;
}

Connection::~Connection(){
    if(tcpSocket != NULL){
        delete (tcpSocket);
    }
}

void * Connection::threadMainBody(void * arg){

    int FILE_LINE_LENGTH = 1024;
     int FILE_LINES_MAX = 10000;

    int jumpCounter = 0; //counter used to cap the an infinite jump
    int labelCounter = 0; //counter used to put labels into a label table
    int fileCounter = 0; //counter to ensure files doesnt exceed max lines

    string line;
    int garbage = 0;
    int counter = 0;
     const char s[3] = " ,";
     char *token;
     char arr[1024];
     map <string, Instruction*> ins;
    ins["ADD"] = new Add();
    ins["SUB"] = new Subtract();
    ins["MUL"] = new Multiply();
    ins["DIV"] = new Divide();  
    ins["ASSIGN"] = new Assign();
    ins["OUT"] = new Out();
    ins["SET_STR_CHAR"] = new SetChar();
    ins["GET_STR_CHAR"] = new GetChar();
    ins["LABEL"] = new Label();
    ins["JMP"] = new JMP();
    ins["JMPZ"] = new JMPZ();
    ins["JMPNZ"] = new JMPNZ();
    ins["JMPGT"] = new JMPGT();
    ins["JMPLT"] = new JMPLT();
    ins["JMPGTE"] = new JMPGTE();
    ins["JMPLTE"] = new JMPLTE();
    ins["SLEEP"] = new Sleep();
    ins["VAR"] = new Value();
	//ins["THREAD_BEGIN"] = new Thread_Begin();
	//ins["THREAD_END"] = new Thread_End();
	//ins["LOCK"] = new Lock();
	//ins["UNLOCK"] = new Unlock();
	//ins["BARRIER"] = new Barrier();


	//NEED TO FIX BELOW TO TAKE IN ANY FILE MAP
	ifstream randfile("test.mis");
	//deleting the content of the .out file.
	ofstream outfile;
	outfile.open(".out",std::ofstream::trunc);
	outfile.close();

	if (randfile.peek() == std::ifstream::traits_type::eof()){
	   std::cout << "failed" << std::endl;
	}else{
	   std::cout << "success" << std::endl;
	}

      while(getline(randfile,line)){
        if(((int)line.length()) > FILE_LINE_LENGTH){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "One of the lines in the file exceeds the maximum length a line is allowed to have" <<endl;
		exit(EXIT_SUCCESS);	
	}	
	labelCounter++;
	fileCounter++;	//used to ensure file lines don't exceed max number of lines
	string insName = "";
	stringstream iss(line);
	getline(iss, insName, ' ');
	Instruction *t = ins[insName];
	if(t!=NULL){
		Instruction *g = t->clone();
		if(dynamic_cast<JUMP*>(g)){
		   garbage = 1;
		}else if(dynamic_cast<Label*>(g)){
		   strcpy(arr, line.c_str());	
	           token = strtok(arr, s);
		   string temp(token);
		   if(token!=NULL){
			token = strtok(NULL, s);
			if(token != NULL){
			  string temp(token);
			  setEntryMap2(temp, labelCounter); 
			}
		   } 
		}
	}
	//ensures number of lines in file doesn't exceed maximum
	if(fileCounter > FILE_LINES_MAX){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "The file has too many number of lines" <<endl;
		exit(EXIT_SUCCESS);
	}
    }
    
    randfile.clear();
    randfile.seekg(0, ios::beg);     
    labelCounter = 0;
    line = "";

    while(getline(randfile,line)){
	labelCounter++;
	vector<Var*> stringBuffer; 
	string temp = line;
 	strcpy(arr, temp.c_str());	
	token = strtok(arr, s); 
	
	while(token != NULL){
	   string temp(token);
           token = strtok(NULL, s);
	
	   if(isDouble(temp) == true){
		stringBuffer.push_back(new Double(stod(temp)));
	   } else if(isInteger(temp) == true){
		stringBuffer.push_back(new Int(stoi(temp)));
	   } else if(isChar(temp) == true){
		if(temp.length() ==  3){
			stringBuffer.push_back(new Char(temp.at(1)));
		} else if(temp.length() == 4){
			char tempChar = temp.at(2);
			char enterChar;
			if(tempChar == 'n'){
				enterChar = '\n';
			} else if(tempChar == 'r'){
				enterChar = '\r';
			} else if(tempChar == 't'){
				enterChar = '\t';
			}
			stringBuffer.push_back(new Char(enterChar));
		}
	   } else{
		//The below method is lokated in checkToken
		stringBuffer = handleStringsMain(stringBuffer,temp);
	   } 
	}

	//Upper part will be put in the client
	//--------------------------------------------------------------
	//Lower part will be put in the server

	string tempName = "";
	stringstream iss(line);
	getline(iss, tempName, ' ');
	Instruction *t = ins[tempName];
	if(t!=NULL){
		Instruction *s = t->clone();	
		if (dynamic_cast<Ops*>(s)){
		   s->doOps(stringBuffer);
		}else if(dynamic_cast<Misc*>(s)){
		   s->doMisc(stringBuffer);
		}else if(dynamic_cast<JUMP*>(s)){
		   int k = s->checkArgs(stringBuffer);
		   if (k!=-99999){ 
		   	randfile.seekg(0, ios::beg);     
		   	labelCounter = 0; 
    		   	for (int m = 0; m < k; m++){
		       	    	labelCounter++;
	  	       	    	getline(randfile, line);
    	           	}
		   }
		} else if(dynamic_cast<Set*>(s)){
		   s->doSet(stringBuffer,labelCounter);
		} else if(dynamic_cast<Char_Ops*>(s)){
		   s->doChar_Ops(stringBuffer);
		} else if(dynamic_cast<Threads*>(s)){
			s->doThread(stringBuffer);
		} else{
		   cout << "never supposed to come here" <<endl;
		}
		//delete(s);
	} else{
		if(tempName.compare("") != 0){
			ofstream outputFile;
			outputFile.open(".err");
			outputFile << "You have not entered a valid instruction type" <<endl;
			exit(EXIT_SUCCESS);
			}
		}
    }


    std::cout << "successfull yaayyy" <<std::endl;
	
    char file_name[1024];
    memset(file_name, 0, 1024);
    int read_bytes = tcpSocket->readFromSocket(file_name, 1023);
    std::cout << "BELOW THERE IS THE OUTPUT OF BUFFER (connection.cpp)" <<std::endl;
    printf("%s\n",file_name);

    if(read_bytes > 0) {        
        if( file_name[strlen(file_name)-1] == '\n' || file_name[strlen(file_name)-1] == '\r'){
            file_name[strlen(file_name)-1] = 0;
        }
        if( file_name[strlen(file_name)-1] == '\n' || file_name[strlen(file_name)-1] == '\r'){
            file_name[strlen(file_name)-1] = 0;
	}

        FILE* f = fopen(file_name, "r");	

	
        if(f != NULL){
            fseek(f,0,2);
            long fsize = ftell(f);
            char * buffer = (char*)calloc(fsize+1, sizeof(char));
	    char line [256];
            fseek(f,0,0);
            fread(buffer,1,fsize,f);
            tcpSocket->writeToSocket(buffer,fsize);

	    //BELOW IS WHERE YOU CAN SEE THE OUPUT OF THE BUFFER
	    std::cout << "SHOWS BELOW IS MAGIC (connection.cpp)" <<std::endl;
	    printf("%s\n",buffer);
	    //int x = 5+3;
	    //fgets(line, 5, f); 

            free(buffer);
            fclose(f);
        }
        else{
            perror("Error With File\n");
            tcpSocket->writeToSocket("Error\n",6);
        }
    }

    // tcpSocket->shutDown();
	std::cout << "hey sucker" << std::endl;



    tcpSocket->shutDown();
    return NULL;
}
