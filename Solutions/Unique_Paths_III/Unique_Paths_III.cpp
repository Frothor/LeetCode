class Solution
{
public:
    int x, y, xLen, yLen, totalZeros = 0, res = 0, cell;
    void dfs(vector<vector<int>> &grid, int x, int y)
    {
        // exit condition: out of bonds
        if (x < 0 || y < 0 || x == xLen || y == yLen)
            return;
        cell = grid[y][x];
        if (cell)
        {
            // increasing res if we reached the goal and touched all available cell
            res += cell == 2 && !totalZeros;
            return;
        }
        // marking cell as visited
        grid[y][x] = -1;
        totalZeros--;
        // exploring north, east, south, west
        dfs(grid, x, y - 1);
        dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x - 1, y);
        // backtracking cell as visitable
        grid[y][x] = 0;
        totalZeros++;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        // setting class variable right
        yLen = grid.size();
        xLen = grid[0].size();
        for (int _y = 0; _y < yLen; _y++)
        {
            for (int _x = 0; _x < xLen; _x++)
            {
                cell = grid[_y][_x];
                // finding the starting point
                if (cell == 1)
                {
                    x = _x;
                    y = _y;
                }
                // increasing countZeros for each cell == 0
                totalZeros += !cell;
            }
        }
        // exploring north, east, south, west of the starting point
        dfs(grid, x, y - 1);
        dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x - 1, y);
        return res;
    }
};

//Fastest
class Solution
{
public:
    int helper_uniquePathsIII(vector<vector<int>> &grid, int si, int sj, int m, int n, int count)
    {
        if (si < 0 || si >= m || sj < 0 || sj >= n || grid[si][sj] == -1)
            return 0;
        if (grid[si][sj] == 2)
        {
            return count == 0;
        }
        grid[si][sj] = -1;
        int path = helper_uniquePathsIII(grid, si + 1, sj, m, n, count - 1) + helper_uniquePathsIII(grid, si - 1, sj, m, n, count - 1) +
                   helper_uniquePathsIII(grid, si, sj - 1, m, n, count - 1) + helper_uniquePathsIII(grid, si, sj + 1, m, n, count - 1);
        grid[si][sj] = 0;
        return path;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int res = 0, i = 0, j = 0, count = 1, si = -1, sj = -1;
        int m = grid.size(), n = grid[0].size();
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    count++;
                }
                if (grid[i][j] == 1)
                {
                    si = i;
                    sj = j;
                }
            }
        }
        res = helper_uniquePathsIII(grid, si, sj, m, n, count);
        return res;
    }
};