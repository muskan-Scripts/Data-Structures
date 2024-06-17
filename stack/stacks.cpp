//st.pop top size push 
//leetcode delete middle element of stack, valid parantheses, insert a element at bottom of its stack, reverse stack using recursion
//sort a stack , redundant bracket, next smaller element (array),
#include<iostream>
using namespace std;
class stacks{
    public:
 int * arr;
 int top;
 int size;

 stacks(int s){
    this->size=s;
    arr=new int[size];
    top=-1;
 }

 void push(int num){

    if((size-top)>1){

    top++;
    arr[top]=num;}
    else{
        cout << "stack is full";
    }
 }

 void pop(){
    if(top>=0){
        top--;
    }
    else{cout << "stack is empty already";}
 }
 int peek(){
    if(top>=0){
        return arr[top];
    }
    else{
        cout<< "stack is empty";
        return -1;
    }
 }
 bool isempty(){
    if(top<=0){
        return true;
    }
    else{ return false;}
 }






};


int main(){
    stacks s(7);
    s.push(3);
    int k=s.peek();
    cout<< k<< "\n";
    s.pop();
    s.peek();
    return 0;
}