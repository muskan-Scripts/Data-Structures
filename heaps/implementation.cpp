#include<iostream>
#include<queue>
using namespace std;


class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size++;
        int index=size;
        arr[index]= val;

        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent], arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }}
    void print(){
        for(int i=1; i<=size; i++ ){
            cout<< arr[i]<<" ";
        }cout<<endl;
    }   
    int deletefromheap(){
        if(size==0){
            cout<<"nothing to delete";
            return -1;
        }

        int ret=arr[size];
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int leftchild= (2*i);
            int rightchild= (2*i)+1;
            if(leftchild<size && arr[i]<arr[leftchild]){
                swap(arr[leftchild], arr[i]);
                i=leftchild;
            }
            else if(rightchild<size && arr[i]<arr[rightchild]){
                swap(arr[i], arr[rightchild]);
                i=rightchild;
            }
            else{
                return ret;
            }
        }
        return ret;
    }
};
void heapify(int arr[], int n, int i){
    int largest=i;
    int left= 2*i;
    int right= 2*i  +  1;

    if(left < n && arr[largest]<arr[left]){
        largest =left;
    }
    if(right< n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
    return;
}

void heapSort(int arr[], int n){
    int t=n;
    while(t>2){
        swap(arr[1], arr[t]);
        t--;
        heapify(arr, t, 1);
    }
    return ;
}
int main(){
    heap h;
    // h.insert(3);
    //  h.print(); 
    // h.insert(9);
    //  h.print();
    // h.insert(4);
    //  h.print();
    // h.insert(10);
    //  h.print();
    // h.insert(8);
    // h.print();
    // h.deletefromheap();
    // h.deletefromheap();
    // h.print();

    // int s[]={-1,2,6,10,11,4,1,7};
    // for(int i=7/2; i>0; i-- ){
    //     heapify(s, 7, i);
    // }
    // for(int i=1; i<8; i++){
    //     cout<<s[i]<<" ";
    // }
    // heapSort(s, 7);
    // cout<<endl;
    // for(int i=1; i<8; i++){
    //     cout<<s[i]<<" ";
    // }
    // priority_queue<int> pq;
    // pq.push(1);
    // pq.push(5);
    // pq.push(4);
    // cout<<"\n"<<pq.top();
    h.insert(10);
    h.insert(8);
    h.insert(9);
    h.insert(6);
    h.insert(7);
    h.insert(5);
    h.print();
    h.deletefromheap();
    h.print(); 

    return 0;
}