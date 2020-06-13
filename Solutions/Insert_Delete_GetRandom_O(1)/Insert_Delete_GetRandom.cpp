class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end())
            return false;
        
        v.push_back(val);
        m[val] = v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;
        
        auto it = m.find(val);
        v[it->second] = v.back();
        v.pop_back();
        m[v[it->second]] = it->second;
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};

    static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


/*
Fastest:

class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>vec;
    RandomizedSet() {
      
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        
        vec.push_back(val);
         mp[val] = vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
        
        if(mp.find(val)==mp.end()) return false;
        int idx = mp[val];
        int lastidx = vec.size()-1;
        int lastele = vec[lastidx];
        swap(vec[idx],vec[lastidx]);
        mp[lastele] = idx;
        mp.erase(val);
      
        vec.pop_back();
       
      //  if(mp.find(0)!=mp.end()){cout << "dfdf " << val << endl;}
        return true;
    }
    
    int getRandom() {
       // srand (time(NULL)); 
        int r = (rand() % vec.size());
        
        return vec[r];
    }
};


static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

*/