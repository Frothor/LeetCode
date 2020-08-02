class MyHashSet {
public:
    vector<int> v;
    /** Initialize your data structure here. */
    MyHashSet() {
        vector<int> in(1000001, false);
        v = in;
    }
    
    void add(int key) {
        v[key] = true;
    }
    
    void remove(int key) {
        v[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return v[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


/*
Most common
#include <unordered_map>

class MyHashSet {
public:
    MyHashSet() {
        m.clear();
    }
    
    void add(int key) {
        m[key] = 1;
    }
    
    void remove(int key) {
        m.erase(key);
    }
    
    bool contains(int key) {
        if(m.find(key)!=m.end())
            return true;
        else
            return false;
    }
    
    private:
    unordered_map<int,int> m;
};

Second most common:
class MyHashSet {
public:
    vector<bool> v;
    
    MyHashSet() {
        v.resize(1024);
    }
    
    void add(int key) {
        while(key>=v.size()){
            v.resize(v.size()*2);
        }
        v.at(key)=true;
    }
    
    void remove(int key) {
        if(key<v.size())  v.at(key)=false; 
    }
    
    bool contains(int key) {
       return key<v.size() && v.at(key);
    }
};

Fastest:
class MyHashSet {
    int *arr;
public:
    MyHashSet() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
       arr=new int[1000001] ;
       memset(arr,-1,sizeof(arr));
    }
    
    void add(int key) {
        arr[key]=1;
    }
    
    void remove(int key) {
        arr[key]=-1;
    }
    
    bool contains(int key) {
        return arr[key]==1;
    }
};
*/