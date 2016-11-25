#include "checkToken.h"
#include "String.h"
#include <typeinfo>
#include <sstream>

string globalString = "";
int stringCount = 0;

bool isDouble(const string &s){
	char dot = '.';
    bool isdot = false;
    int length = (int) s.length();
    
	for(int i=0;i<length;i++){
        char temp = s.at(i);
        if(temp == dot)
            isdot = true;   
    }
    char* endptr = 0;
    strtod(s.c_str(), &endptr);
    
    if(*endptr == 0 && isdot == true)
        return true;
    else 
        return false;
}

bool isInteger(const string&s){
	char dot = '.';
    bool isdot = false;
    int length = (int) s.length();
    
	for(int i=0;i<length;i++){
        char temp = s.at(i);
        if(temp == dot)
            isdot = true;
    }

    char* endptr = 0;
    strtod(s.c_str(), &endptr);
    
    if(*endptr == 0 && isdot == false)
        return true;
	else 
    	return false;
}

bool isChar(const string&s){
	int length = (int) s.length();	
	string temp = "'";
	stringstream ss;
	stringstream ss2;
	string s2;
	string s3;

	char c = s.at(0);
	ss << c;
	ss >> s2;

	char b = s.at(length - 1);
	ss2 << b;
	ss2 >> s3;		
	
	if (length == 3 && s2.compare(temp)==0 && s3.compare(temp)==0){
	  return true;
	} else if(length == 4){
		char temp = s.at(1);
		char temp2 = s.at(2);
		if(temp == '\\'){
			if(temp2 == 'n' || temp2 == 'r' || temp2 == 't'){
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else{
	  return false;
	}
}

bool isString(const string&s){
	int length = (int) s.length();
  	//string temp = """;
	stringstream ss;
	stringstream ss2;
	stringstream ss3;
	string s2;
	string s3;
	string s4;

	char c = s.at(0);
	ss << c;
	ss >> s2;

	char b = s.at(length - 1);
	ss2 << b;
	ss2 >> s3;

	char a = '"';
	ss3 << a;
	ss3 >> s4;		
	
	if (s2.compare(s4)==0 && s3.compare(s4)==0){
	  return true;
	}else{
	  return false;
	}
}

vector<Var*> handleStringsMain(vector<Var*>& stringBuffer,string temp){
		int length = (int) temp.length();
  		//string temp = """;
		stringstream ss;
		stringstream ss2;
		stringstream ss3;
		string s2;
		string s3;
		string s4;
	
		char c = temp.at(0);
		ss << c;
		ss >> s2;
			
		char b = temp.at(length - 1);
		ss2 << b;
		ss2 >> s3;

		char a = '"';
		ss3 << a;
		ss3 >> s4;

		if(s2.compare(s4)==0 && s3.compare(s4)==0){
		   stringBuffer.push_back(new String(temp));
		}
		else if(s2.compare(s4)==0 && stringCount == 0){
		   stringCount = 1;   
	           globalString.append(temp);	
		}else if(s3.compare(s4)==0 && stringCount ==1){
		   globalString.append(" ");
		   globalString.append(temp);
		   stringCount = 0;
		   stringBuffer.push_back(new String(globalString));
		   globalString = "";
	       }else if(stringCount == 1){
		   globalString.append(" ");
		   globalString.append(temp);
               }else if(s2.compare(s4)!=0 && s3.compare(s4)!=0){
		  globalString = temp; 
	          stringBuffer.push_back(new String(globalString));
		  globalString = "";
		}
	      return stringBuffer;	
	   }

