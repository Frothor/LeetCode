class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        // insert reversed word into trie and keep track of the length of longest word
        for (auto& word: words) 
        {
            trie.insert_reversed(word);
            if (word.length() > longest_word)
                longest_word = word.length();
        }
    }
    
    bool query(char letter) {
        queries.insert(queries.begin(), letter);
        // keep in queries only the "longest word" last queries, because we don't need the other ones anymore
        if (queries.size() > longest_word)
            queries.pop_back();
        Trie* cur = &trie;
        for (auto it = queries.begin(); it!=queries.end();++it)
        {
            if (cur->is_leaf) return true;
            if (cur->children[*it -'a'] == NULL) return false;
            cur = cur->children[*it-'a'];
        }
        return cur->is_leaf;
    }
private:
    
    class Trie {
    public:
        Trie() {
            this->is_leaf = false;
            for(int i=0;i<26;i++)
                this->children[i] = NULL;
        }
        
        void insert_reversed(string word) {
            reverse(word.begin(), word.end());
            Trie* root = this;
            for(int i=0;i<word.length();i++)
            {
                int index = word[i] - 'a';
                if (root->children[index] == NULL)
                    root->children[index] = new Trie();
                root = root->children[index];
            }
            root->is_leaf = true;
        }
        
    bool is_leaf;
    Trie* children[26];
    };
    
    Trie trie;
    vector<char> queries;
    int longest_word=0;
};

//Most common
class StreamChecker {
public:
    struct TrieNode
    {
        TrieNode* children[26];
        string word;
    };

    TrieNode* root = NULL;
    string curr_word = "";
    
    void insertNode(TrieNode* root, string word)
    {
        auto temp = root;

        for (int i=word.size()-1; i>=0 ; i--)
        {
            int index = word[i] - 'a';
            if (temp->children[index] == NULL)
                temp->children[index] = new TrieNode();

            temp = temp->children[index];
        }

        temp->word = word;
    }

    bool searchTrie(TrieNode* root, string& word)
    {
        auto temp = root;

        for (int i=word.size()-1; i>=0; i--)
        {
            int index = word[i] - 'a';

            
            if (temp->children[index] == NULL)
                return false;
            
            temp = temp->children[index];
            
            if (temp != NULL && temp->word != "")
                return true;
        }

        return false;
    }

    
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        
        for (auto& word: words)
        {
            insertNode(root, word);
        }
    }
    
    bool query(char letter) {
        curr_word += letter;
        
        return searchTrie(root, curr_word);   
    }
};

//Fastest
static const auto magic = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

typedef struct TrieNode {
    bool isword;
    int child[26];
} tn;

class StreamChecker {
public:
    int num_nodes = 0;  // 0 is root
    tn nodes[29000];
    
    vector<char> q;
    
    StreamChecker(vector<string>& words) {
        int n = 0, tmp;
        memset(nodes, 0, sizeof(tn) * 29000);
        
        for(const auto& w: words) {
            for(int i = w.length() - 1; i >= 0; --i) {
                tmp = w[i] - 'a';
                if(nodes[n].child[tmp] == 0) {
                    nodes[n].child[tmp] = ++num_nodes;    
                }
                n = nodes[n].child[tmp];
            }    
            nodes[n].isword = true;
            n = 0;
        }        
    }
    
    bool query(char letter) {
        q.push_back(letter);
        int p = 0;
        for (int i = int(q.size()) - 1; i >= 0; --i) {
            int ci = q[i] - 'a';
            if (nodes[p].child[ci] == 0) return false;
            p = nodes[p].child[ci];
            if (nodes[p].isword) return true;
        }
        return false;
    }
};