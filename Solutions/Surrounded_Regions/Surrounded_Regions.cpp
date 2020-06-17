class Solution {
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'O'){
            board[i][j] = 'A';
            dfs(board, i+1, j);
            dfs(board, i-1, j);
            dfs(board, i, j+1);
            dfs(board, i, j-1);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n<=2) return;
        
        int m = board[0].size();
        if(m<=2) return;
        
        for(int i=0; i < n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && (i == 0 || i == n-1 || j == 0 || j == m-1))
                    dfs(board, i, j);
            }
        }
        
        for(int i=0; i < n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
};

/*
Fastest:
class Solution {
public:
    void parse(vector<vector<char>>& board, int i, int j) {
        board[i][j] = '1';
        
        cout << "Parse " << i << j << endl;
        
        // left
        if (i - 1 >= 0 && board[i - 1][j] == 'O')
            parse(board, i - 1, j);
        
        cout << "Left done" << endl;
        
        //right
        if (i + 1 < board.size() && board[i + 1][j] == 'O')
            parse(board, i + 1, j);
        
        cout << "Right done" << endl;
        
        //top
        if (j - 1 >= 0 && board[i][j - 1] == 'O')
            parse(board, i, j - 1);
        
        cout << "Top done" << endl;
        
        //bottom
        if (j + 1 < board[0].size() && board[i][j + 1] == 'O')
            parse(board, i, j + 1);
        
        cout << "Bottom done" << endl;
    }
    
    void solve(vector<vector<char>>& board) {
       
        if (board.size() == 0)
            return;
        
        for (int i = 0; i < board[0].size(); i++)
            if (board[0][i] == 'O')
               parse(board, 0, i);
        
        for (int i = 0; i < board[board.size() - 1].size(); i++)
            if (board[board.size() - 1][i] == 'O')
               parse(board, board.size() - 1, i);
        
        for (int i = 0; i < board.size(); i++)
            if (board[i][0] == 'O')
                parse(board, i, 0);
        
        for (int i = 0; i < board.size(); i++)
            if (board[i][board[0].size() - 1] == 'O')
                parse(board, i, board[0].size() - 1);

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == '1')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
        
    }
};

class Solution {
public:
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        //cout << i << ":::" << j << endl;
        if (i < 0 || i >= m || j < 0 || j >= n)   return;
        if (board[i][j] == 'X' || board[i][j] == '#') return;
        
        board[i][j] = '#';
        for (int p = 0; p < dir.size(); p++) {
            dfs(board, i + dir[p][0], j + dir[p][1], m, n);
        }
        
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0 || board[0].size() == 0) return;
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0, m, n);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1, m, n);
        }
        
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') dfs(board, 0, i, m, n);
            if (board[m - 1][i] == 'O') dfs(board, m - 1, i, m, n);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' ) board[i][j] = 'X';
                else if (board[i][j] == '#')    board[i][j] = 'O';
            }
        }
    }
};
*/