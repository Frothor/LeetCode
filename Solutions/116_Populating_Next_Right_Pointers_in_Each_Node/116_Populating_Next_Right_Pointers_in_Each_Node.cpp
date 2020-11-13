//Most common
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root and root->left) {
            root->left->next = root->right;
            auto c1 = root->left, c2 = root->right;
            while(c1->right) c1->right->next = c2->left, c1 = c1->right, c2 = c2->left;
            root->left = connect(root->left), root->right = connect(root->right);
        }
        return root;
    }
};

//Fourth fastest
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0 ; i<n-1 ; ++i){
                Node* curr = q.front();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                q.pop();
                curr->next = q.front();
            }
            q.front()->next=NULL;
            if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
            q.pop();
        }
        return root;
    }
};

//Third fastest
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        dfs(root->left, root->right, root);
        return root;
    }
    
    void dfs(Node* left, Node* right, Node* root) {
        if (!(left && right)) {
            return;
        }
        left->next = right;
        if (root->next) {
            right->next = root->next->left;
        }
        dfs(left->left, left->right, left);
        dfs(right->left, right->right, right);
    }
};

//Second fastest
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> parent; //= new queue<Node*>();
        queue<Node*> children; //= new queue<Node*>();
        
        parent.push(root);
            
        while(!parent.empty() || !children.empty())
        {
            while(!parent.empty())
            {
                Node* curr = parent.front();
                parent.pop();
                if(curr != NULL)
                {
                    if(!parent.empty())
                    {
                        curr->next = parent.front();
                    }

                    children.push(curr->left);
                    children.push(curr->right);
                }
            }
            swap(parent, children);
        }
        
        return root;
    }
};

//Fastest
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;++i){
                Node* cur = q.front();
                q.pop();
                if(i == n-1) cur->next = NULL;
                else cur->next = q.front();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return root;
    }
};