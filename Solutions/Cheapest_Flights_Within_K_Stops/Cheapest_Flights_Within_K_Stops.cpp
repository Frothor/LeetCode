class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
         
        unordered_map<int, vector<pair<int,int>>> g;

        for (const auto& e : flights)
            g[e[0]].emplace_back(e[1], e[2]);
        
        int ans = INT_MAX;

        queue<pair<int,int>> q;

        q.push({src, 0});

        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int curr = q.front().first;

                int cost = q.front().second;
                
                q.pop();

                if (curr == dst) 
                    ans = min(ans, cost);
                
                for (const auto& p : g[curr]) {
                    if (cost + p.second > ans) continue; // Important: prunning          
                    q.push({p.first, cost + p.second});
                }
            }
            if (steps++ > K) break;
        }
        
        return ans == INT_MAX ? - 1 : ans;
    }
};


/*
Most common:
/DFS
#if 0
class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    g_.clear();  
    for (const auto& e : flights)
      g_[e[0]].emplace_back(e[1], e[2]);
    vector<int> visited(n, 0);
    visited[src] = 1;
    int ans = INT_MAX;
    dfs(src, dst, K + 1, 0, visited, ans);
    return ans == INT_MAX ? - 1 : ans;
  }
private:
  unordered_map<int, vector<pair<int,int>>> g_;
  
  void dfs(int src, int dst, int k, int cost, vector<int>& visited, int& ans) {
    if (src == dst) {
      ans = cost;
      return;
    }
    
    if (k == 0) return;    
    
    for (const auto& p : g_[src]) {
      if (visited[p.first]) continue; // do not visit the same city twice.
      if (cost + p.second > ans) continue; // IMPORTANT!!! prunning 
      visited[p.first] = 1;
      dfs(p.first, dst, k - 1, cost + p.second, visited, ans);
      visited[p.first] = 0;
    }
  }
};
#endif



//BFS

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    unordered_map<int, vector<pair<int,int>>> g;
    for (const auto& e : flights)
      g[e[0]].emplace_back(e[1], e[2]);
    
    int ans = INT_MAX;
    queue<pair<int,int>> q;
    q.push({src, 0});
    int steps = 0;
    
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int curr = q.front().first;
        int cost = q.front().second;
        q.pop();
        if (curr == dst) 
          ans = min(ans, cost);
        for (const auto& p : g[curr]) {
          if (cost + p.second > ans) continue; // Important: prunning          
          q.push({p.first, cost + p.second});
        }
      }
      if (steps++ > K) break;
    }
    
    return ans == INT_MAX ? - 1 : ans;
  }
};
////////////////

Fastest:
class Solution {
public:
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {        unordered_map<int, vector<pair<int, int>>> graph;
        for(auto e: flights) graph[e[0]].push_back({e[1], e[2]});
        vector<int> prices(n, -1);
        queue<pair<int, int>> q; q.push({src, 0});
        ++K;
        while(!q.empty()) {
            if(!K) break;
            int len = q.size();
            for(int i = 0; i < len; i++) {
                auto cur = q.front(); q.pop();
                for(auto e: graph[cur.first]) {
                    int price = cur.second + e.second; 
                    if(prices[e.first] == -1 || price < prices[e.first]) {
                        prices[e.first] = price;
                        q.push({e.first, price});
                    }
                }
            }
            K--;
        }
        return prices[dst];
                                                                                         
       
        
    }
};
////////////////

DFS:
 int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

    g_.clear();  

    for (const auto& e : flights)

      g_[e[0]].emplace_back(e[1], e[2]);

    vector<int> visited(n, 0);

    visited[src] = 1;

    int ans = INT_MAX;

    dfs(src, dst, K + 1, 0, visited, ans);

    return ans == INT_MAX ? - 1 : ans;

  }

private:

  unordered_map<int, vector<pair<int,int>>> g_;

  

  void dfs(int src, int dst, int k, int cost, vector<int>& visited, int& ans) {

    if (src == dst) {

      ans = cost;

      return;

    }

    

    if (k == 0) return;    

    

    for (const auto& p : g_[src]) {

      if (visited[p.first]) continue; // do not visit the same city twice.

      if (cost + p.second > ans) continue; // IMPORTANT!!! prunning 

      visited[p.first] = 1;

      dfs(p.first, dst, k - 1, cost + p.second, visited, ans);

      visited[p.first] = 0;

    }

  }

DP - Bellman-Ford algorithm
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

    constexpr int kInfCost = 1e9;

    vector<vector<int>> dp(K + 2, vector<int>(n, kInfCost));

    dp[0][src] = 0;

    

    for (int i = 1; i <= K + 1; ++i) {

      dp[i][src] = 0;

      for (const auto& p : flights)

          dp[i][p[1]] = min(dp[i][p[1]], dp[i-1][p[0]] + p[2]);    

    }

    

    return dp[K + 1][dst] >= kInfCost ? -1 : dp[K + 1][dst];

  }

*/