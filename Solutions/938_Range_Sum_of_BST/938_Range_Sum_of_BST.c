int rangeSumBST(struct TreeNode* root, int L, int R){
    if (!root) {
        return 0;
    }
    if(root->val<L){
        return rangeSumBST(root->right, L, R);
    }
    if(root->val>R){
        return rangeSumBST(root->left, L, R);
    }
    return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
}

//Third fastest
struct Tree {
    int val;
    struct Tree *left;
    struct Tree *right;
};

int rangeSumBST(struct Tree* root, int low, int high){
    int ans = 0;
    int l;
    int r;
    if(root == NULL){
        return 0;
    }
    l = rangeSumBST(root->left, low, high);
    r = rangeSumBST(root->right, low, high);
    if(root->val >= low && root->val <= high){
        ans = l + r + ans + root->val;
    }
    else{
        ans = l + r + ans;
    }
    return ans;
}

//Second fastest
int rangeSumBST(struct TreeNode* root, int low, int high){
    if (root == NULL) return 0;
    
    if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    }
    if (root->val > high) {
        return rangeSumBST(root->left, low, high);
    }
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

//Fastest
int rangeSumBST(struct TreeNode* root, int low, int high){
    if(root==NULL){
        return 0; 
    }
    if( root->val < low ){
        return rangeSumBST(root->right, low, high);
    }
    if( root->val > high){
        return rangeSumBST(root->left, low, high); 
    }
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high); 
}