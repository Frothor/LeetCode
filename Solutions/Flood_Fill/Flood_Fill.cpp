class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int rows, int cols, int source){
        if(sr<0 || sr>=rows || sc<0 || sc>=cols)
            return;
        else if(image[sr][sc]!=source)
            return;
        
        image[sr][sc]=newColor;
        
        dfs(image, sr-1,sc,newColor,rows,cols,source);
        dfs(image, sr+1,sc,newColor,rows,cols,source);
        dfs(image, sr,sc-1,newColor,rows,cols,source);
        dfs(image, sr,sc+1,newColor,rows,cols,source);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc])
            return image;
        int rows = image.size();
        int cols = image[0].size();
        int source = image[sr][sc];
        dfs(image, sr, sc, newColor, rows, cols, source);
        return image;
    }
};


/*
Fastest:
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldCol = image[sr][sc];
        if (oldCol != newColor)
            fillCol(image, sr, sc, newColor, oldCol);
        return image;
    }
    
    void fillCol(vector<vector<int>>& image, int i, int j, int newCol, int oldCol) {
        if (i < 0 || i >= image.size() ||
            j < 0 || j >= image[0].size() ||
            image[i][j] != oldCol
           )
            return;
        image[i][j] = newCol;
        fillCol(image, i+1, j, newCol, oldCol);
        fillCol(image, i-1, j, newCol, oldCol);
        fillCol(image, i, j+1, newCol, oldCol);
        fillCol(image, i, j-1, newCol, oldCol);
        return;
    }
};

Second fastest:
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(); if (m == 0) return image;
        int n = image[0].size(); if (n == 0) return image;
        int c = image[sr][sc];
        if (c != newColor)
            dfs(image, m, n, sr, sc, c, newColor);
        return image;
    }
    
private:
    void dfs(vector<vector<int>>& image, int m, int n, int x, int y, int oc, int nc) {
        if (x < 0 || x >= m || y < 0 || y >= n || image[x][y] != oc) return;
        image[x][y] = nc;
        dfs(image, m, n, x-1, y, oc, nc);
        dfs(image, m, n, x+1, y, oc, nc);
        dfs(image, m, n, x, y-1, oc, nc);
        dfs(image, m, n, x, y+1, oc, nc);
    }
};
*/