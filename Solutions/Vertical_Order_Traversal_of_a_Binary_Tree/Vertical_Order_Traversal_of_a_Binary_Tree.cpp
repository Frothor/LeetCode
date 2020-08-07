/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int left_most = INT_MAX, right_most = INT_MIN;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        if(!root)
            return {};
        int x = 0, y = 0;
        map<int, set<pair<int, int>>> M;
        solve(root, M, x, y);
        vector<vector<int>> V;
        vector<int> tmp;
        for(int i = left_most; i<= right_most; i++){
            tmp.clear();
            for(auto m: M[i]){
                tmp.push_back(m.second);
            }
            V.push_back(tmp);
        }
        return V;
    }
    void solve(TreeNode* root, map<int, set<pair<int, int>>>& M, int x, int y){
        if(root){
            if(left_most > x)
                left_most = x;
            if(right_most < x)
                right_most = x;
            M[x].insert(make_pair(-y, root->val));
            solve(root->left, M, x - 1, y - 1);
            solve(root->right, M, x + 1, y -1);
        }
    }
};

//Fastest:
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        
        map<pair<int, int>, set<int>> map;
        int maxValue = INT_MIN;
        int minValue = INT_MAX;
        dfs(map, root, 0, 0, maxValue, minValue);
        vector<vector<int>> result(maxValue - minValue + 1);
        for (const auto& pair : map) {
            int index = pair.first.first - minValue;
            result[index].insert(result[index].end(), pair.second.begin(), pair.second.end());
        }
        return result;
    }
    
    void dfs(map<pair<int, int>, set<int>>& map, TreeNode* root, int x, int y, int& maxValue, int& minValue) {
        if (root == NULL) {
            return;
        }
        map[{x, y}].insert(root->val);
        maxValue = max(maxValue, x);
        minValue = min(minValue, x);
        dfs(map, root->left, x - 1, y + 1, maxValue, minValue);
        dfs(map, root->right, x + 1, y + 1, maxValue, minValue);
    }

};

//BFS:
class Solution {
public:
    struct custom {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            return (a[2] < b[2]) || (a[1] == b[1] && a[2] == b[2] && a[0] > b[0]);
        }
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, vector<int>>> q; // node, {x, y}
        map<int, priority_queue<vector<int>, vector<vector<int>>, custom>> mp; // x, {val, x, y}
        q.push({root, {0, 0}}); 
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            mp[cur.second[0]].push({cur.first->val, cur.second[0], cur.second[1]});
            if (cur.first->left) q.push({cur.first->left, {cur.second[0] - 1, cur.second[1] - 1}});
            if (cur.first->right) q.push({cur.first->right, {cur.second[0] + 1, cur.second[1] - 1}});
        }
        for (auto &m : mp) {
            vector<int> tmp;
            while (!m.second.empty()) {
                tmp.push_back(m.second.top()[0]);
                m.second.pop();
            }
            res.push_back(tmp);
        }
        return res;
    }
};

//Need fix with order of nodes in same distance
class Solution {
public:
    int left_most = INT_MAX, right_most = INT_MIN;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return {};
        map<int, vector<int> > m;
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 0});
        while (!q.empty()){
            TreeNode* node = q.front().first;
		    int dist = q.front().second;
		    q.pop();
            
            if(left_most > dist)
                left_most = dist;
            if(right_most < dist)
                right_most = dist;
            
            m[dist].push_back(node->val); 
            
            if (node->left)
			    q.push({node->left, dist - 1});
		    if (node->right)
			    q.push({node->right, dist + 1});
        }
        
        vector<vector<int>> res;
        for(int i = left_most; i<= right_most; i++){
            res.push_back(m[i]);
        }
        return res;
    }
};