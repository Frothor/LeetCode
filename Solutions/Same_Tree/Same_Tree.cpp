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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)  
            return true;  
  
        if (p != NULL && q != NULL)  
        {  
            return (  
            p->val == q->val &&  
            isSameTree(p->left, q->left) &&  
            isSameTree(p->right, q->right) );  
        }  
      
        return false;  
    }
};

/*
Another most common:
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return 1;
        if((!p && q)|| (p && !q)) return 0;
        if(p->val==q->val)
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        else return 0;
    }
};
Fastest:
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
		    return true;
        bool left,right;
	    if(p != nullptr && q != nullptr)
	    { 
            if(p->val != q->val)
                return false;

            if (p->left != nullptr && q->left != nullptr)
		    {
			   left= isSameTree(p->left,q->left);
		    }
            else{
                if(p->left == nullptr && q->left == nullptr)
                    left = true;
                else
                    return false;
            }
                
		    if (p->right != nullptr && q->right != nullptr)
		    {
			    right= isSameTree(p->right,q->right);
		    }
            else{
                if(p->right == nullptr && q->right == nullptr)
                    right = true;
                else
                    return false;
            }
            return right&&left;
         }
        else
            return false;
        }
};
*/