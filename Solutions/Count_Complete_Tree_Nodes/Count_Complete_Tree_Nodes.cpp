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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        TreeNode *left = root, *right = root;
        int l = 0, r = 0;
        while(left){
            l++;
            left = left->left;
        }
        
        while(right){
            r++;
            right = right->right;
        }
        
        if(l == r)
            return (1<<l)-1;
        
        return 1+countNodes(root->left) + countNodes(root->right);
        
    }
};

/*
Fastest:
class Solution {
public:
    int countNodes(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(root==NULL)
            return 0;
        TreeNode* curr=root, *prev;
        int c=0;
        while(curr)
        {
            if(curr->left==NULL)
            {
                c++;
                curr=curr->right;
            }
            else
            {
                prev=curr->left;
                while(prev->right)
                    prev=prev->right;
                TreeNode* temp=curr;
                prev->right=curr;
                curr=curr->left;
                temp->left=NULL;
            }
        }
        return c;
    }
};
*/