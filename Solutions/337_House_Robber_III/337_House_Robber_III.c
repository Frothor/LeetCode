//Fastest
#define max(x,y) (x>y?x:y)

typedef struct TreeNode* Node;
struct robber{
    int if_rob;
    int if_not_rob;
};
typedef struct robber ROB;
struct robber helper(Node root){
    ROB local={0,0};
    if(root){
        ROB left = helper(root->left);
        ROB right= helper(root->right);
        local.if_not_rob=max(left.if_rob,left.if_not_rob)+max(right.if_rob,right.if_not_rob);
        local.if_rob=root->val+left.if_not_rob+right.if_not_rob;
        return local;
        
    }else{
        return local;
    }
    
}

int rob(struct TreeNode* root){
    ROB money=helper(root);
    return max(money.if_rob,money.if_not_rob);
    
}