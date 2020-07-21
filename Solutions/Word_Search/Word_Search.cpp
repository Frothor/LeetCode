/*
Approach
1. Search the board for the first letter in the word.
2. When we encouter that letter set index to 0 perform DFS. (index - 0 = first letter of word)
    1. Use a visited array to mark the letters we visited to avoid duplicates
    2. increment the index to look for the next letter in the word.
    3. If we have reached the end of the word return true.
    4. Go to the adjacent 4 cells and see if the next letter is true.
    5. Each of the adjacent elements will also perform the same process
    6. If any of the adjacent cell returns true return true.
    7. If none of the neighbours returned true. mark this node as unvisited and return false
3. If any of the starting letter DFS searches return true the return true
4. If word was not found return false

NOTE:

1. Checkbounds function
This function checks if the given indices are valid
2. To iterate adjacent cells we use vector - dirs {0,1},{0,-1},{1,0},{-1,0}
These four values will be added to the current index to get new indices.
*/

//DFS
class Solution {
public:
    bool checkBounds(int i,int j,int r,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
    
    bool dfs(vector<vector<char>>& board,vector<vector<int>>& visited,string& word,int i,int j,int p,int r,int c){
        if(visited[i][j]) return false;
        visited[i][j] = 1;
        p++;
        if(p == word.length()) return true;
        vector<pair<int,int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto dir : dirs){
            int ii = i+dir.first, jj=j+dir.second;
            if(checkBounds(ii,jj,r,c) && board[ii][jj] == word[p] && dfs(board,visited,word,ii,jj,p,r,c)){
                return true;
            }
        }
        visited[i][j] = 0;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        char s = word[0];
        vector<vector<int>>visited(r,vector<int>(c));
         for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j] == s && dfs(board,visited,word,i,j,0,r,c)) return true;
            }
        }
        return false;
    }
};

/*
Most common:
class Solution {
public:
     bool exist(vector<vector<char>>& board, string word) 
    {
        if(board.size() == 0) return false;
        
        for(int i=0 ; i<board.size() ; i++)
        {
            for(int j=0 ; j < board[i].size() ; j++)
            {
                if(board[i][j] == word[0])
                {
                    bool found =  dfs(i,j,board,word, 0);
                    if(found) 
                        return true;
                }
            }
        }       
        
        return false;        
        
    }
    
    
    bool dfs(int i , int j , vector<vector<char>>& board, string &word , int pos)
    {
        int n = board.size() , m = board[0].size();
        
        if(pos == word.length()) return true;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j] != word[pos]) return false;
        
        char prev_char = board[i][j];
        
        board[i][j] = '*';    // using this approach to save up on the space for a visited 2-D array -> mark the current element with some non-usable value , eg : *
        
		// Move in all 4 possible directions
        bool res =    dfs(i+1, j , board , word , pos+1)
                   || dfs(i , j+1 , board , word , pos +1 )
                   || dfs(i-1 , j , board, word , pos+ 1)
                   || dfs(i , j-1 , board , word , pos+1);
        
        board[i][j] = prev_char; // backtracking part -> remove the marker at this step , i.e, before returning the  result.
        
        return res;
    }
    
};


Fastest:
class Solution {
    bool make(vector<vector<char>>& board, const string &word, int index, int i, int j, int n, int m, int w) {
        if(index == w) return true;
        if(i < 0 || j < 0 || i > n-1 || j > m-1 || board[i][j] != word[index]) return false;
        char store = board[i][j];
        board[i][j] = ' ';
        bool ispossible = make(board, word, index + 1, i+1, j, n, m, w) || make(board, word, index + 1, i-1, j, n, m, w) || make (board, word, index + 1, i, j+1, n, m, w) || make(board, word, index + 1, i, j-1, n, m, w); 
        board[i][j] = store;
        return ispossible;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n = board.size();
        int m = board[0].size();
        int ww = word.length();
        int w = 0;
        unordered_multiset<char> tab;
        for(char c : word) tab.insert(c);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(make(board, word, 0, i, j, n, m, word.length())) {
                    return true;
                }
            }
        }
        return false;
    }
};

[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"SEE"

[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCCED"

[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCB"

*/