//Second fastest
class Solution {

public:

int helper(TreeNode* root,int curmin,int curmax)
{
    if(root==NULL)
    {
        return curmax-curmin;
    }
    
    curmax=max(root->val,curmax);
    curmin=min(root->val,curmin);
    
    int l=helper(root->left,curmin,curmax);
    int r=helper(root->right,curmin,curmax);
    
    return max(l,r);
}

int maxAncestorDiff(TreeNode* root) {
    
    if(root==NULL)
    {
        return 0;
    }
    
    return helper(root,root->val,root->val);
    
    
}
};

//Another
class Solution {
public:
        
        int helper(TreeNode* root,int min_curr,int max_curr){
                if(root==NULL){
                        return max_curr-min_curr;
                }
                
                min_curr = min(root->val,min_curr);
                max_curr = max(root->val,max_curr);
                
                int l = helper(root->left,min_curr,max_curr);
                int r = helper(root->right,min_curr,max_curr);
                
                return max(l,r);
        }
        
    int maxAncestorDiff(TreeNode* root) {
            int min_curr = INT_MAX;
            int max_curr = INT_MIN;
        return helper(root,min_curr,max_curr);
    }
};

//Fastest
class Solution {
public:
     int helper(TreeNode* root,int min_curr,int max_curr){
                if(root==NULL){
                        return max_curr-min_curr;
                }
                
                min_curr = min(root->val,min_curr);
                max_curr = max(root->val,max_curr);
                
                int l = helper(root->left,min_curr,max_curr);
                int r = helper(root->right,min_curr,max_curr);
                
                return max(l,r);
        }
        
    int maxAncestorDiff(TreeNode* root) {
            int min_curr = INT_MAX;
            int max_curr = INT_MIN;
        return helper(root,min_curr,max_curr);
    }
};