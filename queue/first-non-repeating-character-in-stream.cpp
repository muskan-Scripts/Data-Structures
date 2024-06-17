#include<iostream>
#include<queue>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/first-unique-character-in-a-string_893404?leftPanelTab=0

void printnonrepeatingchar(char arr[], int s){
   queue<char> c;
   int krr[26]={0};
    for(int i=0; i<s; i++){
        c.push(arr[i]);
        int idx= arr[i]-'a';
        krr[idx]++;
        bool printt= false;
        while(!c.empty()){
            if(krr[(c.front())-'a']>1){
                c.pop();
            }
            
            else{
                char p=c.front();
                cout<<p<<" ";
                printt=true;
                break;
            }
        }
        
        

        
    }
return;
   
}
int main(){
    
    char trr[]="bebeeed";
    printnonrepeatingchar(trr, 7);
   
    return 0;
}
// solution to linked ques
// #include <bits/stdc++.h> 
// vector<char> firstNonRepeating(string arr) 
// {
//     vector<char> res;
//     queue<char> c;
//    int krr[26]={0};
//     for(int i=0; arr[i]!='\0'; i++){
//         c.push(arr[i]);
//         int idx= arr[i]-'a';
//         krr[idx]++;
      
//         while(!c.empty()){
//             if(krr[(c.front())-'a']>1){
//                 c.pop();
//             }
            
//             else{
//                 char p=c.front();
//                res.push_back(p);
               
//                 break;
//             }
//         }
        
        

        
//     }
//     return res;
// }