#include<iostream>
#include<stack>
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
void reversekele(queue<int> &q, int k){
stack<int> s;
for(int i=0; i<k; i++){
s.push(q.front());
q.pop();
}
while(!s.empty()){
q.push(s.top());
s.pop();
}
for(int i=0; i<(q.size()-k); i++){
    int t=q.front();
    q.pop();
    q.push(t);
}

}
int main(){
    queue<int> q;
    for(int i=0; i<8; i++){
        q.push(i);
    }
  
    displayqueue(q);
      cout<<"\n";
    reversekele(q, 3);
    displayqueue(q);

    return 0;
}