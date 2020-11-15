//Third fastest
class Solution {
    int total = 0;
    void dfs( TreeNode* root, int L, int R) {
        if(!root) return;
        
        if( root->val >= L && root->val <= R ){
            total += root->val;
        }
        
        auto leftmost = root->left;
        while( leftmost && leftmost->left ) {
            leftmost = leftmost->left;
        }
        if( leftmost && leftmost->val > R ) {
            return;
        }
        dfs( root->left, L, R);

        auto rightmost = root->right;
        while( rightmost && rightmost->right ) {
            rightmost = rightmost->right;
        }
        if( rightmost && rightmost->val < L ) {
            return;
        }
        dfs( root->right, L, R);
    }
    
    int recursive_dfs(TreeNode* root, int L, int R) {
        total = 0;
        dfs( root, L, R);   
        return total;
    }
    
    int iteractive_morris( TreeNode* root, int L, int R) {
        total = 0;
        
        while( root ) {
            if( !root->left ) {
                if( root->val >= L && root->val <= R ){
                    total += root->val;
                }                
                root = root->right;
            } else {
                auto prev = root->left;
                while( prev->right && prev->right != root )
                    prev = prev->right;
                
                if( prev->right == nullptr ) {
                    prev->right = root;
                    root = root->left;
                } else {
                    prev->right = nullptr;
                    if( root->val >= L && root->val <= R ){
                        total += root->val;
                    }                      
                    root = root->right;
                }
            }
        }
        return total;
    }
    int iteractive_convert_linklist( TreeNode* root, int L, int R) {
        int sum = 0;
        while( root ) {
            if( root->left ) {
                auto prev = root->left;
                while( prev->right ) prev = prev->right;
                
                prev->right = root;
                auto tmp = root;
                root = root->left;
                tmp->left = nullptr;
            } else {
                if( root->val >= L && root->val <= R ){
                    sum += root->val;
                }                  
                root = root->right;
            }
        }
        return sum;
    }

public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        //return recursive_dfs(root, L, R);
        //return iteractive_morris(root, L, R);
        return iteractive_convert_linklist( root, L, R);
    }
};

//Second fastest
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        //Morris traversal
        TreeNode* cur = root, *pre = nullptr;
        int res = 0;
        while(cur) {
            if(cur->left) {
                pre = cur->left;
                while(pre->right) pre = pre->right;
                TreeNode* tmp = cur;
                cur = cur->left;
                tmp->left = NULL;
                pre->right = tmp;
            } 
            else {
                if(cur->val <= R && cur->val >= L) res += cur->val;
                cur = cur->right;
            }
        }
        return res;
    }
};

//Fastest
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
      TreeNode* cur = root, *pre = NULL;
      
      int res = 0;
      
      while(cur != NULL) {
        //For each node, check if we still need to tie it together to become a linked list.  If it's already tied, take the value
        if(cur->left != NULL) {
          pre = cur->left;
          while(pre->right != NULL) pre = pre->right;
          
          TreeNode* tmp = cur;
          cur = cur->left;
          tmp->left = NULL;
          pre->right = tmp;
        } 
        else {
          if(cur->val <= R && cur->val >= L) res+=cur->val;
          cur = cur->right;
        }
      }
      
      return res;
    }
};

#if 0
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        TreeNode *cur = root, *pre = nullptr;
        int res = 0;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                pre = cur->left;
                while (pre->right != nullptr) pre = pre->right;
                pre->right = cur;
                TreeNode *temp = cur;
                cur = cur->left;
                temp->left = nullptr;
            } else {
                if (cur->val >= L && cur->val <= R) res += cur->val;
                cur = cur->right;
            }
        }
        return res;
    }
};
#endif

#if 0
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
      if(!root) return 0;
      int self = 0;
      
      if(root->val <= R && root->val >= L) self+=root->val;
      
      if(root->val >= L) self+=rangeSumBST(root->left, L, R);
      if(root->val <= R) self+=rangeSumBST(root->right, L, R);
      
      return self;
    }
};
#endif