//First thought
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0) continue;
                perimeter += 4;
                if(i > 0) perimeter -= grid[i-1][j];
                if(i + 1 < n) perimeter -= grid[i+1][j];
                if(j > 0) perimeter -= grid[i][j-1];
                if(j + 1 < m) perimeter -= grid[i][j+1];
            }
        }
        
        return perimeter;
    }
};

//DFS
class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j, int& perimeter){
        grid[i][j] = 2;
        if(i == 0 || grid[i-1][j] == 0) perimeter++;
        if(i == grid.size()-1 || grid[i+1][j] == 0) perimeter++;
        if(j == 0 || grid[i][j-1] == 0) perimeter++;
        if(j == grid[0].size()-1 || grid[i][j+1] == 0) perimeter++;
        
        if(i > 0 && grid[i-1][j] == 1) dfs(grid, i-1, j, perimeter);
        if(i < grid.size()-1 && grid[i+1][j] == 1) dfs(grid, i+1, j, perimeter);
        
        if(j > 0 && grid[i][j-1] == 1) dfs(grid, i, j-1, perimeter);
        if(j < grid[0].size()-1 && grid[i][j+1] == 1) dfs(grid, i, j+1, perimeter);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)
                    dfs(grid, i, j, perimeter);   
            }
        }
        
        return perimeter;
    }
};


/*
Most common:
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0)
            return 0;
        
        int col = grid[0].size();
        int ans = 0;
        for(int r = 0; r< row ; r++){
            for(int c= 0; c< col; c++){
                if(grid[r][c] ==1){
                    dfs(r, c, grid, &ans);
                    break;
                }
            }
        }
        
        return ans;
    }
    
private:
    const int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(int r, int c, vector<vector<int>>& grid, int* ans_ptr){
        if(grid[r][c] !=1)
            return;
        
        grid[r][c] = -1;
        int count = 4;
        
        for(const auto dir: dirs){
            int new_r = r + dir[0];
            int new_c = c + dir[1];
            if(new_r <0 || new_r >= grid.size() ||
               new_c <0 || new_c >= grid[0].size()||
               grid[new_r][new_c] == 0)
                continue;
            count --;
            dfs(new_r, new_c, grid, ans_ptr);
        }
        
        *ans_ptr += count;
    }
};

Fastetst:
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(nullptr);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int cnt=0, count=0, row = grid.size(), cols = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                    cnt++;
                    if(j+1 < cols and grid[i][j+1] == 1)
                        count++;
                    if(i+1 < row and grid[i+1][j] == 1)
                        count++;
                    if(j-1 >=0 and grid[i][j-1] == 1)
                        count++;
                    if(i-1 >= 0 and grid[i-1][j] == 1)
                        count++;
                }
            }
        } 
        return 4*cnt - count;
    }
};

*/

