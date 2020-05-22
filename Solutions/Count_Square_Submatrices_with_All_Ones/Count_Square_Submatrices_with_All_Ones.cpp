class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp((n), vector<int> (m));
        int count = 0;
        
        for(int i=0; i<m; i++){
            dp[0][i] = matrix[0][i];
            count += dp[0][i];
        }
        
        for(int i=1; i<n; i++){
            dp[i][0] = matrix[i][0];
            count += dp[i][0];
        }
        
        for(int i =1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 1)
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                count += dp[i][j];
            }
        }
        
        return count;
    }
};

/*
Most common:
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        const size_t rowCount = matrix.size();
        const size_t colCount = matrix[0].size();
        
        int count = 0;
        vector<size_t> prevRow(colCount, 0);
        for (size_t c = 0; c < colCount; ++c) {
            if (matrix[0][c] == 0) continue;
            
            prevRow[c] = 1;
            ++count;
        }
        
        vector<size_t> curRow(colCount);
        for (size_t r = 1; r < rowCount; ++r) {
            curRow[0] = matrix[r][0] == 1;
            count += curRow[0];
            
            for (size_t c = 1; c < colCount; ++c) {
                if (matrix[r][c] == 0) {
                    curRow[c] = 0;
                } else {
                    curRow[c] = 1 + std::min(curRow[c - 1],
                                                std::min(prevRow[c - 1], 
                                                         prevRow[c]));
                }
                
                count += curRow[c];
            }
            
            prevRow.swap(curRow);
        }        
        
        return count;
    }
};

Fastest:
class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);  std::cin.tie(nullptr); std::cout.tie(nullptr);
    }
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0; 
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(i && j && matrix[i][j])
                    matrix[i][j] += min(min(matrix[i][j-1], matrix[i-1][j]), matrix[i-1][j-1]);
                res += matrix[i][j]; //本身可以组成1个square
            }
        }
        return res;
    }
};
*/