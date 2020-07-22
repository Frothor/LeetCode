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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(!root)
            return result;
        
        stack<TreeNode*> s1, s2;
        
        s1.push(root);
        while(true){
            vector<int> level;
            while(!s1.empty()){
                TreeNode* curr = s1.top();
                s1.pop();
                level.push_back(curr->val);
                if(curr->left)
                    s2.push(curr->left);
                if(curr->right)
                    s2.push(curr->right);
            }
            result.push_back(level);
            level = {}; 
            if(s2.empty())
                break;
            while(!s2.empty()){
                TreeNode* curr = s2.top();
                s2.pop();
                level.push_back(curr->val);
                if(curr->right)
                    s1.push(curr->right);
                if(curr->left)
                    s1.push(curr->left);
            }
            result.push_back(level);
            if(s1.empty())
                break;
        }
        return result; 
    }
};


/*
Most common:
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> retVal;
        if(root){
            std::queue<TreeNode*> q;
            q.push(root);
            int layer = 0;
            while(!q.empty()){
                
                const std::size_t Q_LENGTH = q.size();
                retVal.push_back(std::vector<int>(Q_LENGTH, 0));
                
                if(layer % 2){
                    for(int i = Q_LENGTH - 1; i > -1; --i){
                        retVal[layer][i] = q.front()->val;
                        if(q.front()->left){
                            q.push(q.front()->left);
                        }
                        
                        if(q.front()->right){
                            q.push(q.front()->right);
                        }
                        q.pop();
                    }
                    
                }
                else{
                    for(int i = 0; i < Q_LENGTH; ++i){
                        retVal[layer][i] = q.front()->val;
                        if(q.front()->left){
                            q.push(q.front()->left);
                        }
                        
                        if(q.front()->right){
                            q.push(q.front()->right);
                        }
                        q.pop();
                    }
                }
                
                ++layer;
            }
        }
        return retVal;
    }

Fastest:
class Solution {
public:
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) {
        return vector<vector<int> > ();
    }
    vector<vector<int> > result;

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while ( !nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->val;
            if (node->left) {
                nodesQueue.push(node->left);
            }
            if (node->right) {
                nodesQueue.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}
};

*/