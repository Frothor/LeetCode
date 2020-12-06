//BFS extra space
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/961835/C%2B%2B-or-Two-approaches-BFS-and-DFS
class Solution {
    queue<Node *> q;
public:
    Node* connect(Node* root) {
        if(root) {
            q.push(root);
            while(not q.empty()) {
                int len = q.size();
                Node *prev = nullptr;
                for(int i=0; i<len; i++) {
                    Node *n = q.front();
                    q.pop();
                    if(not n)   continue;
                    prev ? (prev->next = n) : nullptr;
                    prev = n;
                    q.push(prev->left);
                    q.push(prev->right);
                }
            }
        }
        return root;
    }
};

//DFS extra space
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/961835/C%2B%2B-or-Two-approaches-BFS-and-DFS
class Solution {
    vector<vector<Node *> > vec;
    void dfs(Node *root, int level) {
        if(not root)    return;
        if(vec.size() <= level) vec.push_back({});
        if(vec[level].size() > 0)
            vec[level][vec[level].size()-1]->next = root;
        vec[level].push_back(root);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
public:
    Node* connect(Node* root) {
        dfs(root, 0);
        return root;
    }
};

//Third fastest
class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<int>> result;
        queue<Node*> q;
        if(root == nullptr) return root;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            Node* prev = nullptr;
            for(int i = 0; i < size; --size)
            {
                if(prev)
                    prev->next = q.front();
                prev = q.front();
                q.pop();
                if(prev->left)q.push(prev->left);
                if(prev->right)q.push(prev->right);
            }

            prev->next = nullptr;
        }
        return root;
    }
};

//Second fastest
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for (int i=0; i<size; i++){
                Node* n = q.front();
                q.pop();
                if (i+1==size)
                    n->next = NULL;
                else{
                    Node* p = q.front();
                    n->next = p;
                }
                
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);     
            }
        }
        
        return root;
    }
};

//Fastest
class Solution {
public:
    Node* connect(Node* root) {
         if(!root)
            return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node* prev=NULL;
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                Node *curr=q.front();
                q.pop();
                if(prev)
                {
                    prev->next=curr;
                }
                prev=curr;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            prev->next=NULL;
        }
        return root;
    }
};