#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//not optimized code----time complexity-> O(n^2)
//optimized code written using pair sum----time complexity-> O(n)
class Node
{
  
public:
    int data;
   Node* left;
   Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
 
};
Node* buildfromlevelorder(Node * &root){
    queue<Node*> q;
    cout<<"enter data for root ";
    int d;
    cin>>d;
    root=new Node(d);
    q.push(root);
    while(!q.empty()){
        Node* temp= q.front();
        q.pop();
    cout<<"enter data for left of "<< temp->data<<" ";
    int leftdata;
    cin>>leftdata;
    if(leftdata!=-1){
        temp->left=new Node(leftdata);
        q.push(temp->left);
    }
    cout<<"enter data for right of "<< temp->data<< " ";
    int rightdata;
    cin>>rightdata;
    if(rightdata!=-1){
        temp->right=new Node(rightdata);
        q.push(temp->right);
    }

    }
}
//height of a binary tree is number of levels of a tree
int heightoftree(Node* root){
    if(root==NULL){
        return 0;
    }
    return max(heightoftree(root->left), heightoftree(root->right))+1;
}
int diameteroftree(Node* root){
    if(root==NULL){
        return 0;
    }
    int opt1=diameteroftree(root->left);
    int opt2=diameteroftree(root->right);
    int opt3=heightoftree(root->left)+heightoftree(root->right)+1;
    return max(max(opt1, opt2), opt3);
    }
int main(){
    Node* root = NULL;
    buildfromlevelorder(root);
    cout<<endl;
   cout<<heightoftree(root);
   cout<<endl<<diameteroftree(root);
    return 0;
}
//optimised approach

// pair<int,int> diameterFast(Node* root) {
//         //base case
//         if(root == NULL) {
//             pair<int,int> p = make_pair(0,0);
//             return p;
//         }
        
//         pair<int,int> left = diameterFast(root->left);
//         pair<int,int> right = diameterFast(root->right);
        
//         int op1 = left.first;
//         int op2 = right.first;
//         int op3 = left.second + right.second + 1;
        
//         pair<int,int> ans;
//         ans.first = max(op1, max(op2, op3));;
//         ans.second = max(left.second , right.second) + 1;

//         return ans;
//     }
//     int diameter(Node* root) {
    
//         return diameterFast(root).first;
        
//     }