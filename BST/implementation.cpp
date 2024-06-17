#include <iostream>
using namespace std;
class Node
{ public:
    int data;
    Node *left;
    Node *right;
   
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertintobst(Node* &root, int n){
    if(root==NULL){
        root= new Node(n);
        return root;
    }
    if(n < root->data){
        insertintobst(root->left, n);
    }
    else{
        insertintobst(root->right, n);
    }
    return root;
}

void buildbst(Node* &root){
    int n;
    cin>>n;
    while (n!=-1)    {
        /* code */
        insertintobst(root, n);
        cin>>n;

    }
    
}
int main()
{
    Node *root = NULL;
    buildbst(root);
    return 0;
}