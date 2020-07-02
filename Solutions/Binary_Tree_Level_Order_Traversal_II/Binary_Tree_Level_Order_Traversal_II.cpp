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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        
        if(!root)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> nodes(n);
            for(int i = 0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                nodes[i] = node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            result.push_back(nodes);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

/*
Most common:
class Solution {
    
public:
    int height(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if (!root) return vector<vector<int>>();
        
        int h = height(root);
        
        vector<vector<int>> res(h);
        
        queue<TreeNode*> q;
        q.push(root);
        int curr = h-1;
        
        while (!q.empty()) {
            
            int sz = q.size();
            
            vector<int> t(sz);
            
            for (int i=0; i<sz; i++) {
                
                TreeNode* f = q.front();
                q.pop();
                
                t[i] = f->val;
                
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
                
            }
            
            res[curr] = t;
            curr--;
            
        }
        
        // reverse(res.begin(), res.end());
        
        return res;
    }
};

Fastest:
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	
		//Given binary tree [3,9,20,null,null,15,7],
		//return its bottom-up level order traversal as:
		//[
		//  [15,7],
		//  [9,20],
		//  [3]
		//]
		//0. root
		//1. for each level, find its children, push to a deque
		//2. pop_front this level
		//3. reverse res order

    	vector<vector<int>> res, final;
    	deque<TreeNode*> deq;
    	TreeNode* cur;

    	if(root == nullptr)
    		return res;

    	deq.push_back(root);

    	while(deq.size() != 0){
    		int level_len = deq.size();
    		vector<int> level;
    		for(int i = 0; i < level_len; ++i){
    			cur = deq.front();
    			level.push_back(cur->val);
    			deq.pop_front();
    			if(cur->left != nullptr)
    				deq.push_back(cur->left);
    			if(cur->right != nullptr)
    				deq.push_back(cur->right);
    		}
    		res.push_back(level);
    	}
    	for(int i = 0; i < res.size(); ++i)
    		final.push_back(res[res.size()-1-i]);


    	return final;
        
    }
};
*/
