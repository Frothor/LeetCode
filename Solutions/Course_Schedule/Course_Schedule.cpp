class Solution {

    bool isCyclic(vector<vector<int>>& adj, vector<int>& visited, int curr){
        if(visited[curr]==2)
            return true;
        
        visited[curr] = 2;
        for(int i=0; i<adj[curr].size();++i)
            if(visited[adj[curr][i]]!=1)
                if(isCyclic(adj, visited, adj[curr][i]))
                    return true;
        
        visited[curr] = 1;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i<prerequisites.size(); i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        vector<int> visited(numCourses, 0);
        for(int i = 0; i< numCourses; i++)
            if(visited[i]==0)
                if(isCyclic(adj, visited, i))
                    return false;
        
        return true;
    }
};

/*
Fastest:
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> adj(numCourses);
        vector<int> inDegree(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int v1 = prerequisites[i][0];
            int v2 = prerequisites[i][1];
            adj[v2].insert(v1);
            inDegree[v1]++;
        }
        
        queue<int> q;
        int count = 0;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();   
            count++;
            for(auto it = adj[top].begin(); it != adj[top].end(); it++){
                inDegree[*it]--;
                if(inDegree[*it] == 0){
                    q.push(*it);
                }
            }
        }
        
        if(count == numCourses) return true;
        return false;
    }
};

Second Fasteest:
class Solution {
public:
    // First solution
    // Parse input into map from node -> edges
    // For each node
    //      if unvisited: DFS(curPath, visited, map)
    //          if we see cycle, return false
    
    
    // Second solution
    // Find node with no incoming edges
    // Remove it from graph since it shouldn't affect cycles
    // Continue until we can't find one or if graph is empty

    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int> > graph;
        vector<int> incomingNodes(numCourses, 0);
        
        for (const vector<int>& edge : prerequisites) {
            graph[edge[0]].push_back(edge[1]);
            ++incomingNodes[edge[1]];
        }
        
        int curHeadNode;
        queue<int> headNodes;
        
        for (int i = 0, end = incomingNodes.size(); i < end; ++i) {
            if (incomingNodes[i] == 0) {
                headNodes.push(i);
            }
        }
        
        int numHeadNodesRemoved = 0;
        
        while (!headNodes.empty()) {
            for (int node : graph[headNodes.front()]) {
                --incomingNodes[node];
                
                if (incomingNodes[node] == 0) {
                    headNodes.push(node);
                }                
            }
            headNodes.pop();
            ++numHeadNodesRemoved;
        }
        
        return numHeadNodesRemoved == numCourses;
    }
};
*/