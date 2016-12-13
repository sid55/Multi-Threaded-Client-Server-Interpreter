#include "Thread_End.h"



Thread_End::Thread_End(void *(*_threadRoutine) (void *)):Thread(_threadRoutine){

}

// Thread_End::Thread_End(const Var& v){
// 	tVec = new vector<vector<Var*> >(*)
// }



void *runner(void *val){
	cout << "In runner function" << endl;
	return nullptr;
}

void Thread_End::doThread(vector < vector<Var*> >&vec) {

	void *ptr = &vec;
	Thread *t = new Thread_End();
	t->threadMainBody(ptr);
	//t->cleanup(t);

        //pthread_exit(NULL); // Invoke pthread_exit to terminate and invoke the cleanup functions.

}

void *Thread_End::threadMainBody (void * arg){
	
	vector < vector<Var*> > *vec;
	vec = (vector < vector<Var*> > *)arg;
	//vector<Var*> stringBuffer = vec->at(1);


	pthread_mutex_lock(&mutex); // Acquire lock before forking the thread
    started=true; // Set started to true
    // Invoke pthread create and pass to the routine the current object as the start routine need to be static
    int created = pthread_create (&pthread,&pthread_attr,threadRoutine,this);
    if ( created != 0 ) // If the return in not zero then pthread_create failed
    {
        // Print an error message with the return integer value
        printf ("error creating thread: %d\n",created);
        // Check the error type and print an equivalent error message
        if (created == EAGAIN) printf ("EAGAIN generated\n");
        else if (created == EINVAL) printf ("EINVAL generated\n");
        else if (created == EPERM) printf ("EPERM generated\n");
        else if (created == ENOMEM) printf ("ENOMEM generated\n");
        started= false; // Set started to false
    }
    else setRunning(true); // Else thread is marked running 




    //Create label tabel for this thread

    int labelCounter = 0;
    int thread = 0; 

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
	ins["THREAD_BEGIN"] = new Thread_Begin();
	ins["THREAD_END"] = new Thread_End();
	ins["LOCK"] = new Lock();
	ins["UNLOCK"] = new Unlock();
	ins["BARRIER"] = new Barrier();



	//cout << "THE TVEC SIZE IS: " << vec->size() <<endl;
	for (int i = 0; i<vec->size(); i++){
		//vector<Var*> stringBuffer = t->tVec.at(i);
		vector<Var*> stringBuffer = vec->at(i);
	    Instruction *p = ins[stringBuffer.at(0)->getString()];
		//Instruction *p = ins[stringBuffer.at(0)->getString()];
	       // Instruction *m = p->clone();
		//cout << "came into for loop at: " <<i << " " <<stringBuffer.at(0)->getString() <<endl;	


		if(p!=NULL){

		Instruction *s = p->clone();	
		if (dynamic_cast<Ops*>(s) && thread == 0){
		   s->doOps(stringBuffer);
		}else if(dynamic_cast<Misc*>(s) && thread == 0){
		   s->doMisc(stringBuffer);
		}else if(dynamic_cast<JUMP*>(s) && thread == 0){
		   int k = s->checkArgs(stringBuffer);
		   if (k!=-99999){ 
		   	//randfile.seekg(0, ios::beg); 
			i = 0;    
		   	labelCounter = 0; 
    		   	for (int m = 0; m < k; m++){
		       	    	labelCounter++;
				i++;
	  	       	    	//getline(randfile, line);
    	           	}
		   }
		} else if(dynamic_cast<Set*>(s) && thread == 0){
		   s->doSet(stringBuffer,labelCounter);
		} else if(dynamic_cast<Char_Ops*>(s) && thread == 0){
		   s->doChar_Ops(stringBuffer);
		} else if(dynamic_cast<Threads*>(s) && thread == 0){
			//have globalvector and add this stringBuffer to it
			//if statemtn checking if thread_end, if it is then
			  //past the global vector into thread_begin method
			//throw error of no thread_end found when thread_begin called first	

			//GOT TO EDIT BELOW METGHOD BY CREATING IT
			
			if(dynamic_cast<Lock*>(s)){
			  s->doThreadMethod(stringBuffer);
			  //doubleVec.push_back(stringBuffer);
			}else if(dynamic_cast<Unlock*>(s)){
			  //s->doThread(stringBuffer);
			  s->doThreadMethod(stringBuffer);
			}else if(dynamic_cast<Barrier*>(s)){
			  s->doThreadMethod(stringBuffer);
			}
			
			//cout << "got into thread part for dynamic cast(Thread_End.cpp)" <<endl;

		} else{
		   //cout << "never supposed to come here" <<endl;
		}
		//delete(s);
	} else{
			ofstream outputFile;
			outputFile.open(".err");
			outputFile << "You have not entered a valid instruction type" <<endl;
			exit(EXIT_SUCCESS);

    // int labelCounter = 0;
    // int thread = 0; 

    // map <string, Instruction*> ins;
    // ins["ADD"] = new Add();
    // ins["SUB"] = new Subtract();
    // ins["MUL"] = new Multiply();
    // ins["DIV"] = new Divide();  
    // ins["ASSIGN"] = new Assign();
    // ins["OUT"] = new Out();
    // ins["SET_STR_CHAR"] = new SetChar();
    // ins["GET_STR_CHAR"] = new GetChar();
    // ins["LABEL"] = new Label();
    // ins["JMP"] = new JMP();
    // ins["JMPZ"] = new JMPZ();
    // ins["JMPNZ"] = new JMPNZ();
    // ins["JMPGT"] = new JMPGT();
    // ins["JMPLT"] = new JMPLT();
    // ins["JMPGTE"] = new JMPGTE();
    // ins["JMPLTE"] = new JMPLTE();
    // ins["SLEEP"] = new Sleep();
    // ins["VAR"] = new Value();
	// ins["THREAD_BEGIN"] = new Thread_Begin();
	// ins["THREAD_END"] = new Thread_End();
	// ins["LOCK"] = new Lock();
	// ins["UNLOCK"] = new Unlock();
	// ins["BARRIER"] = new Barrier();


	// cout << "THE TVEC SIZE IS: " << t->tVec.size() <<endl;
	// for (int i = 0; i<t->tVec.size(); i++){
	// 	vector<Var*> stringBuffer = t->tVec.at(i);
	// 	Instruction *p = ins[stringBuffer.at(0)->getString()];
	//        // Instruction *m = p->clone();
	// 	//cout << "came into for loop at: " <<i << " " <<stringBuffer.at(0)->getString() <<endl;	



	// 	if(t!=NULL){
	// 	Instruction *s = p->clone();	
	// 	if (dynamic_cast<Ops*>(s) && thread == 0){
	// 	   s->doOps(stringBuffer);
	// 	}else if(dynamic_cast<Misc*>(s) && thread == 0){
	// 	   s->doMisc(stringBuffer);
	// 	}else if(dynamic_cast<JUMP*>(s) && thread == 0){
	// 	   int k = s->checkArgs(stringBuffer);
	// 	   if (k!=-99999){ 
	// 	   	//randfile.seekg(0, ios::beg); 
	// 		i = 0;    
	// 	   	labelCounter = 0; 
    // 		   	for (int m = 0; m < k; m++){
	// 	       	    	labelCounter++;
	// 			i++;
	//   	       	    	//getline(randfile, line);
    // 	           	}
	// 	   }
	// 	} else if(dynamic_cast<Set*>(s) && thread == 0){
	// 	   s->doSet(stringBuffer,labelCounter);
	// 	} else if(dynamic_cast<Char_Ops*>(s) && thread == 0){
	// 	   s->doChar_Ops(stringBuffer);
	// 	} else if(dynamic_cast<Threads*>(s) && thread == 0){
	// 		//have globalvector and add this stringBuffer to it
	// 		//if statemtn checking if thread_end, if it is then
	// 		  //past the global vector into thread_begin method
	// 		//throw error of no thread_end found when thread_begin called first	

	// 		//GOT TO EDIT BELOW METGHOD BY CREATING IT
	// 		/*
	// 		if(dynamic_cast<Lock*>(s)){
	// 		  s->doThreadMethod(stringBuffer);
	// 		  //doubleVec.push_back(stringBuffer);
	// 		}else if(dynamic_cast<Unlock*>(s)){
	// 		  //s->doThread(stringBuffer);
	// 		  s->doThreadMethod(stringBuffer);
	// 		}else if(dynamic_cast<Barrier*>(s)){
	// 		  s->doThreadMethod(stringBuffer);
	// 		}
	// 		*/
	// 		cout << "got into thread part for dynamic cast(Thread_End.cpp)" <<endl;

	// 	} else{
	// 	   //cout << "never supposed to come here" <<endl;
	// 	}
	// 	//delete(s);
	// } else{
	// 		ofstream outputFile;
	// 		outputFile.open(".err");
	// 		outputFile << "You have not entered a valid instruction type" <<endl;
	// 		exit(EXIT_SUCCESS);
			
		}//closes else down here





	}//closes for loop
	//cout << tVec.size() << " this is the size of tVec in threadMainBodoy"  <<endl;
	
	return nullptr;
}

Instruction* Thread_End::clone(){
	Thread_End *threade = new Thread_End();
	return threade;
}


Thread_End::~Thread_End(){
    //pthread_exit(NULL); // Invoke pthread_exit to terminate and invoke the cleanup functions.

}
