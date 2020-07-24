class Solution {
public:
   vector < vector <int> > res;
   void solve(vector < vector <int> >& graph, int node, int target, vector <int>temp){
      temp.push_back(node);
      if(node == target){
         res.push_back(temp);
         return;
      }
      for(int i = 0; i < graph[node].size(); i++){
         solve(graph, graph[node][i], target, temp);
      }
   }
   vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      vector <int> temp;
      solve(graph, 0, graph.size() - 1, temp);
      return res;
   }
};

/*
class Solution {
public:
    void backtrack(int node_id, vector<int> & path, vector<vector<int>> & results, vector<vector<int>>& graph) {
        const int target = graph.size() - 1;
        if (node_id == target) {
            results.push_back(vector<int>(path));
            return;
        }
        
        for (auto n : graph[node_id]) {
            path.push_back(n);
            backtrack(n, path, results, graph);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> results;
        vector<int> path;
        path.push_back(0);
        backtrack(0, path, results, graph);
        return results;
    }
};

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(0, graph, path, res);
        return res;
    }
    void backtrack(int currNode, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& res) {
        path.push_back(currNode);
        if(currNode == graph.size() - 1) {
            res.push_back(path);
        }
        else {
            for(int nextNode: graph[currNode]) {
                backtrack(nextNode, graph, path, res);
            }
        }
        path.pop_back();
    }
};
*/