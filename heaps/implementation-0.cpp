#include<iostream>
using namespace std;
class heap{
    public:

    int arr[100];
    int size;
    heap(){
        size=-1;
    }
    void insert(int val){
        size++;
        arr[size]=val;
        int i=size;
        while(i>0){
            int parent=(i-1)/2;
            if(arr[parent]<arr[i]){
                swap(arr[parent], arr[i]);
                i=parent;
            }
            else{
                return;
            }
        }
        return;
    }
    void deletefromheap(){
        if(size==-1){
            cout<<"no elements present";
            return;
        }
        swap(arr[0],arr[size]);
        size--;
        int i=0;
        int leftidx=(2*i)+1;
        int rightidx=(2*i)+2;
        while(i<size){
            if(leftidx<size && arr[leftidx] > arr[i]){
                
            }
        }
    }
}
int main(){
    return 0;
}