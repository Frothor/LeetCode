//Fastest
//https://leetcode.com/problems/spiral-matrix-ii/discuss/963514/C%2B%2B-Simulation%3A-self-explained-without-comment
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int begX = 0, endX = n - 1;
        int begY = 0, endY = n - 1;
        int counter = 0;
        while(true){
            for(int j = begX; j <= endX; j++) ans[begY][j] = ++counter;
            if(++begY>endY) break;
            for(int j = begY; j <= endY; j++) ans[j][endX] = ++counter;
            if(begX>--endX) break;
            for(int j = endX; j >= begX; j--) ans[endY][j] = ++counter;
            if(begY>--endY) break;
            for(int j = endY; j >= begY; j--) ans[j][begX] = ++counter;
            if(++begX>endY) break;
        }
        return ans;
    }
};

//Another
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int r1 = 0, r2 = n - 1, c1 = 0, c2 = n - 1 ,cnt = 1;
        while(r1 < r2){
            for(int c = c1; c < c2; c++){
                res[r1][c] = cnt++;
            }
            for(int r = r1; r < r2; r++){
                res[r][c2] = cnt++;
            }
            for(int c = c2; c > c1; c--){
                res[r2][c] = cnt++;
            }
            for(int r = r2; r > r1; r--){
                res[r][c1] = cnt++;
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        if(r1 == r2){
            res[r1][c1] = cnt;
        }
        return res;
    }
};