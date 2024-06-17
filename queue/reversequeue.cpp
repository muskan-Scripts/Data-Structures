#include<iostream>
#include<queue>
using namespace std;
void displayqueue(queue<int> s){
    if(s.empty()){
        return;
    }
    cout << s.front();
    s.pop();
    displayqueue(s);
    return;
}
// reversed using recursion.......can be done using stack or array
void reversequeue(queue<int> &qu){
    if(qu.empty()){
        return;
    }
    int n=qu.front();
    qu.pop();
    reversequeue(qu);
    qu.push(n);
    return;

}
int main(){
queue<int> q;
for(int i=0; i<8; i++){
    q.push(i);
}
displayqueue(q);
reversequeue(q);
cout<<"\n";
displayqueue(q);


    return 0;
}