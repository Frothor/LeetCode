//Morris inorder constant space
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        while(cur!=NULL)
        {
            if(cur->left!=NULL)
            {
                TreeNode* temp=cur->left;
                 TreeNode* nxtcur = cur->left;
                while(temp->right!=NULL)
                {
                    temp=temp->right;
                }
                temp->right = cur;
                cur->left=NULL;
                cur=nxtcur;
            }
            else
            {
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};

//Another
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
private:
    void inorder(TreeNode* node, vector<int>& res){
        if(!node) return;
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }
};