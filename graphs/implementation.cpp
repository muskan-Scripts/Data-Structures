#include <bits/stdc++.h>

using namespace std;
class graph{
    public:
    unordered_map<int, list<int>> adj;

    void addedge(int u, int v, bool direction){
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
        return;
    }

    void print(){
        for(auto i:adj){
            cout<< i.first<<"->";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main(){

    graph g;
    int n;
    cout<< "enter number of edges";
    cin>>n;
    for(int i=0; i<n; i++){
        int u,v;
        cin>> u>> v;
        g.addedge(u, v, 0);
        cout <<"edge added";
    }
    g.print();

    return 0;
}