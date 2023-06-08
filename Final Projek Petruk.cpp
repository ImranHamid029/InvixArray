#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> convertToInfixArray(const string& text){
    vector<string> infixArray;
    string elemen;
    for(size_t i=0;i<text.length();i++){
    	char a=text[i];
		if(a==' '){
		    continue;
		}
        else if(a=='+' || a=='*' || a=='/' ||a=='(' || a==')'){
            if(!elemen.empty()){
                infixArray.push_back(elemen);
                elemen.clear();
            }
            infixArray.push_back(string(1,a));
            
            
        }
        else if(a=='-'){
        	
			if(!elemen.empty() && (i==0 || text[i-1]=='('|| text[i-1]=='+'||text[i-1]=='/')){
				if(!elemen.empty()){
				infixArray.push_back(elemen);
                elemen.clear();
				}
				infixArray.push_back(string(1,a));
				
			}
			else{
        		elemen+= a;
        		
			}
        	
		}
        else{
    		elemen += a;
    		
		}
    }
 if(!elemen.empty()){
     infixArray.push_back(elemen);
 }
   
    return infixArray; 
}
int main(){
	string text = "5*(-6+2)-12/-4";
    vector<string> infixArray = convertToInfixArray(text);

    for (const string b : infixArray) {
        cout << b <<endl;
    }
}
