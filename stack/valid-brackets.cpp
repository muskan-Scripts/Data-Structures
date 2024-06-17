#include<iostream>
#include<stack>
using namespace std;
void checkbr(char * str){
    stack<char> s;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            s.push(str[i]);
        }
        else{
            if(s.empty()){
                cout<< "right brackets are more than left brackets";
                return;
            }
            else{
                if((s.top()=='(' && str[i]==')') || (s.top()=='[' && str[i]==']') ||(s.top()=='{' && str[i]=='}')){
                    s.pop();
                }
                else{
                    cout<<"mismatched brackets";
                    return ;
                }
            }
        }
        i++;
    }
    if(s.empty() && str[i]=='\0'){
        cout<<"valid brackets";
        return;
    }
    else{
        cout<<"left brackets more than right brackets";
        return;
    }
}
bool ispar(string x)
    {
        // Your code here
        
        stack<char> s;
        for(int i=0; x[i]!='\0'; i++){
            char c=x[i];
            cout<<c;
            if(c=='[' || c=='{' || c=='('){
                s.push(c);
            }
            else{
                if(c==']' || c=='}' || c==')'){
                    if(s.empty()){
                        cout<<"first if";
                        return false;
                        

                    }
                    if(c!=s.top()){
                         cout<<"second if";
                        return false;
                       
                    }
                   
                        cout << s.top();
                       s.pop();
                      
                       
                  
                }
            }
        }
        if(!s.empty()){
             cout<<"second if";
            return false;
        }
        
        return true;
    }

int main(){
 
 char yes[]= "{([])}";
 cout<< ispar(yes);

    return 0;
}