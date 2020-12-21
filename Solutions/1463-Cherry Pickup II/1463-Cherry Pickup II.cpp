//Fourth fastest
//https://leetcode.com/problems/cherry-pickup-ii/discuss/977803/C%2B%2B-28ms-faster-than-99.39-or-iterative-or-2d-DP
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int R=grid.size(),C=(R>0)?grid[0].size():0;
        int dp[C][C];
        memset(dp,-1,sizeof(dp));
        dp[0][C-1]=grid[0][0]+((0==C-1?0:grid[0][C-1]));
        for(int r=1;r<R;++r){
            int dp2[C][C];
            memset(dp2,-1,sizeof(dp2));
            for(int c1=0;c1<C;++c1){
				for(int c2=c1;c2<C;++c2){
                    int temp=grid[r][c1]+((c1==c2)?0:grid[r][c2]);
                    for(int nc1=c1-1;nc1<=c1+1;++nc1){
                        for(int nc2=c2-1;nc2<=c2+1;++nc2){
                            if(nc1>=0 && nc1<C && nc2>=0 && nc2<C && dp[nc1][nc2]>=0)
                                dp2[c1][c2]=max(dp2[c1][c2],temp+dp[nc1][nc2]);
                        }
                    }
                }
            }
            memcpy(dp,dp2,sizeof(dp2));
        }
        return *max_element(&dp[0][0],&dp[0][0]+C*C);
    }
};

//Third fastest
/**         (buri nazar wale tera muh kala \U0001f611)
 *
 * @Author   : rudraksh
 * @Created  : Friday, December 11th 2020, 10:32:09 pm
 * @Email    : rudrakshk@iitbhilai.ac.in
 *
 *   “Think twice, code once.”
 */


#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int,int> PI;
typedef pair<ll,ll> PL;
typedef map<int,int> MI;
typedef pair<int,PI> PIP;

#define ar              array
#define pb              push_back
#define pf              push_front
#define popb            pop_back
#define popf            pop_front
#define eb              emplace_back
#define F               first
#define S               second
#define repa(i,a,n)     for(int i=a;i<n;i++)
#define rep(i,n)        for(int i=0;i<n;i++)
#define pera(i,a,n)     for(int i=a;i>=n;i--)
#define per(i,n)        for(int i=n;i>=0;i--)
#define all(x)          (x).begin(),(x).end()
#define loop(it,x)      for(auto it=x.begin();it!=x.end();it++)
#define MS0(x)          memset((x), 0, sizeof((x)))
#define MS1(x)          memset((x), -1, sizeof((x)))
#define CP(dst,src)     memcpy(dst, src, sizeof(src))
#define SZ(x)           ((ll)(x).size())
#define watch(x)        cout << (#x) << " is " << (x) << endl
#define TIME            cerr << "\nTime elapsed: " << setprecision(5) << 1000.0*clock()/CLOCKS_PER_SEC << "ms\n";

const ll mod=1e9+7;
const double pi=acos(-1);

template<typename T,typename T1>T max(T &a,T1 &b){if(b>a) return b;else return a;}
template<typename T,typename T1>T min(T &a,T1 &b){if(b<a) return b;else return a;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

void print() { cout<<'\n'; }
// void print() { cout<<endl; }

template <typename T, typename... Params>
void print(const T& var1, const Params&... var2)
{
    cout<<var1<<' ';
    print(var2...);
}

ll power(ll a,ll b)
{
    ll res=1;
    a %= mod;
    if(a==0) return 0;
    while(b>0)
    {
        if(b&1) res = (res*a) % mod;
        b = b>>1;
        a = (a*a) % mod;
    }
    return res;
}


/************* I started out with nothing, and I still have most of it. ****************/

// class Solution {
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         int m = (int)grid.size(), n = (grid[0].size());
//         vector<vector<int>> prev_dp(n, vector<int>(n));
//         for (int row = 0; row < m; row++) {
//             vector<vector<int>> current_dp(n, vector<int>(n));
//             for (int c1 = 0; c1 < min(n, row + 1); c1++) {
//                 for (int c2 = max(0, n - 1 - row); c2 < n; c2++) {
//                     int prev_max = 0;
//                     for (int offset1 = max(0, c1 - 1); offset1 <= min(n - 1, c1 + 1); offset1++) {
//                         for (int offset2 = max(0, c2 - 1); offset2 <= min(n - 1, c2 + 1); offset2++) {
//                                 prev_max = max(prev_max, prev_dp[offset1][offset2]);
//                         }
//                     }
//                     if (c1 == c2)
//                         current_dp[c1][c2] = prev_max + grid[row][c1];
//                     else
//                         current_dp[c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
//                 }
//             }
//             prev_dp = current_dp;
//         }
//         int res = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 res = max(res, prev_dp[i][j]);    
//             }
//         }
//         return res;
//     }
// };

int n;
int dp[70][70];

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        MS0(dp);
        rep(i,n)
        {
            int newdp[70][70]{};
            rep(col1,min(m, i + 1))
            {
                repa(col2, max(0, m - 1 - i),m)
                {
                    int candy = grid[i][col1] + grid[i][col2];
                    if(col1 == col2) candy -= grid[i][col1];
                    amax(newdp[col1][col2], dp[col1][col2] + candy);
                    if(col1) amax(newdp[col1][col2], dp[col1-1][col2] + candy);
                    if(col2) amax(newdp[col1][col2], dp[col1][col2-1] + candy);
                    if(col1 < m-1) amax(newdp[col1][col2], dp[col1+1][col2] + candy);
                    if(col2 < m-1) amax(newdp[col1][col2], dp[col1][col2+1] + candy);
                    if(col1 && col2 < m-1) amax(newdp[col1][col2], dp[col1-1][col2+1] + candy);
                    if(col2 && col1 < m-1) amax(newdp[col1][col2], dp[col1+1][col2-1] + candy);
                    if(col1 && col2) amax(newdp[col1][col2], dp[col1-1][col2-1] + candy);
                    if(col1 < m-1 && col2 < m-1) amax(newdp[col1][col2], dp[col1+1][col2+1] + candy);
                }
            }
            CP(dp, newdp);
        }
        rep(col1,m) rep(col2,m) amax(ans, dp[col1][col2]);
        return ans;
        // return (ans + grid[0][0] + grid[0][m-1]);
    }
};

//Second fastest
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        int dp[n+5][m+5][m+5];
        int i,j,k;
        for(k=0;k<n;k++)
        for(i=0;i<m;i++)
            for(j=0;j<m;j++)
                dp[k][i][j]=0;
        dp[0][0][m-1]=grid[0][0]+grid[0][m-1];
        
        for(i=1;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                for(k=0;k<m;k++)
                {
                    if(j>i)
                        continue;
                    if(k<(m-1-i))
                        continue;
                    if(j>0 and k>0)
                        dp[i][j][k]=max(dp[i-1][j-1][k-1],dp[i][j][k]);
                    if(j>0 and k<m-1)
                        dp[i][j][k]=max(dp[i-1][j-1][k+1],dp[i][j][k]);
                    if(j>0)
                        dp[i][j][k]=max(dp[i-1][j-1][k],dp[i][j][k]);
                    if(j+1<m)
                        dp[i][j][k]=max(dp[i-1][j+1][k],dp[i][j][k]);
                    if(j+1<m and k<m-1)
                        dp[i][j][k]=max(dp[i-1][j+1][k+1],dp[i][j][k]);
                     if(j+1<m and k>0)
                        dp[i][j][k]=max(dp[i-1][j+1][k-1],dp[i][j][k]);
                    dp[i][j][k]=max(dp[i-1][j][k],dp[i][j][k]);
                    if( k<m-1)
                        dp[i][j][k]=max(dp[i-1][j][k+1],dp[i][j][k]);
                     if(k>0)
                        dp[i][j][k]=max(dp[i-1][j][k-1],dp[i][j][k]);
                    if(j==k)
                        dp[i][j][k]+=grid[i][j];
                    else
                        dp[i][j][k]+=grid[i][j]+grid[i][k];
                    
                }
            }
        }
        int max1=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                max1=max(dp[n-1][i][j],max1);
                // cout<<dp[n-5][i][j]<<" ";
            }
            // cout<<"\n";
        }
        return max1;
        
    }
};

//Fastest
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
             int M = grid.size();
        int N = grid[0].size();
        int dp[70][70][70] = {0};
        dp[0][0][N-1] = grid[0][0] + grid[0][N-1];
        for(int i = 1; i < M; ++i)
        for(int j1 = 0; j1 < min(N,i+1); ++j1)
        for(int j2 = max(0,N-i-1); j2 < N; ++j2)
        {
            int cur = (j1==j2) ? grid[i][j1] : grid[i][j1]+grid[i][j2];
            int tmp_max = dp[i-1][j1][j2];
            if(j2 > 0)
            if(tmp_max < dp[i-1][j1][j2-1])
                tmp_max = dp[i-1][j1][j2-1];
            if(j2 < N-1)
            if(tmp_max < dp[i-1][j1][j2+1])
                tmp_max = dp[i-1][j1][j2+1];
            if(j1 > 0)
            {
                if(tmp_max < dp[i-1][j1-1][j2])
                    tmp_max = dp[i-1][j1-1][j2];
                if(j2 > 0)
                if(tmp_max < dp[i-1][j1-1][j2-1])
                    tmp_max = dp[i-1][j1-1][j2-1];
                if(j2 < N-1)
                if(tmp_max < dp[i-1][j1-1][j2+1])
                    tmp_max = dp[i-1][j1-1][j2+1];
            }
            if(j1 < N-1)
            {
                if(tmp_max < dp[i-1][j1+1][j2])
                    tmp_max = dp[i-1][j1+1][j2];
                if(j2 > 0)
                if(tmp_max < dp[i-1][j1+1][j2-1])
                    tmp_max = dp[i-1][j1+1][j2-1];
                if(j2 < N-1)
                if(tmp_max < dp[i-1][j1+1][j2+1])
                    tmp_max = dp[i-1][j1+1][j2+1];
            }
            dp[i][j1][j2] = tmp_max + cur;
        }
        int ret = 0;
        for(int j1 = 0; j1 < N; ++j1)
        for(int j2 = 0; j2 < N; ++j2)
        if(ret < dp[M-1][j1][j2])
            ret = dp[M-1][j1][j2];
        return ret;
    }
};