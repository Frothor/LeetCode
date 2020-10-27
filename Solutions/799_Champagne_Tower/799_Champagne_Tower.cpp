//Second fastest
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured < 0 || query_row < 0 || query_glass < 0)
        return 0;
    vector<vector<double>> mp(query_row+1, vector<double>(query_row+1));
    mp[0][0] = poured;
    for(int i=0; i<query_row; i++){
        for(int j=0; j<=i; j++){
            if(mp[i][j] > 1){
                double rem = mp[i][j] - 1;
                mp[i+1][j] += rem/2.0;
                mp[i+1][j+1] += rem/2.0;
            }
        }
    }
    return mp[query_row][query_glass] > 1 ? 1 : mp[query_row][query_glass];
    }
};

//Fastest
class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    const int kRows = 100;
    double dp[kRows][kRows]={}; //dp[i][j]: maximal accumulated amount.   vector<vector<double>> dp(kRows, vector<double>(kRows));
    dp[0][0] = poured;
    for (int i = 0; i < kRows - 1; ++i)
      for (int j = 0; j <= i; ++j)
        if (dp[i][j] > 1) {
          dp[i + 1][j    ] += (dp[i][j] - 1) / 2.0;
          dp[i + 1][j + 1] += (dp[i][j] - 1) / 2.0;
          dp[i][j] = 1.0;
        }
    return std::min(1.0, dp[query_row][query_glass]);
  }
};

//Another fastest
#define glasses g

class Solution {
public:
    
    double min(double a,double b){
        if(a<b)
            return a;
        return b;
    }
    
    double champagneTower(int poured, int query_row, int query_glass) {
        double glasses[100][100];
        
        for(int i=0;i<=query_row;i++)
            for(int j=0;j<=query_glass;j++)
                g[i][j] = 0;
        
        g[0][0] = (double)poured;
        
        for(int i=0;i<query_row;i++){
            for(int j=0;j<=i;j++){
                double p = ((double)g[i][j] - 1)/2;
                if(p > 0){
                    g[i+1][j] += p;
                    g[i+1][j+1] += p;
                }
            }
        }
        
        return min(1.0,g[query_row][query_glass]);
    }
};