//https://leetcode.com/problems/binary-search-tree-iterator/discuss/965938/C%2B%2B-Stack-trick-%2B-inoder
class BSTIterator {    
public: 
    BSTIterator(TreeNode* root) {
        while(root){
            stk.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* p = stk.top();
        stk.pop();
        int val = p->val;
        p = p->right;
        while(p){
            stk.push(p); // FILO: think about 3-node tree
            p = p->left;
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
    
private:
    stack<TreeNode* > stk;
};

//Third fastest
class BSTIterator {
public:
    BSTIterator(TreeNode* root) : call_stack_{}, current_{root} {
    }
    
    int next() {
        if (current_ == nullptr) {
            auto current = call_stack_.top();
            call_stack_.pop();
            current_ = current->right;
            return current->val;
        }
        
        if (current_->left == nullptr) {
            const int value = current_->val;
            current_ = current_->right;
            return value;
        }
        
        while (current_->left != nullptr) {
            call_stack_.push(current_);
            current_ = current_->left;
        }
        const int value = current_->val;
        current_ = current_->right;
        return value;
    }
    
    bool hasNext() {
        if (!call_stack_.empty()) {
            return true;
        }
        if (current_ == nullptr) {
            return false;
        }
        return true;
    }
private:
    std::stack<TreeNode*> call_stack_;
    TreeNode* current_;
};


//Second fastest
class BSTIterator {
public:
    void Traversal(TreeNode* node){
        if(node == nullptr)
            return;
        
        Traversal(node->left);
        inorder.push_back(node->val);
        Traversal(node->right);
    }
    BSTIterator(TreeNode* root) {
        Traversal(root);
        
    }
    
    int next() {
        return inorder[index++];
    }
    
    bool hasNext() {
        return (inorder.size() > index);
    }
    
private:
    vector<int> inorder;
    int index = 0;
};


//Fastest
class BSTIterator {
  std::stack<TreeNode*> worklist_;

 public:
  BSTIterator(TreeNode* root) { insert_left_path(root); }

  /// Returns the next smallest number.
  int next() {
    TreeNode* curr = worklist_.top();
    worklist_.pop();
    insert_left_path(curr->right);
    return curr->val;
  }

  /// Whether there is another number.
  bool hasNext() { return !worklist_.empty(); }

 private:
  void insert_left_path(TreeNode* node) {
    while (node != nullptr) {
      worklist_.push(node);
      node = node->left;
    }
  }
};