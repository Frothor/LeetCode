//https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/discuss/969242/C%2B%2B-%3A-using-recursion-%3A-85-faster
//Second fastest
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
         if (root == NULL) return NULL;
         int left = getDepth(root->left);
         int right = getDepth(root->right);
        if (left == right) return root;
        else if (left > right) return subtreeWithAllDeepest(root->left);
        else return subtreeWithAllDeepest(root->right);
    }
    
private :
     int getDepth(TreeNode* node)
     {
         if (node == NULL) return 0;
         return 1 + std::max(getDepth(node->left),getDepth(node->right));
     }
};

//Another
class Solution {
public:
    int height(TreeNode* node){
        if(!node){
            return 0;
        }
        int l = height(node->left);
        int r = height(node->right);
        return max(l,r)+1;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* node) {
        if(!node){
            return NULL;
        }
        int lh = height(node->left);
        int rh = height(node->right);
        if(lh == rh){
            return node;
        }
        if(lh < rh){
            return subtreeWithAllDeepest(node->right);
        }
        return subtreeWithAllDeepest(node->left);
    }
};

//Fastest
class Solution
{
    public:
        int getLevel(TreeNode* node)
        {
            if(!node)
            {
                return 0;
            }
            return 1 + max(getLevel(node->left), getLevel(node->right));
        }
    
        TreeNode* subtreeWithAllDeepest(TreeNode* root)
        {
            if(!root)
            {
                return nullptr;
            }
            
            int leftDepth = getLevel(root->left);
            int rightDepth = getLevel(root->right);
            
            if(leftDepth == rightDepth)
            {
                return root;
            }
            else if(leftDepth > rightDepth)
            {
                return subtreeWithAllDeepest(root->left);
            }
            else
            {
                return subtreeWithAllDeepest(root->right);
            }
        }
};