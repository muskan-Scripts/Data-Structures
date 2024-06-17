#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Hashing{
    vector<list<int> > hashtable;
    int buckets;
    Hashing(int size){
        buckets=size;
        hashtable.resize(size);
    }

    int hashvalue(int key){
        return key%buckets;
    }

    void add(int key){
        int idx= hashvalue(key);
        hashtable[idx].push_back(key);
    }

    list<int>::iterator search(int key){
        int idx= hashvalue(key);
       return find(hashtable[idx].begin(), hashtable[idx].end(), key);

    }

    void delete(int key){
        int idx-= hashvalue(key);
        hashtable(idx).erase(search(key));
            }
            
}
int main(){


    return 0;
}