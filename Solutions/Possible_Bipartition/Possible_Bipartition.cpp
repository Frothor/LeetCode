class Solution {

    bool dfs(vector<vector<int>>& adj, vector<int> & groups, int v, int grp){
        if(groups[v] == -1)
            groups[v] = grp;
        else
            return groups[v] == grp;
        
        for(int n: adj[v]){
            if(!dfs(adj, groups, n, 1 - grp))
                return false;
        }
        
        return true;
    }
    
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> groups(N, -1);
        vector<vector<int>> adj(N, vector<int>());
        
        for(vector<int> &p: dislikes){
            adj[p[0] - 1].push_back(p[1] - 1);
            adj[p[1] - 1].push_back(p[0] - 1);
        }
        
        for(int i=0; i<N; i++){
            if(groups[i] == -1 && !dfs(adj, groups, i, 0))
                return false;
        }
        
        return true;
    }
};

/*
Most common:
class Solution {
public:
    // unordered_set 대신 vector 써서 약간 개선
    bool possibleBipartition(int N, vector<vector<int>>& dislikes)
    {
        vector<vector<int>> mat(N + 1);
        for (auto& v : dislikes)
        {
            mat[v[0]].push_back(v[1]);
            mat[v[1]].push_back(v[0]);
        }
        
        vector<int> visited(N + 1);
        for (int i = 1; i <= N; ++i)
        {
            if (!visited[i])
            {
                if (!isBipartition(visited, mat, i, true)) return false;
            }
        }
        return true;
        
    }
    
    static bool isBipartition(vector<int>& visited, const vector<vector<int>>& mat, int curr, bool isA)
    {
        if (isA && visited[curr] == 2) return false;
        if (!isA && visited[curr] == 1) return false;
        if (visited[curr]) return true;
        
        visited[curr] = isA ? 1 : 2;
        
        for (auto& next : mat[curr])
        {
            if (!isBipartition(visited, mat, next, !isA)) return false;
        }
        return true;
    }

    // 왜 자꾸 TLE 나오나 했더니 & 빼먹어서 mat 이 복사되고 있었음 ㅠㅠ
    // Runtime: 288 ms, faster than 47.74% of C++ online submissions for Possible Bipartition.
    // Memory Usage: 48.7 MB, less than 100.00% of C++ online submissions for Possible Bipartition.
    /*
    bool possibleBipartition(int N, vector<vector<int>>& dislikes)
    {
        vector<vector<int>> mat(N + 1);
        for (auto& v : dislikes)
        {
            mat[v[0]].push_back(v[1]);
            mat[v[1]].push_back(v[0]);
        }
        
        unordered_set<int> A, B;
        for (int i = 0; i < N; ++i)
        {
            if (!isBipartition(A, B, mat, i, !B.count(i))) return false;
        }
        return true;
        
    }
    
    static bool isBipartition(unordered_set<int>& A, unordered_set<int>& B, const vector<vector<int>>& mat, int curr, bool isA)
    {
        bool inA = A.count(curr);
        bool inB = B.count(curr);
        if (isA && inB) return false;
        if (!isA && inA) return false;
        if (inA || inB) return true;
        
        (isA ? A : B).insert(curr);
        
        for (auto& next : mat[curr])
        {
            if (!isBipartition(A, B, mat, next, !isA)) return false;
        }
        return true;
    }
    */

    
    /*
    bool possibleBipartition(int N, vector<vector<int>>& dislikes)
    {
        vector<vector<int>> mat(N + 1);
        for (auto& v : dislikes)
        {
            mat[v[0]].push_back(v[1]);
            mat[v[1]].push_back(v[0]);
        }
        
        vector<bool> visited(N);
        
        queue<pair<int, bool>> q;
        q.push({1, true});
        bool aTurn = false;
        while (int size = q.size())
        {
            aTurn = !aTurn;
            while (size--)
            {
                auto [node, isA] = q.front(); q.pop();
                visited[node] = true;
                if (isA != aTurn) return false;
                
                for (auto& next : mat[node])
                {
                    if (!visited[next])
                    {
                        q.push({next, !isA});
                    }
                }
            }
            
            if (q.empty())
            {
                for (int i = 1; i < N; ++i)
                {
                    if (!visited[i])
                    {
                        q.push({i, true});
                        aTurn = false;
                        break;
                    }
                }
            }
        }
        return true;
    }
    */
    


    // dfs. 셋을 어레이로 바꿔도 마찬가지로 TLE
    /*
    bool possibleBipartition(int N, vector<vector<int>>& dislikes)
    {
        vector<vector<int>> mat(N + 1);
        for (auto& v : dislikes)
        {
            mat[v[0]].push_back(v[1]);
            mat[v[1]].push_back(v[0]);
        }
        
        vector<bool> A(N + 1), B(N + 1);
        for (int i = 0; i < N; ++i)
        {
            if (!isBipartition(A, B, mat, i, !B[i])) return false;
        }
        return true;
        
    }
    
    static bool isBipartition(vector<bool>& A, vector<bool>& B, const vector<vector<int>> mat, int curr, bool isA)
    {
        bool inA = A[curr];
        bool inB = B[curr];
        if (isA && inB) return false;
        if (!isA && inA) return false;
        if (inA || inB) return true;
        
        (isA ? A : B)[curr] = true;
        
        for (auto& next : mat[curr])
        {
            if (!isBipartition(A, B, mat, next, !isA)) return false;
        }
        return true;
    }
    */

    // dfs
    // TLE. 46 / 66 test cases passed.
    // 왜지
    /*
    bool possibleBipartition(int N, vector<vector<int>>& dislikes)
    {
        vector<vector<int>> mat(N + 1);
        for (auto& v : dislikes)
        {
            mat[v[0]].push_back(v[1]);
            mat[v[1]].push_back(v[0]);
        }
        
        unordered_set<int> A, B;
        for (int i = 0; i < N; ++i)
        {
            if (!isBipartition(A, B, mat, i, !B.count(i))) return false;
        }
        return true;
        
    }
    
    static bool isBipartition(unordered_set<int>& A, unordered_set<int>& B, const vector<vector<int>> mat, int curr, bool isA)
    {
        bool inA = A.count(curr);
        bool inB = B.count(curr);
        if (isA && inB) return false;
        if (!isA && inA) return false;
        if (inA || inB) return true;
        
        (isA ? A : B).insert(curr);
        
        for (auto& next : mat[curr])
        {
            if (!isBipartition(A, B, mat, next, !isA)) return false;
        }
        return true;
    }
    
};
*/

/*
Fastest:
static int _ = [] { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();

class Solution {
public:
    bool possibleBipartition(int n, const vector<vector<int>>& d) 
    {
        vector<bool> used(n + 1, 0);
        vector<int> color(n + 1, 0);
        vector<vector<int>> g(n + 1);
        
        for (const auto & p : d)
        {
            g[p[0] - 1].push_back(p[1] - 1); 
            g[p[1] - 1].push_back(p[0] - 1);
        }
        
        function<bool(int)> dfs;
        dfs = [&](int v)
        {
            for (const auto & e : g[v])
            {
                if (color[e] == color[v])
                    return false;

                if (used[e])
                    continue;

                if (color[e] == 0)
                    color[e] = - color[v];

                used[e] = true;
                if (!dfs(e))
                    return false;
            }

            return true;
        };

        for (int i = 1; i <= n; i++)
        {            
            if (used[i])
                continue;
            
            // print(i);

            queue<int> q;
            q.push(i);
            used[i] = true;
            
            if (color[i] == 0)
                color[i] = 1;
            
            if (!dfs(i))
                return false;
        }
        
        return true;
    }
};
*/
