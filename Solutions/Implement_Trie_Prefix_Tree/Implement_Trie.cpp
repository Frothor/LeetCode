class Trie {
    Trie* children[26];
    bool isEnd;
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        for(int i=0; i<26; i++){
            children[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr = this;
        for(char c: word){
            if(!(curr->children[c-'a']))
                curr->children[c-'a'] = new Trie;
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* curr = this;
        for(char c: word){
            if(!(curr->children[c-'a']))
                return false;
            curr = curr->children[c-'a'];
        }
        return curr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* curr = this;
        for(char c: prefix){
            if(!(curr->children[c-'a']))
                return false;    
            curr = curr->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/*
Fastest:

class Trie {
    int R = 26;
    vector<Trie*> children;
    bool isEnd;
public:
    Trie() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        this->children = vector<Trie*>(R, nullptr);
        isEnd = 0;
    }
    
    void insert(string word) {
        Trie* curr = this;
        int n = word.size(), idx;
        for(int i = 0;i<n;i++) {
            idx = word[i] - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new Trie();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        int n = word.size(), idx;
        for(int i = 0;i<n;i++) {
            idx = word[i] - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return (curr->isEnd);
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        int n = prefix.size(), idx;
        for(int i = 0;i<n;i++) {
            idx = prefix[i] - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};

Most common:
class Trie {
public:
    Trie* next[26];
    bool isWord=false;
    Trie() {
        memset(next, 0, sizeof next);
    }
    
    void insert(string word) {
        Trie* t=this;
        for(char c: word){
            int i=c-'a';
            if(t->next[i]==0) t->next[i]=new Trie();
            t=t->next[i];
        }
        t->isWord=true;
    }
    
    bool search(string word) {
        Trie* t=this;
        for(char c: word){
            int i=c-'a';
            if(t->next[i]==0) return false;
            t=t->next[i];
        }
        return t->isWord;        
    }
    
    bool startsWith(string prefix) {
        Trie* t=this;
        for(char c: prefix){
            int i=c-'a';
            if(t->next[i]==0) return false;
            t=t->next[i];
        }
        return true;        
    }
};
*/