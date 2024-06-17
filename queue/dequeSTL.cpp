#include<iostream>
#include<queue>
using namespace std;
int main(int argc, char const *argv[])
{
deque <int> d;
d.push_front(5);
d.push_back(8);
d.push_front(7);
cout<<d.front();
    return 0;
}
