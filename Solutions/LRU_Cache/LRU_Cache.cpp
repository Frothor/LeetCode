class LRUCache
{
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;

    void refresh_position(int key, int value)
    {

        cache.erase(map[key]);
        cache.push_front(make_pair(key, value));
        map[key] = cache.begin();
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (map.find(key) != map.end())
        {
            refresh_position(key, (*map[key]).second);
            return (*map[key]).second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            refresh_position(key, value);
        }
        else
        {
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
            if (map.size() > capacity)
            {
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

///////////////////////////////////////////////////////////////////////
//Another
struct LL
{
    int key;
    LL *next;
    LL *prev;

    //constructor
    LL(int k) : key(k), next(nullptr), prev(nullptr)
    {
    }
};

class LinkedList
{

    LL *head;
    LL *tail;
    int max_size;
    int c_size = 0;

public:
    LinkedList(int msize)
    {
        max_size = msize;
        head = nullptr;
        tail = nullptr;
    }

    LL *insert(int key)
    {
        LL *node = new LL(key);
        if (head == nullptr && tail == nullptr)
        {
            head = node;
            tail = node;
            c_size++;
            return node;
        }

        tail->next = node;
        node->prev = tail;
        c_size++;
        tail = node;
        return node;
    }

    int removeHead()
    {

        int data = head->key;
        LL *newHead = head->next;
        head = nullptr;
        delete head;
        head = newHead;
        c_size--;
        return data;
    }

    void MakeMostRecentlyUsedNode(LL *node)
    {

        if (node == tail || c_size <= 1)
            return;

        if (node == head)
        {
            LL *newHead = head->next;
            newHead->prev = nullptr;
            head = newHead;
            //
        }
        else
        {
            LL *newTail = node;
            LL *prevNode = node->prev;
            LL *nextNode = node->next;

            //remove from this list
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }

        node->prev = tail;
        tail->next = node;
        tail = node;
        tail->next = nullptr;
    }

    void printLL()
    {
        LL *pNode = head;
        cout << "HEAD->";
        while (pNode != nullptr)
        {
            cout << pNode->key << "(" << pNode << ")"
                 << "->";
            pNode = pNode->next;
        }
        cout << "TAIL\n";
    }

    int size()
    {
        return c_size;
    }

    int capacity()
    {
        return max_size;
    }
};

class LRUCache
{
    int listSize_;
    LinkedList *cacheKeys_;
    unordered_map<int, LL *> keyAddrMap_;
    unordered_map<int, int> keyValueMap_;

public:
    LRUCache(int capacity)
    {
        listSize_ = capacity;
        cacheKeys_ = new LinkedList(listSize_);
    }

    int get(int key)
    {
        //cout << __FUNCTION__ << "\t" << key << ":" ;
        auto itKeyIterator = keyValueMap_.find(key);
        int val = (itKeyIterator == keyValueMap_.end()) ? -1 : itKeyIterator->second;
        //cout << " " << val << endl;
        if (val == -1)
            return val;
        auto itKeyAddrIterator = keyAddrMap_.find(key);
        LL *addrNode = itKeyAddrIterator->second;

        cacheKeys_->MakeMostRecentlyUsedNode(addrNode);
        //cacheKeys_->printLL();
        return val;
    }

    void put(int key, int value)
    {
        //does key exist
        //cout << __FUNCTION__ << "\t" << key << ":" << value << endl;
        auto itKeyIterator = keyAddrMap_.find(key);
        if (itKeyIterator != keyAddrMap_.end())
        {
            //key exists
            //cout << "KeyExists " << endl;
            //update in keyValueMap
            keyValueMap_[key] = value;
            //move position in LL
            LL *addrNode = itKeyIterator->second;

            cacheKeys_->MakeMostRecentlyUsedNode(addrNode);
            //cacheKeys_->printLL();
            return;
        }

        //key does not exists
        //cout << "KeyNotExists " << endl;
        //is cache size full
        //no
        if (cacheKeys_->size() < listSize_)
        {

            //insert key in cache
            LL *addr = cacheKeys_->insert(key);
            //update addr map
            keyAddrMap_[key] = addr;

            //update value map
            keyValueMap_[key] = value;
        }
        else
        {
            //cache full, yes
            int removedKey = cacheKeys_->removeHead();

            //remove Key from value and addrMap
            keyAddrMap_.erase(removedKey);
            keyValueMap_.erase(removedKey);

            LL *addr = cacheKeys_->insert(key);
            //update addr map
            keyAddrMap_[key] = addr;

            //update value map
            keyValueMap_[key] = value;
        }

        //cacheKeys_->printLL();
    }
};
