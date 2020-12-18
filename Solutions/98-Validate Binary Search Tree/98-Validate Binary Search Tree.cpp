//Third fastest
class Solution {
public:
	queue<int> q;
	int pass = 1;

	void DFS(TreeNode* root) {

		if(pass != 1)
			return;

		if(root != NULL){
			DFS(root->left);

			if(q.empty())
				q.push(root->val);
			else{
				if(root->val > q.front()){
					q.pop();
					q.push(root->val);
				}
				else
					pass = 0;
			}
			DFS(root->right);
		}
		return;
	}

    bool isValidBST(TreeNode* root) {
		int tmp1;
        int tmp2;
		DFS(root);

		if(pass == 1)
			return true;
		return false;
    }
};

//Second fastest
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr||(root->left==nullptr&&root->right==nullptr)) return true;
        if(root->left!=nullptr &&root->left->val>=root->val) return false;
        if(root->right!=nullptr &&root->right->val<=root->val) return false;
        bool isvalidL= isValidBST(root->left);
        if((root->left!=nullptr&&root->left->val>=root->val)||(root->left!=nullptr&&maxleft(root->left)>=root->val)) return false;
        bool isvalidR= isValidBST(root->right);
        if((root->right!=nullptr&&root->right->val<=root->val)||(root->right!=nullptr&&minright(root->right)<=root->val)) return false;
        return isvalidL&isvalidR;
    }
    
    int maxleft(TreeNode* left){
        while(left->right!=nullptr) left = left->right;
        return left->val;
    }
    
    int minright(TreeNode *right){
        while(right->left!=nullptr) right = right->left;
        return right->val;
    }
};

//Fastest
class Solution {
private:
    TreeNode* prev=NULL;
public:
    bool isValidBST(TreeNode* root) {
        if(!root)   return true;
        return isValidBST(root->left)  && help(root) && isValidBST(root->right);
    }
    
    bool help(TreeNode* root){
        if(!prev){
            prev=root;
            return true;
        }
        if(prev->val >= root->val)   return false;
        prev=root;
        return true;
    }
};