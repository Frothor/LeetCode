//Recoursive

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);
        if (val > root->val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};

//Iterative Solution

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val, bool f = true)
    {
        if (!root)
            return new TreeNode(val);
        TreeNode *current = root;
        while (f)
            if (current->val < val)
                if (current->right)
                    current = current->right;
                else
                    current->right = new TreeNode(val), f = false;
            else if (current->left)
                current = current->left;
            else
                current->left = new TreeNode(val), f = false;
        return root;
    }
};

//Second fastest
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);
        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};

static const auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

//Fastest
static auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int data)
    {
        if (!root)
            return new TreeNode(data);

        if (data == root->val)
            return nullptr;

        else if (data < root->val)
            root->left = insertIntoBST(root->left, data);

        else
            root->right = insertIntoBST(root->right, data);

        return root;
    }
};