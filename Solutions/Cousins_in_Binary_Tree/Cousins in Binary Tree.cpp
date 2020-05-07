/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        if(!root)
            return false;
        
        q.push(root);
        while(!q.empty()){
            bool has_x = false, has_y = false;
            int level_size = q.size();
            for(int i=0; i<level_size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->val == x)
                    has_x = true;
                if(curr->val == y)
                    has_y = true;
                
                if(curr->left && curr->right) {
                    if(curr->left->val == x && curr->right->val == y)
                        return false;
                    if(curr->right->val == x && curr->left->val == y)
                        return false;
                }
                
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
            }
            
            if(has_x && has_y)
                return true;
            
            if(has_x || has_y)
                return false;
        }
        return false;
    }
};

/* Another solution
class Solution {
public:
    void fun(TreeNode* root,int val,int& h,int& p,int par,int height)
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->val==val)
        {
            h=height;
            p=par;
            return;
        }
        fun(root->left,val,h,p,root->val,height+1);
        fun(root->right,val,h,p,root->val,height+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int h1=0,h2=0,par1=-1,par2=-2;
        fun(root,x,h1,par1,-1,0);
        fun(root,y,h2,par2,-1,0);
        if(h1==h2&&par2!=par1)
        {
            return true;
        }
        return false;
    }
};
*/

/* Faster solution
class Solution {
public:
    int xdepth, ydepth;
    bool commparent = false;
    TreeNode* saveparentleft=NULL;
    TreeNode* saveparentright = NULL;
    void rectraversal(TreeNode* root,int x, int y , int depth, TreeNode* parent)
    {
        
        if(root == NULL)
            return;                
        
        else
        {
            //cout << "rval " << root->val << endl;
            //cout << "depth " << depth << endl;
            depth++;
            if(root->val == x )
            {
                xdepth = depth;
                
                saveparentleft = parent;
                
            }
            if(root->val == y)
            {
                ydepth = depth;
               
                saveparentright = parent;
                
                
            }
            //depth = depth+1;
             rectraversal(root->left, x, y, depth, root);
             rectraversal(root->right, x, y, depth, root);
            return;
        }
    }
    
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        int depth=0;
        rectraversal(root, x, y, depth, root);
        cout << xdepth << ydepth << endl;
        cout << saveparentleft << saveparentright << endl;
        
        if(xdepth != ydepth)
            return false;
        else if(saveparentleft == saveparentright)
            return false;
        else
            return true;
            
        
        
        
    }
};
*/