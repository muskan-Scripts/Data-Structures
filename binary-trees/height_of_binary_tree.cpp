#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
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
    return max(heightoftree(root->left), heightoftree(root->right));
}
int main(){
    Node* root = NULL;
    buildfromlevelorder(root);
    cout<<endl;
   cout<<heightoftree(root);
    return 0;
}