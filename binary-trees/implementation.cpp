#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<utility>
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
void printleft( Node* root){
    if(root->left==NULL){
        return ;

    }
    cout<<root->data;
    printleft(root->left);
    return;
}

Node* buildtree(Node* &root){
    int data;
    cout<<"enter data ";
    cin>>data;
    root = new Node(data);

    if(data==-1){
        return NULL;
    }
    cout<<"enter data for left of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"enter data for right of " << data<<endl;
    root->right=buildtree(root->right);
    return root;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

void ppo(vector<int> in, vector<int> pre, int idx, int st, int end){
    if(st>end || idx==pre.size() ){ return;
    }
    int root= pre[idx];
    int k;
    for(int i=st; i<=end; i++){
        if(pre[idx]==in[i]){
            k=i;
            break;
        }}
    ppo(in, pre, idx+1, st, k-1);
    ppo(in, pre, idx+k+1, k+1, end);
    cout<<root;
     return;}
int main() {
   vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
   vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
   
   ppo(inorder, preorder,0,0, inorder.size()-1);
   
     
    return 0;
}

void levelordertraversal(Node * root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp= q.front();
        q.pop();
        if(temp==NULL){
        cout<<endl;
            if(!q.empty()){
            q.push(NULL);
                 }
            else{return;}
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
}
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
    cout<<"enter data for left of "<< temp->data;
    int leftdata;
    cin>>leftdata;
    if(leftdata!=-1){
        temp->left=new Node(leftdata);
        q.push(temp->left);
    }
    cout<<"enter data for right of "<< temp->data;
    int rightdata;
    cin>>rightdata;
    if(rightdata!=-1){
        temp->right=new Node(rightdata);
        q.push(temp->right);
    }

    }
}
void countleafnodes(Node* root, int &cnt){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        cnt++;
    }
    preorder(root->left);
    preorder(root->right);
    return;
}
vector<int> verticaltraversal(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    map<int, map<int, vector<int>>> node;
    pair<int, int> p1;
    queue<pair<Node*, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));
    while(!q.empty()){
       pair<Node*, pair<int,int> >temp= q.front();
        Node* frontnode=temp.first;
        int hd= temp.second.first;
        int lvl= temp.second.second;
        node[hd][lvl].push_back(frontnode->data);
        if(frontnode->left){
            q.push(make_pair(frontnode->left, make_pair(hd-1, lvl+1)));}
        if(frontnode->right){
            q.push(make_pair(frontnode->right, make_pair(hd+1, lvl+1)));
        }    
        q.pop();
    }
    for(auto i: node){
        for(auto j: i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;

}


int main(){
    Node* root = NULL;
    buildfromlevelorder(root);
    inorder(root);
    cout<<endl;
    levelordertraversal(root);
    return 0;
}