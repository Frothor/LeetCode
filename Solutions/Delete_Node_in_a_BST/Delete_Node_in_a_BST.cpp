// helper function to find successor node
struct TreeNode* minValueNode(struct TreeNode * node) 
{ 
    struct TreeNode * current = node; 
    while (current && current->left != NULL) 
        	current = current->left; 
  
    return current; 
} 

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    if (root == NULL)
		return root; 
  
    // key to delete is smaller than root so go left
    if (key < root->val) 
        root->left = deleteNode(root->left, key); 
 
    // key to delete is greater than root so go right
   	else if (key > root->val) 
        	root->right = deleteNode(root->right, key); 
    
    // we came to node to be deleted
    else
    {   
        // node to be deleted has only right child, so right child takes its place
        if (root->left == NULL) 
        { 
            	struct TreeNode *temp = root->right; 
            	free(root); 
            	return temp; 
        } 
        // node to be deleted has only left child, so left child takes its place
        else if (root->right == NULL) 
        { 
		    struct TreeNode *temp = root->left; 
		    free(root); 
		    return temp; 
        } 
        // node to be deleted has two children, so the successor takes its place
        struct TreeNode * temp = minValueNode(root->right); 
        root->val = temp->val; 
   
        root->right = deleteNode(root->right, temp->val);   	
    } 
    	
    return root; 
} 


class Solution {
public:
    static TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else { //key == root->val
            if (!root->left || !root->right) {
                const TreeNode* toDelete = root;
                root = root->left ? root->left : root->right;
                delete toDelete;
            }
            else {
                const TreeNode* leftmost = findLeftmost(root->right);
                root->val = leftmost->val;
                root->right = deleteNode(root->right, leftmost->val);
            }
        }
        return root;
    }
    
    static constexpr const TreeNode* findLeftmost(const TreeNode* root) {
        if (!root || !root->left) return root;
        return findLeftmost(root->left);
    }
};

//Most common

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
    TreeNode * temp=NULL, *temp1=NULL;
    TreeNode* search(TreeNode* root, int key)
    {
        if(root==NULL)
            return NULL;
        else if(root->val!=key &&root->left==NULL && root->right==NULL)
        {
            return root;
        }
        else if(root->val==key)
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete(root);
                // cout<<"yes";
                return NULL;
            }
            else if(root->left!=NULL && root->right!=NULL)
            {
                
                root->left=prede(root->left);
                temp=temp1;
                // cout<<"mk"<<temp->val;
                temp->right=root->right;
                temp->left=root->left;
                delete(root);
                return temp;
            }
            else if(root->left!=NULL)
            {
                
                temp= root->left;
                root->left=NULL;
                delete root;
                // cout<<"mk6";
                return temp;
            }
            else
            {
                temp= root->right;
                root->right=NULL;
                // root=temp;
                delete root;
                return temp;
            }
            // return temp;
        }
        else
        {
             if(root->val <key)
             {
                 root->right=search(root->right,key);
                 // return root;
             }
           else  if(root->val >key)
            {
                root->left=search(root->left,key);
            }
            return root;
        }
        // return temp;
    }
    TreeNode* prede(TreeNode* root)
    {
        TreeNode *temp2=NULL;
        if(root==NULL)
            return root;
        else if(root->right==NULL)
        {
            temp1=root;
            // cout<<temp1->val;
            if(root->left!=NULL)
                return root->left;
            return NULL;
        }
        else
        {
            temp2=prede(root->right);
            root->right=temp2;
            return root;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return root;
        // cout<<"mk";
        root=search(root,key);
            return root;
    }
};

//Fastest
class Solution {
public:
    TreeNode* deleteNode(TreeNode* r, int x) {
        if(r == nullptr) return nullptr;
        if(r->val < x) {
            r->right = deleteNode(r->right, x);
        } else if(r->val > x) {
            //r->lc--;
            r->left = deleteNode(r->left, x);
        } else {
            if(r->right != nullptr && r->left != nullptr) {
                TreeNode* t = r->left;
                while(t->right != nullptr) t = t->right;
                r->val = t->val;
                r->left = deleteNode(r->left, t->val);
                return r;
            }
            if(r->left != nullptr) return r->left;
            return r->right;
        }
        return r;
    }
};