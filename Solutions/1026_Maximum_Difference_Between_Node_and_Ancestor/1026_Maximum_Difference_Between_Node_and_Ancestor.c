//Second fastest
int diff(struct TreeNode* root,int*max,int*min){
    if(root){
        int diff1=(*max)-root->val;
        if(diff1<0){
            (*max)=root->val;
            diff1=-diff1;
        }
        int diff2=root->val-(*min);
        if(diff2<0){
            (*min)=root->val;
            diff2=-diff2;
        }
        diff1=diff1>diff2?diff1:diff2;
        int maxTemp=*max;
        int minTemp=*min;
        diff2=diff(root->left,max,min);
        diff1=diff1>diff2?diff1:diff2;
        *max=maxTemp;
        *min=minTemp;
        diff2=diff(root->right,max,min);
        diff1=diff1>diff2?diff1:diff2;
        return diff1;
    }
    return 0;
}
int maxAncestorDiff(struct TreeNode* root){
    if(!root)return 0;
    int max=root->val;
    int min=root->val;
    return diff(root,&max,&min);
}

//Fastest
int madHelper(struct TreeNode* node, int min_seen, int max_seen) {
    int leftdiff,rightdiff;
    if (!(node -> val < min_seen || node -> val > max_seen))
        ;
    else {
        if (node -> val > max_seen)
            max_seen = node -> val; 
        else 
            min_seen = node -> val;    
        }
    int diff = max_seen - min_seen;
    if (node -> left == NULL && node -> right == NULL)
        return diff;
    else if (!(node -> left != NULL && node -> right != NULL)) {
        if (node -> left == NULL) {
            leftdiff = 0;
            rightdiff = madHelper(node -> right, min_seen, max_seen);
            return (rightdiff > diff ? rightdiff : diff);
        } else {
            rightdiff = 0;
            leftdiff = madHelper(node -> left, min_seen, max_seen);
            return (leftdiff > diff ? leftdiff : diff);
        }
    }
    else {
        leftdiff = madHelper(node -> left, min_seen, max_seen);
        rightdiff = madHelper(node -> right, min_seen, max_seen);
        return leftdiff > rightdiff ? leftdiff : rightdiff;
    }
}

int maxAncestorDiff(struct TreeNode* root){
    if (root == NULL)
        return 0;
    else 
        return madHelper(root, root -> val, root -> val);
}

//Another
#define max(a,b) (a)>(b)? (a):(b)
#define min(a, b) (a)<(b)?(a):(b)

void dfs(struct TreeNode *root, int mn, int mx, int *res)
{
    if (root == NULL)
        return;
    
    mn = min(mn, root->val);
    mx = max(mx, root->val);
    
    if (abs(mx - mn) > *res)
        *res = mx - mn;
    
    dfs(root->left, mn, mx, res);
    dfs(root->right, mn, mx, res);
}

int maxAncestorDiff(struct TreeNode* root){
    int res = 0;
    
    if (root == NULL)
        return 0;
    
    dfs(root, INT_MAX, INT_MIN, &res);
    
    return res;
}