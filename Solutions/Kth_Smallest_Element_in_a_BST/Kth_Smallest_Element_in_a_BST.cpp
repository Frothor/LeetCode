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
    void inorder(TreeNode* root, vector<int> &nums, int k){
        if(!root)
            return;
        
        inorder(root->left, nums, k);
        
        if(++nums[0] == k){
            nums[1] = root->val;
            return;
        }
        
        inorder(root->right, nums, k);
        
    } 
    
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums(2);
        inorder(root, nums, k);
        
        return nums[1];
    }
};

/*
Most common:
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root!=NULL){
                st.push(root);
                root = root->left;
            }
            auto top = st.top();
            if(!(--k)){return top->val;}
            st.pop();
            root = top->right;
        }
        return -1;
    }
};

Fastest:
class Solution {
public:
    int result;
    int index = -1;
    void traverse(TreeNode* root, int &k){
        if(root == NULL)
            return;
        traverse(root -> left, k);
        index ++;
        if(index == k-1)
            result = root -> val;
        else
            traverse(root -> right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return result;
    }
};


Another:
class Solution {
public:
    int numOfNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        return 1 + numOfNodes(root->left) + numOfNodes(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ln = numOfNodes(root->left);
        
        if (ln == k - 1) {
            return root->val;
        } else if (ln < k - 1) {
            return kthSmallest(root->right, k - ln - 1);
        } else {
            return kthSmallest(root->left, k);
        }
    }
};
*/