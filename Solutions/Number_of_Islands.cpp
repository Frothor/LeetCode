/*
LeetCode Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1


Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/


class Solution {
    
void mark(vector<vector<char>>& m, int y, int x, int r, int c){
    if(y < 0 || y >= r || x < 0 || x >= c || m[y][x] != '1')
        return;
    
    m[y][x] = '2';

    mark(m, y - 1, x, r, c);
    mark(m, y, x + 1, r, c);
    mark(m, y + 1, x, r, c);
    mark(m, y, x - 1, r, c);
}
    
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int rows = grid.size();
        if(rows == 0)
            return 0;
        
        int cols = grid[0].size();
        
        int count = 0;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(grid[i][j] == '1'){
                    mark(grid, i, j, rows, cols);
                    count++;   
                }
            }            
        }
        
        return count;
    }
};