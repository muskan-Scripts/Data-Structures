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
void printnegint(int nums[], int k, int s){
    deque<int> d;
    
    //int s=nums.size();
    for(int i=0; i<k-1; i++){
        if(nums[i]<0){
        d.push_back(i);}
    }
    for(int i=(k-1); i<s; i++){
        
        while(d.front()<=(i-k)){
            d.pop_front();
        }
        if(nums[i]<0){
            d.push_back(i);
        }
        if(!d.empty()){
             cout<<nums[d.front()]<<" ";
           
        }
        else{
            cout<<"0"<<" ";
        }
    }
   
}
int main(){
    
    int arr[]={-8, 2, 3, -6, 10};
    printnegint(arr, 2, 5);
   
    return 0;
}



// vector<int> firstNegative(vector<int> nums, int s, int k) {
	       
// 			vector<int> res;
//         deque<int> d;
    
//     for(int i=0; i<k-1; i++){
//         if(nums[i]<0){
//         d.push_back(i);}
//     }
//     for(int i=(k-1); i<s; i++){
        
//         while(d.front()<=(i-k)){
//             d.pop_front();
//         }
//         if(nums[i]<0){
//             d.push_back(i);
//         }
//         if(!d.empty()){
//              res.push_back(nums[d.front()]);
           
//         }
//         else{
//             res.push_back(0);
//         }
//     }
//         return res;
// }