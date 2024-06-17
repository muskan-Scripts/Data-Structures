#include <iostream>
#include <stack>
//if(element at top is smaller than the element at bottom then push top element at bottom of stack)else(push the element 
//at a position where the elements below are smaller than the to-be-pushed element)
using namespace std;
int eleatbott(stack<int> st){
    int bott;
    
    while(!st.empty()){
        bott=st.top();
        st.pop();
       
    }
    return bott;
        }
void insertatbott(stack<int> &st, int n){
        if (st.empty())
        {
            st.push(n);
            return;
        }
        int num = st.top();
        st.pop();
        insertatbott(st, n);
        st.push(num);
        return;
    }
void insertatpos(stack<int> &st, int n){
        if (st.top()<n)
        {
            st.push(n);
            return;
        }
        int num = st.top();
        st.pop();
        insertatpos(st, n);
        st.push(num);
        return;
    }
    
    
    void sortstack(stack<int> &st){
        if(st.empty()){return;}
        int num = st.top();
        st.pop();
        sortstack(st);
        if(num< eleatbott(st)){
            insertatbott(st, num);
        }
        else{
            insertatpos(st, num);
        }
        return;
        

    }

int main()
{
    stack<int> s;
   s.push(6);
   s.push(5);
   s.push(9);
   s.push(7);
   s.push(12);
   s.push(0);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    s.push(6);
   s.push(5);
   s.push(9);
   s.push(7);
   s.push(12);
   s.push(0);
sortstack(s);
cout<<"\n";
while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}