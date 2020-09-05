//Most common
class Solution {
public:
    void helper(stack<TreeNode*>&st, TreeNode*root){
        while(root){ // smallest value on top
            st.push(root);
            root=root->left;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode*> s1, s2;
        helper(s1, root1);
        helper(s2, root2);
        while(!s1.empty() || !s2.empty()){
            stack<TreeNode*>&st = s1.empty() ? s2 : s2.empty() ? s1 : s1.top()->val < s2.top()->val ? s1 : s2;
            TreeNode* cur = st.top(); st.pop();
            ans.push_back(cur->val);
            helper(st, cur->right);
        }
        return ans;
    }
};

//Fastest
class Solution {
public:
    static vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        static int a[10000];
        int i = 0;
        GAE(root1, a, i);
        int j = i;
        GAE(root2, a, j);
        vector<int> v(j);
        merge(a, a + i, a + i, a + j, begin(v));
        return v;
    }
    static void GAE(TreeNode* n, int* p, int& i) {
        if (n) {
            GAE(n->left,  p, i);
            p[i++] = n->val;
            GAE(n->right, p, i);
        }
    }
};
static const auto speedup = []() {
std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();