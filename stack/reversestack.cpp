#include <iostream>
#include <stack>
//refer gfg algo 
// it takes help of(insert at bottom function)
// another long approch could be storing all elements in an array and then pushing it into stack in reverse. or by using 
//another stack but that requires extra space
using namespace std;
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
    
    void revstack(stack<int> & st)
    {
        if (st.empty())
        {
            return;
        }
        int num = st.top();
        st.pop();
        revstack(st);
        insertatbott(st, num);
        return;
    }
    

int main()
{
    stack<int> s;
    for (int i = 1; i < 5; i++)
    {
        s.push(i);
    }
    for (int i = 1; i < 5; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
    for (int i = 1; i < 5; i++)
    {
        s.push(i);
    }
revstack(s);
cout << "\n";

    for(int i = 1; i < 5; i++)
    {
        cout<< s.top() << " ";
        s.pop();
    }

    return 0;
}