/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return encode(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        TreeNode* root = NULL;
        
        while (getline (ss, item, '-')) 
            root = insert(root, stoi(item));

        return root;
    }
    
private:
    string encode(TreeNode* root) {
        if (!root)
            return "";
        return to_string(root->val) + "-" + encode(root->left)+encode(root->right);
    }
    
    TreeNode* insert(TreeNode* root, int val) {
        if (root == NULL) {
			TreeNode* temp=new TreeNode(val);
			return temp;
		}
    
		if (val<=root->val)
			root->left=insert(root->left,val);
    
		else
			root->right=insert(root->right,val);
    
		return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;


//Most common
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         ostringstream os;
         serialize(root, os);
         return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserialize(is);
    }
    
    void serialize(TreeNode* root, ostringstream& os) {
        if (!root) os << "# ";
        else {
            os << root->val << " ";
            serialize(root->left, os);
            serialize(root->right, os);
        }
    }
    
    TreeNode* deserialize(istringstream& is) {
        string val = "";
        is >> val;
        if (val == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserialize(is);
        node->right = deserialize(is);
        return node;
    }
};


//Third fastest
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "N";      
        stringstream ss {};
        ss << root->val << ' ';
        deque<TreeNode*> bfs{root};
        while(bfs.size()){
            TreeNode* node = bfs.front();
            bfs.pop_front();            
            if(node->left == nullptr) ss << "N ";
            else{
                ss << node->left->val << ' ';
                bfs.push_back(node->left);
            }
            if(node->right == nullptr) ss << "N ";
            else{
                ss << node->right->val << ' ';
                bfs.push_back(node->right);
            }
        }
        cout << ss.str();
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == 'N') return nullptr;
        int val = 0;
        int pos = 0;
        while(data[pos]!=' ') val = val*10+data[pos++]-'0';
        pos++;
        TreeNode *root = new TreeNode(val);
        deque<TreeNode*> bfs{root};
        while(bfs.size()){
            TreeNode* head = bfs.front();
            bfs.pop_front();
            if(data[pos] != 'N'){
                val = 0;                
                while(data[pos]!=' ') val = val*10+data[pos++]-'0';
                pos++;
                head->left = new TreeNode(val);
                bfs.push_back(head->left);
            }
            else{
                head->left = nullptr;
                pos+=2;
            }
            if(data[pos] != 'N'){
                val = 0;                
                while(data[pos]!=' ') val = val*10+data[pos++]-'0';
                pos++;
                head->right = new TreeNode(val);
                bfs.push_back(head->right);
            }
            else{
                head->right = nullptr;
                pos+=2;
            }
        }
        return root;
    }
};

//Second fastest
class Codec {
public:

    // Encodes a tree to a single string.
    
    int getVal(string str) {
        int answer=0;
        reverse(str.begin(), str.end());
        int base=1;
        for(int i=0; i<str.size(); i++) {
            answer+=(str[i]-'0')*base;
            base*=10;
        }
        return answer;
    }
    
    string serialize(TreeNode* root) {
        string str = "";
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()) {
            auto top = q.front();
            if(top==NULL) {
                str+="null,";
            } else {
                str+=to_string(top->val)+",";
                q.push(top->left);
                q.push(top->right);
            }
            q.pop();
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<pair<TreeNode*, bool>>q;
        string temp;
        TreeNode* root = NULL;
        TreeNode* tep;
        int i=0;
        while(i<data.size()) {
            // cout<<temp<<'\n';
            if(data[i]==',') {
                if(temp=="null")
                    tep=NULL;
                else
                    tep = new TreeNode(stoi(temp));
                if(q.size()==0) {
                    root = tep;
                } else {
                    auto front = q.front();
                    q.pop();
                    if(front.second)
                        front.first->left=tep;
                    else
                        front.first->right = tep;
                }
                if(tep) {
                    q.push({tep, true});
                    q.push({tep, false});
                }
                temp = "";
                i++;
            } else {
                temp+=data[i++];
            }
        }
        return root;
    }
};

//Fastest
class Codec {
    public:

        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            ostringstream out;
            mySerialize(root, out);
            return out.str();
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            if (data == "") {
                return NULL;
            }

            istringstream in(data);
            return myDeserialize(in);
        }
    private:
        void mySerialize(TreeNode* root, ostringstream& out) {
            if (root == NULL) {
                return;
            }

            out << root->val << " ";
            mySerialize(root->left, out);
            mySerialize(root->right, out);
        }

        TreeNode* myDeserialize(istringstream& in) {
            string val;
            in >> val;
            TreeNode* root = new TreeNode(stoi(val));

            while (in >> val) {
                buildTree(root, stoi(val));
            }

            return root;
        }

        void buildTree(TreeNode* root, int n) {
            if (root->val > n) {
                if (root->left == NULL) {
                    root->left = new TreeNode(n);
                }

                else {
                    buildTree(root->left, n);
                }

            } else {
                if (root->right == NULL) {
                    root->right = new TreeNode(n);
                }

                else {
                    buildTree(root->right, n);
                }
            }
        }
};