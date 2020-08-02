# Solution

## 1. O(1) Solution
### Idea Is :
* Create one Boolen arry Of maxSize + 1 and initialize each elemnt by false
* For **Add** Do Mark That Place True
* For **Remove** Do mark That Place False
* For **contain** Do Retun arr[Key]

As Each Oparetion Take O(1)Time
So **Time Complexcity - O(No_of_oparetion)**
And as U use Array of size MaxSize So **Space Complexcity - O (MaxSize)**
```c++
class MyHashSet {
public:
    vector<bool>arr;
    MyHashSet() {
        vector<bool>t(100001,false);
        arr = t;
    }
    void add(int key){
        arr[key] = true;
    }
    void remove(int key){
        arr[key]=false;
    }
    bool contains(int key){
        return arr[key];
    }
};
```

## 2. This Is Brute Force Approch
```
Time Complexcity  - O(N*No_of_oparetion)
Space Complexcity -	O(N)
```
```c++
class MyHashSet {
public:
    vector<int>arr;
    MyHashSet() {
        arr.clear();
    }
    void add(int key) {
        if(arr.empty())
            arr.push_back(key);
        else{
            if(find(begin(arr),end(arr),key)==end(arr))arr.push_back(key);
        }
    } 
    void remove(int key) {
        if(arr.empty())
            return;
        else{
            auto it = find(begin(arr),end(arr),key);
            if(it!=end(arr))arr.erase(it);
        }
    }
    bool contains(int key) {
        if(arr.empty())
            return false;
        return find(begin(arr),end(arr),key)!=end(arr);
    }
};
```

[Original post](https://leetcode.com/problems/design-hashset/discuss/768548/C-%2B%2B-Two-Easy-Solution-or-Clean-Code)