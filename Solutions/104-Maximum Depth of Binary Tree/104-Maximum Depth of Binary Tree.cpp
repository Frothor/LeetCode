//Second fastest
class Solution {
public:
    int maxDepth(TreeNode* root) {        
        //return root == NULL ? 0:  1 + max(maxDepth(root->left), maxDepth(root->right)); // ok
		return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};

//Another
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
return max(maxDepth(root->left),maxDepth(root->right))+1;
       
    }
};

//Fastest
class Solution {
    
public:
    int findMax (TreeNode* n,int depth){
        if (n == nullptr) return depth;
        
        return max(findMax(n->left, depth +1), findMax(n->right, depth +1));
        
    }
    int maxDepth(TreeNode* root) {
        return findMax ( root,0);
    }
};