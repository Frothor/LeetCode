//Third fastest
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int tree_tilt = 0;
int node_sum(struct TreeNode *root)
{
	int node_tilt,left_sum = 0, right_sum = 0;
	if (root != NULL)
	{
		left_sum = node_sum(root->left);
		right_sum = node_sum(root->right);
		node_tilt = abs(left_sum - right_sum);
		tree_tilt+=node_tilt;
		return(root->val + left_sum + right_sum);
	}
	else
		return(0);
}
int findTilt(struct TreeNode* root)
{
    tree_tilt=0;
	node_sum(root);
	return(tree_tilt);
}

//Another
int tilt = 0;
int sum(struct TreeNode* root){
    if(root == NULL) return 0;
    int node=0;
    int left = sum(root->left);
    int right = sum(root->right);
    node = abs(left - right);
    tilt+=node;
    return(root->val + left + right);
}

int findTilt(struct TreeNode* root){
    tilt=0;
	sum(root);
	return(tilt);
}


//Second fastest
inline int abs(int i){
        return i < 0 ? -i : i;
}

int ans;

int helper(struct TreeNode* root){
        if(root == 0)
                return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        ans += abs(left - right);
        return  left + right + root->val;
}

int findTilt(struct TreeNode* root){
        ans = 0;
        helper(root);
        return ans;
}

//Fastest
int sum_left (struct TreeNode *root, int *tilt) {
    int left = 0, right = 0;
    if (!root) {
        return 0;
    }
    left = sum_left(root->left, tilt);
    right = sum_left(root->right, tilt);
  
    *tilt += abs(left - right);
    return left + right + root->val; 
 
}
int findTilt(struct TreeNode* root) {
  
    int ls = 0, rs = 0;
    if (!root) {
        return 0;
    }
    rs = sum_left(root, &ls);
    
    return (ls);
}