class Solution {
    int util(TreeNode* root,long long int& tilt) {
        if(!root)
            return 0;
        int leftSubTreeSum = util(root->left,tilt);
        int rightSubTreeSum = util(root->right,tilt);
        tilt += abs(leftSubTreeSum-rightSubTreeSum);
        return leftSubTreeSum + root->val + rightSubTreeSum;
    }
public:
    int findTilt(TreeNode* root) {
        long long int tilt = 0;
        util(root,tilt);
        return tilt;
    }
};

//Third fastest
class Solution {
public:
    
    int get(TreeNode*A,int&s)
    {
        if(A==0)return 0;
        int l=get(A->left,s);
        int r=get(A->right,s);
        int sum=l+r+A->val;
        A->val=abs(l-r);
        s+=A->val;
        return sum;
    }
    
    int findTilt(TreeNode* A) {
        int s=0;
        get(A,s);
        return s;
    }
};

//Second fastest
class Solution {
public:
    int func(TreeNode *root,int &ans)
    {
        if(root==NULL)
            return 0;
        int l=func(root->left,ans);
        int r=func(root->right,ans);
        ans+=abs(l-r);
        return l+r+root->val;
    }
    
    int findTilt(TreeNode* root) {
        
        int ans=0;
        int x=func(root,ans);
        return ans;
        
    }
};

//Fastest
class Solution {
    
    int helper(TreeNode *root, int &sum)
    {
        if(!root)
        {
            sum = 0;
            return 0;
        }
        int lSum, rSum, l, r;
        l = helper(root->left, lSum);
        r = helper(root->right, rSum);
        sum = lSum + rSum + root->val;
        return abs(lSum - rSum) + l + r;
    }
    
public:
    int findTilt(TreeNode* root) {
        int sum;
        return helper(root, sum);
    }
};