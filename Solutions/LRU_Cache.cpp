/*
LeetCode LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );
/*
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/


class LRUCache {
    int capacity;
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> map;
    
    void refresh_position(int key, int value) {
        
        cache.erase(map[key]);
        cache.push_front(make_pair(key,value));
        map[key] = cache.begin();
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            refresh_position(key, (*map[key]).second);
            return (*map[key]).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            refresh_position(key, value);
        } else {
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
            if(map.size() > capacity) {
                map.erase(cache.back().first);
                cache.pop_back();
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


 /*
 Quicker solution:

class LRUCache {
public:
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    int capacity;
    LRUCache(int capacity):capacity(capacity) {
        
    }
    
    int get(int key) {
        auto it=m.find(key);
        if (it==m.end()) return -1;
        l.splice(l.begin(),l,it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it=m.find(key);
        if (it==m.end()){
            if (m.size()==capacity){
                m.erase(l.back().first);
                l.pop_back();
            }
            l.push_front({key,value});
            m[key]=l.begin();
        }else{
            l.splice(l.begin(),l,it->second);
            it->second->second=value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 