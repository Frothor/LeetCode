class TrieNode {
public:
    vector<TrieNode*> nodes;
    const string* word;
    TrieNode(): nodes(26), word(nullptr){}
    ~TrieNode(){
        for(auto node : nodes) delete node;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root;
        //Add all the words into Trie.
        for(const string& word : words) {
            TrieNode* cur = &root;
            for(char c : word){
                auto& next = cur->nodes[c - 'a'];
                if(!next) next = new TrieNode();
                cur = next;
            }
            cur->word = &word;
        }
        
        const int n = board.size();
        const int m = board[0].size();
        vector<string> ans;
        
        function<void(int, int, TrieNode*)> walk = [&](int x, int y, TrieNode* node) {
            if(x < 0 || x == m || y < 0 || y == n || board[y][x] == '#')
                return;
            
            const char cur = board[y][x];
            TrieNode* next_node = node->nodes[cur - 'a'];
            //Prunning, only expand paths that are in the trie
            if(!next_node) return;
            
            if(next_node->word){
                ans.push_back(*next_node->word);
                next_node->word = nullptr;
            }
            
            board[y][x] = '#';
            walk(x + 1, y, next_node);
            walk(x - 1, y, next_node);
            walk(x, y + 1, next_node);
            walk(x, y - 1, next_node);
            board[y][x] = cur;
        };
        
        //Try all possible pathes
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                walk(j, i, &root);
        
        return ans;
    }
};

/*
Fastest:
struct TrieNode{
    int v;
    TrieNode* next[26];
    TrieNode(): v(0){
        memset(next, NULL, sizeof(next));
    }
};
class Solution {
public:
    

    void backtrack(int x, int y, vector<vector<char> > &board, TrieNode *node, vector<string> &ans, string &cur){
        char tmp = board[x][y];
        board[x][y] = '#';
        node = node->next[tmp-'a'];
        if(node->v > 0){
            ans.push_back(cur);
            node->v--;
        }

        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int i=0; i<4; ++i){
            int x_ = x+dir[i][0], y_ = y+dir[i][1];
            if(x_ >= 0 && x_ < board.size() && y_ >= 0 && y_ < board[0].size() && board[x_][y_] != '#' && node->next[board[x_][y_]-'a']){
                cur.push_back(board[x_][y_]);
                backtrack(x_, y_, board, node, ans, cur);
                cur.pop_back();
            }
        }
        board[x][y] = tmp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || words.empty()) return vector<string>();
        TrieNode *root = new TrieNode();
        for(auto &word: words){
            TrieNode *ptr = root;
            for(auto &c: word){
                if(!ptr->next[c-'a'])
                    ptr->next[c-'a'] = new TrieNode();
                ptr = ptr->next[c-'a'];
            }
            ptr->v++;
        }

        vector<string> ans;
        ans.reserve(words.size());
        int N = board.size(), M = board[0].size();
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(root->next[board[i][j]-'a']){
                    string cur = "";
                    cur.push_back(board[i][j]);
                    backtrack(i, j, board, root, ans, cur);
                }
            }
        }
        return ans;
    }
};

Most common:
class Solution {
private:
    class Node {
        public:
        vector<Node*> links = vector<Node*>(26);
        int isEnd = false;
        string w;
    };
    vector <string> sol;
public:
    Node* init_trie(vector<string>& words) {
        Node* root = new Node();
        for (string word : words) {
            Node* curr = root;
            for (char c : word) {
                if (!curr -> links[c - 'a']) 
                    curr -> links[c - 'a'] = new Node();
                curr = curr -> links[c - 'a'];
            }
            curr -> isEnd = true;
            curr -> w = word;
        }
        return root;
    }
    
    void helper(vector<vector<char>>& board, int i, int j, Node*& curr) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == ' '
           || !curr -> links[board[i][j] - 'a'])
            return;
        Node*& next = curr -> links[board[i][j] - 'a'];
        if (next -> isEnd) {
            sol.push_back(next -> w);
            next -> isEnd = false;
        }
        char c = board[i][j];
        board[i][j] = ' ';
        helper(board, i-1, j, next);
        helper(board, i+1, j ,next);
        helper(board, i, j-1, next);
        helper(board, i, j+1, next);
        board[i][j] = c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = init_trie(words);
        int rows = board.size();
        if (!board.size()) return {};
        int cols = board[0].size();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                helper(board,i,j,root);

        return sol;
    }
};
*/