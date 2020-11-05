//Second fastest
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int bt_diameter(struct TreeNode* root, int *diameter)
{   
    if (root == NULL)
        return 0;
    
    int left_h = bt_diameter(root->left, diameter);
    int right_h = bt_diameter(root->right, diameter);
    int curr_dia = left_h + right_h;
    
    *diameter = MAX(*diameter, curr_dia);
    return 1 + MAX(left_h, right_h);
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    int diameter = 0;
    bt_diameter(root, &diameter);
    return diameter;
}

//Another
int height(struct TreeNode* root, int *ans){
    if (root == NULL) return 0; 
  
    int left = height(root->left, ans);
    int right = height(root->right, ans);
        
    *ans = fmax(*ans, left+right);
    return 1 + fmax(left, right);
}

int diameterOfBinaryTree(struct TreeNode* root){
    int ans = 0;
    height(root, &ans);
    return ans;
}

//Fastest
int find_diameter(struct TreeNode* root, int* diameter) {
    if (!root)
        return 0;
    
    int left = find_diameter(root->left, diameter);
    int right = find_diameter(root->right, diameter);
    if (*diameter < left + right)
        *diameter = left + right;
    return left > right ? left + 1 : right + 1;
}


int diameterOfBinaryTree(struct TreeNode* root){
    int diameter = 0;
    find_diameter(root, &diameter);
    return diameter;
}