#include "out.h"
#include <sstream>

//fstream txtfile(".out", ios::out | ios::app);

Out::Out(){

}

void Out::addStrChar(string tempo2){
	fstream txtfile(".out", ios::out | ios::app);
	//fstream txtfile(".out", ios::app | ios::in | ios::out);
    // std::ifstream file(".out", ios::app); //goes to the very end of the file and write from there 
    // ofstream txtfile(".out", ios::app);
        string appendSlash;
	     string slash = "\\";
	     for(int k =0; k < (int)(tempo2.length()); k++){
	        stringstream ss;
	        string s;
	        char tempChar = tempo2.at(k);
	   	ss << tempChar;
	    ss >> s;
			ss.str("");	
		if(s.compare(slash)==0){
		  k = k + 1;
		  if(k < ((int)(tempo2.length()))){
			stringstream ss2;
			string s2;
			char tempChar2 = tempo2.at(k);
			ss2 << tempChar2;
			ss2 >> s2;
			ss2.str("");
			s.append(s2); //s contains the \n or \r or etc
			string n = "\\n";
			string r = "\\r";
			string t = "\\t";
			if(s.compare(n)==0){
			   txtfile << "\n";
			}else if(s.compare(t) == 0){
			   txtfile << "\t";
			}else if(s.compare(r) == 0){
			   txtfile << "\r";	
			}else{
			   ofstream outputFile;
			   outputFile.open(".err");
			   outputFile << "You have a backslash in one of your OUT statements that is not a valid backslash statement" <<endl;
			   exit(EXIT_SUCCESS);
			}	
		  }else{
			//for just a slash with nothing after
			ofstream outputFile;
			outputFile.open(".err");
			outputFile << "You're backslash does not have a character after the backslash symbol" <<endl;
			exit(EXIT_SUCCESS);
		  }   
		}else{
		  txtfile << tempChar;
		}
	     }

}

//error checking to see if right or not, 
//
void Out::doMisc(vector<Var*>const&vec){
    Misc::checkOps(vec);
		fstream txtfile(".out", ios::out | ios::app);
//fstream txtfile(".out", ios::in | ios::out | ios::app);


	//fstream txtfile(".out", ios::app | ios::in | ios::out);
    // std::ifstream file(".out", ios::app); //goes to the very end of the file and write from there 
    // std::ofstream txtfile(".out", ios::app); //creates the file if it's not there already '
    for( int i = 1; i<vec.size(); i++){
	if (dynamic_cast<Int*>(vec.at(i))){
          txtfile << vec.at(i)->getInt();
					txtfile.close();
        }else if (dynamic_cast<Double*>(vec.at(i))){
          txtfile << vec.at(i)->getDouble();
					txtfile.close();
        }else if (dynamic_cast<Char*>(vec.at(i))){
          txtfile << vec.at(i)->getChar();
					txtfile.close();
        }else if (dynamic_cast<String*>(vec.at(i))){
          if(isString(vec.at(i)->getString())==1){
	     string tempo = (vec.at(i)->getString());
		 //cout << tempo << endl;
		 cout << "got to first part" << endl;
		 //cout << "should go in here second" << endl;
	     string tempo2 = tempo.substr(1,((int)tempo.length())-2);
	     	     //txtfile << tempo2 << "\n";
	     addStrChar(tempo2);
	   }else{
	     //cout << "good keep going" <<endl;
	     Var *temp2 = getEntry(vec.at(i)->getString());
		 //cout << "got my temp" <<endl;
	       if(temp2!=NULL){
			//cout << "its not null" <<endl;
			//cout <<vec.at(i)->getString()<<endl;
			//cout<<temp2->getDouble()<<endl;
		 	if (dynamic_cast<Int*>(temp2)){
				//cout <<"came to int" <<endl;
          			txtfile << temp2->getInt();
								txtfile.close();
        		}else if (dynamic_cast<Double*>(temp2)){
          		txtfile << temp2->getDouble();
							txtfile.close();
       		 	}else if (dynamic_cast<Char*>(temp2)){

				//cout <<"came to char " << temp2->getChar() << endl;
					cout << "should go in here first" <<endl;
					cout << temp2->getChar() << endl;
					char c = temp2->getChar();
					string a(1, c);
         	 		txtfile << a;
								txtfile.close();
					//cout << temp2->getChar() << " testing " << endl;
        		}else if (dynamic_cast<String*>(temp2)){
				string tempo = temp2 ->getString();
				string tempo2 = tempo.substr(1,((int)tempo.length())-2);
				addStrChar(tempo2);
				
			 
				//txtfile << tempo2 << "\n";
			}else{
				cout<<"You have an error when doing the out function"<<endl;
			}	
	      	}else{
						ofstream outputFile;
						outputFile.open(".err");
						outputFile << "You have not entered proper parameters for an OUT statement" <<endl;
						exit(EXIT_SUCCESS);
					}
	   		}
      }else{
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have not entered a valid object type" <<endl;
		exit(EXIT_SUCCESS);
	}
    }
}

Instruction* Out::clone(){
	Out *out = new Out();
	return out;
}


Out::~Out(){

}


