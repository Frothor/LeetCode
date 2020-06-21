class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        
        vector<vector<int>> ans(rows, vector<int>(cols));
        
        ans[rows-1][cols-1] = dungeon[rows-1][cols-1] > 0 ? 1 : 1 - dungeon[rows-1][cols-1];
            
        for(int i = rows-2; i >= 0; i--)
            ans[i][cols-1] = max(ans[i+1][cols-1] - dungeon[i][cols-1], 1);
        for(int j = cols-2; j >= 0; j--)
            ans[rows-1][j] = max(ans[rows-1][j+1] - dungeon[rows-1][j], 1);
        
        for(int i = rows-2; i >= 0; i--)
            for(int j = cols-2; j >=0; j--)
                ans[i][j] = max(min(ans[i+1][j], ans[i][j+1]) - dungeon[i][j], 1);
        
        return ans[0][0];
    }
};

/*
Fastest:
static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& D) {
        int m = D.size();
        if(m==0)
        {
            return 0;
        }
        int n = D[0].size();
        if(n==0)
        {
            return 0;
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                {
                    if(D[i][j]>=0)
                    {
                        D[i][j] = 1;
                    }
                    else{
                        D[i][j] = (-1*D[i][j]) + 1;
                    }
                    continue;
                }
                if(i==m-1)
                {
                    if(D[i][j]>=0){
                    D[i][j]= max(1,D[i][j+1]-D[i][j]);
                    }else{
                      D[i][j]= (-1*D[i][j]) + D[i][j+1];
                    }
                    continue;
                }
                 if(j==n-1)
                {
                   if(D[i][j]>=0){
                    D[i][j]= max(1,D[i+1][j]-D[i][j]);
                    }else{
                       D[i][j]= (-1*D[i][j]) + D[i+1][j];
                    }
                    continue;
                }
                if(D[i][j]>=0)
                {
                    D[i][j]= min(max(1,D[i][j+1]-D[i][j]),max(1,D[i+1][j]-D[i][j]));
                }
                else{
                 D[i][j]= (-1*D[i][j]) + min(D[i+1][j],D[i][j+1]);   
                }
                
                
            }
        }
        return D[0][0];
    }
};
*/