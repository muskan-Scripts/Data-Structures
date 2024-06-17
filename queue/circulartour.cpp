#include<iostream>
#include<queue>
using namespace std;
int possibleStation(int arr[][2], int size){
    int start=0,end=start, balance=0;
    while(start<size){

        if(arr[end%size][0]-arr[end%size][1]+balance>=0){
            end=(end+1);
            balance=balance+arr[end%size][0]-arr[end%size][1];
        }
        else{
            start=end+1;
            end=start;
            balance=0;
        }
        
        
    }
    if(start<size){
        return size;
    }
    else{
        return -1;
    }
}
int main(){
     int arr[][2] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
     
     cout << possibleStation(arr,4);
    return 0;
}