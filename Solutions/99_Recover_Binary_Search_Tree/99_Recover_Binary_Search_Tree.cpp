class Solution {
public:
    void inorder(TreeNode* root,vector<int>&bs){
        if(root==NULL){
            return;
        }
        inorder(root->left,bs);
        bs.push_back(root->val);
        inorder(root->right,bs);
    }
    void recover(TreeNode* root,int &a,int &b,TreeNode* &r){
        if(root==NULL){
            return;
        }
        if(root->val==a && root!=r){
            root->val=b;
            r=root;
        }else if(root->val==b && root!=r){
            root->val=a;
            r=root;
        }
        recover(root->left,a,b,r);
        recover(root->right,a,b,r);
    }
    void recoverTree(TreeNode* root) {
        vector<int>bs;
        inorder(root,bs);
        int a=-1,b=-1;
        int count=0;
        for(int i=0;i<bs.size()-1;i++){
            if(bs[i]>bs[i+1] && count==0){
                a=i;
                count++;
            }else if(bs[i]>bs[i+1] && count==1){
                b=bs[i+1];
                break;
            }
        }
        if(b==-1){
            b=bs[a+1];
        }
        a=bs[a];
        TreeNode* r;
        recover(root,a,b,r);
    }
};

//Fourth fastest
class Solution {
public:
    // Time O(n) | Space O(1) - where n is the number of elements
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second = NULL, *parent = NULL;
        TreeNode *curr, *pre;
        curr = root;
        while(curr){
            if(!curr->left){
                if(parent && parent->val > curr->val){
                    if(!first) first = parent;
                    second = curr;
                }
                parent = curr;
                curr = curr->right;
            } else {
                pre = curr->left;
                while(pre->right && pre->right != curr) pre = pre->right;
                if(!pre->right){
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    
                    pre->right = NULL;
                    if(parent->val > curr->val){
                        if(!first) first = parent;
                        second = curr;
                    }
                    parent = curr;
                    curr = curr->right;
                }
            }
        }
        if(first && second) swap(first->val, second->val);
    }
};

//Third fastest
void inord(TreeNode* root , vector<int> &vect)
{
    if(root)
    {
        inord(root->left , vect);
        vect.push_back(root->val);
        inord(root->right, vect);
    }
}
void pre(TreeNode* root , vector<int> &vect , int &i)
{
    if(root)
    {
        pre(root->left , vect , i);
        root->val = vect[i];
        i++;
        pre(root->right , vect , i);
    }
}
class Solution {
public:
    void recoverTree(TreeNode* root) {
            vector<int> vect;
        inord(root , vect);
        sort(vect.begin(), vect.end());
        int j=0;
        pre(root, vect , j);
       // return root;
    }
};

//Second fastest
class Solution {
public:
    TreeNode * x=NULL, * y=NULL, * prev=NULL;
    
    void find_nodes(TreeNode * root) {
        if (!root) return;
        
        find_nodes(root->left);
        
        if (prev && root->val < prev->val) {
            y = root;
            if (x==NULL) {
                x = prev;
            } else {
                return;
            }
        }
        prev = root;
        
        find_nodes(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        find_nodes(root);
        int temp;
        if (x&&y) {
            temp = x->val;
            x->val = y->val;
            y->val = temp;
        }
    }
};

//Fastest
class Solution {
private:
    void traverse(TreeNode* root, TreeNode*& pre, TreeNode*& first, TreeNode*& second)
    {
        if(!root) return ;
        traverse(root->left, pre, first, second);
        if(pre && pre->val>root->val)
        {
            if(!first) first = pre;
            second = root;
        }
        pre = root;
        traverse(root->right, pre, first, second);
    }
public:
    void recoverTree(TreeNode* root) 
    {
        TreeNode *first = NULL, *second = NULL, *pre = NULL;
        traverse(root, pre, first, second);
        if(first) swap(first->val, second->val);
    }
};