//Fastest
//https://leetcode.com/problems/increasing-order-search-tree/discuss/958108/C%2B%2B-Inorder-Traversal-O(N)
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
    void inorder(TreeNode*& ans, TreeNode* root) {
        if (!root) return;
        inorder(ans, root->left);
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        inorder(ans, root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* temp;
        TreeNode* ans = new TreeNode();
        temp = ans;
        inorder(ans, root);
        return temp->right;
    }
};

//Another
class Solution {
    queue<TreeNode*> qt;
public:
    TreeNode* increasingBST(TreeNode* root) {
        traverse(root);
        
        TreeNode* head  = NULL;
        if(qt.size() > 0)
        {
            head = qt.front();
            qt.pop();
            
            TreeNode* p = head;
            
            while(!qt.empty())
            {
                p->left = NULL;
                p->right = qt.front();
                qt.pop();
                p = p->right;
            }
            
            p->left = NULL;
            p->right = NULL;
            
        }
        
        return head;
    }
    
    void traverse(TreeNode* node)
    {
        if( node == NULL ) return;
        
        if(node->left != NULL) traverse(node->left);
        qt.push(node);
        if(node->right != NULL) traverse(node->right);        
    }
};