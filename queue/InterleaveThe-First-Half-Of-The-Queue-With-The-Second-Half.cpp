#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void displayqueue(queue<int> s){
    if(s.empty()){
        return;
    }
    cout << s.front()<<" ";
    s.pop();
    displayqueue(s);
    return;
}
void interleave(queue<int> &q){
    stack<int> s;
    int size=q.size();
    for(int i=0; i<size/2; i++){
        s.push(q.front());
        q.pop();
    }
    for(int i=0; i<size/2; i++){
        q.push(s.top());
        s.pop();
    }
    for(int i=0; i<size/2; i++){
       int p=q.front();
       q.pop();
       q.push(p);
    }
    for(int i=0; i<size/2; i++){
        s.push(q.front());
        q.pop();
    }
    for(int i=0; i<size/2; i++){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
    return;
}
int main(){
    queue<int> s;
    for(int i=1; i<11; i++){
        s.push(i);
    }
    displayqueue(s);
 interleave(s);
 cout<<"\n";
displayqueue(s);
    return 0;
}