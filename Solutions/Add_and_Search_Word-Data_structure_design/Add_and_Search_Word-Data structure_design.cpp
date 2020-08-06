class TrieNode{
    public:
        vector<TrieNode*> next;
        bool isWord = false;
        TrieNode(){
            next.resize(26, NULL);
        }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* current = root;
        for(char ch:word){
            if(!current->next[ch - 'a']){
                current->next[ch - 'a'] = new TrieNode();
            }
            current = current->next[ch - 'a'];
        }
        current->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word, root);
    }
private:
    
    bool searchHelper(string word, TrieNode* current) {
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(ch != '.'){
                if(!current->next[ch - 'a']) 
                    return false;
                current = current->next[ch - 'a'];
            }
            else{
                for(int j = 0; j < 26; j++){
                    if(current->next[j] && searchHelper(word.substr(i + 1), current->next[j])){
                        return true;
                    }
                }
                return false;
            }
        }
        return current->isWord;
    }
};

//Most Common
class TrieNode {
public:
    bool word;
    TrieNode* children[26];
    TrieNode() {
        word = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node -> children[c - 'a']) {
                node -> children[c - 'a'] = new TrieNode();
            }
            node = node -> children[c - 'a'];
        }
        node -> word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word.c_str(), root);
    }
private:
    TrieNode* root = new TrieNode();
    
    bool search(const char* word, TrieNode* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node -> children[word[i] - 'a'];
            } else {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> children[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node -> word;
    }
};

//Fastest
struct node{
    char c;
    
    node *first;
    node *next;
    
    bool flag;
    
    node(char c) : c(c), first(NULL), next(NULL), flag(false){};
};

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();


class WordDictionary {
public:
    /** Initialize your data structure here. */
    node *root;
    
    WordDictionary() {
        root = new node('0');        
    }
    
    void create(string &s, int index, node* from){
        
        if(index == s.size()){
            from->flag = true;
            return;
        }
        
        char c = s[index];
             
        node *tmp, *pre;
        
        bool find;
        
        if(from->first){
            tmp = from->first;
            
            find = false;
            
            while(tmp){
                if(tmp->c == c){
                    find = true;
                    break;
                }
                pre = tmp;
                tmp = tmp->next;
            }
            
            if(!find){
                pre->next = new node(c);
                tmp = pre->next;           
            }         
        }else{
            from->first = new node(c);
            tmp = from->first;
        }
        
        create(s, index + 1, tmp);
    }
    
    bool scan(string &s, int index, node *from){
    
        if(!from) return false;
        
        char c = s[index];

        node *tmp;
        
        bool find = false;
        
        tmp = from;
        
        if(c == '.'){
            while(tmp){
                if(index == s.size() - 1)
                    return tmp->flag;
                else{
                    if(scan(s, index + 1, tmp->first)){
                        return true;
                    }
                }
                tmp = tmp->next;
            }    
        }else{       
            while(tmp){
                if(tmp->c == c){
                    if(index == s.size() - 1)
                        return tmp->flag;
                    else
                        return scan(s, index + 1, tmp->first);
                }
                tmp = tmp->next;
            }        
        }
        
        return false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        create(word, 0, root);  
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return scan(word, 0, root->first);    
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */