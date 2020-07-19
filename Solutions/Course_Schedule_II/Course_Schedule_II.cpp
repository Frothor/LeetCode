class Solution {
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& s, vector<int>& visited){
        visited[u] = 1;
        for(int v: adj[u]){
            if(visited[v] == 1)
                return true;
            if(visited[v] == 0 && dfs(v, adj, s, visited))
                return true;
        }
        visited[u] = 2;
        s.push_back(u);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &courses: prerequisites)
            adj[courses[1]].push_back(courses[0]);
        
        vector<int> s;
        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; i++)
            if(visited[i] == 0 && dfs(i, adj, s, visited)) 
                return {};
        reverse(s.begin(), s.end());
        return s;
        
                
    }
};

/*
Most common:
class Solution {
    vector<int> ans;
    vector<char> color;
    vector<vector<int>> g;
public:
    bool dfs(int i)
    {
        if(color[i] == 0)
            return true;
        color[i] = 0;
        for(int j: g[i])
        {
            if(color[j] != 1 && dfs(j))
                return true;
        }
        // cout << i << " ";
        ans.push_back(i);
        color[i] = 1;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        ans = {};
        g.assign(numCourses, vector<int>());
        color.assign(numCourses, -1);
        
        for(vector<int> &v: p)
            g[v[0]].push_back(v[1]);
        
        for(int i = 0; i < numCourses; ++i)
        if(color[i] == -1 && dfs(i))
            return {};
        
        return ans;
    }
};

Fastest:
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> edges(n);
        vector<int> indeg(n, 0);
        
        for(int i=0;i<pre.size();i++){
            edges[pre[i][0]].push_back(pre[i][1]);
            indeg[pre[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for(int i=0;i<edges[x].size();i++){
                int y=edges[x][i];
                indeg[y]--;
                if(indeg[y]==0){
                    q.push(y);
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        if(ans.size() == n){
            return ans;
        } else{
            return vector<int>(0);
        }
        
    }
};
*/