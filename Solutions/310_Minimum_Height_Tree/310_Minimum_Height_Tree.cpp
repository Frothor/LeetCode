//Topologiacal sort BFS
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<int> degree(n, 0);
        
        vector<vector<int>> adj(n);
        
        if(n <= 0) return {};
        if(n == 1) return {0};
        
        for(auto e:edges) {
            degree[e[0]]++;
            degree[e[1]]++;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        for(int i=0;i<degree.size();i++) {
            if(degree[i] == 1) q.push(i);
        }
        
        while(n>2) {
            int size = q.size();
            n -= size;
            while(size--) {
                int v = q.front();
                q.pop();
                for(auto x:adj[v]) {
                    degree[x]--;
                    if(degree[x] == 1) {
                        q.push(x);
                    }
                }
            }
        }
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

//BFS
class Solution { // BFS
public://Time/Space: O(N); O(N)
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n < 2) return {0};
        vector<vector<int>> g(n);
        vector<int> indegrees(n, 0);
        for(const auto& e: edges){
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
            indegrees[e[0]]++;
            indegrees[e[1]]++;
        }        
     
        vector<int> q, level;
        for(int i = 0; i < n; i++)
            if(indegrees[i] == 1) q.emplace_back(i);
        for(int step = 0; !q.empty(); ++step){            
            for(int sz = q.size(); sz > 0; sz--){                
                auto cur = q[sz - 1];
                for(const auto& next: g[cur])
                    if(--indegrees[next] == 1)
                        level.emplace_back(next);
            }            
            if(level.empty()) break;
            swap(q, level);level.clear();
        }
        return q;
    }
};

//Fastest
class Solution {
public:
    const int shift = 15; // max size of n is 20,000, so we can use 32768 to pack info above edge info
    const int cntr = 1 << shift;
    const int mask = cntr - 1;

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) return {0};
        //if (n==2) return {0,1};
        
        edges.push_back(vector<int>{0,0});
        const int k2 = n - 1;
        for (int k=0; k < k2; k++) {
            int i = edges[k][0] & mask;
            int j = edges[k][1] & mask;
            edges[i][0] += cntr; // counts
            edges[i][1] += (j << shift); // sums

            edges[j][0] += cntr;
            edges[j][1] += (i << shift);
        }

        deque<int> leaves;
        const int m = n;
        for (int i=0; i < m; i++) {
            edges[i][0] = edges[i][0] >> shift;
            edges[i][1] = edges[i][1] >> shift;
            if (edges[i][0]==1) leaves.push_back(i);
        }
        
        while (n > 2) {
            const int leaves_size = leaves.size();
            for (int i=0; i < leaves_size; i++) {
                const int leaf = leaves.front(); leaves.pop_front();
                const int conn = edges[leaf][1];
                edges[conn][1] -= leaf;
                if (--edges[conn][0]==1) leaves.push_back(conn);
            }
            n -= leaves_size;
        }

        return vector<int>(leaves.begin(), leaves.end());
    }
};