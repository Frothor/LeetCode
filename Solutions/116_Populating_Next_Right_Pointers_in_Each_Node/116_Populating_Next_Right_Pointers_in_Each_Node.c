/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void connect_left_to_right(struct Node* left, struct Node* right)
{
    if (left && right) {
        left->next = right;
        connect_left_to_right(left->right, right->left);
    }
}

struct Node* connect(struct Node* root)
{
    if (root) {
        connect_left_to_right(root->left, root->right);
        connect(root->left);
        connect(root->right);
    }
    return root;
}

//Second fastest
#if 0
static void connect_two_node(struct Node* node1, struct Node* node2) {
	if (node1 == NULL || node2 == NULL) {
		return;
	}

	node1->next = node2;

	connect_two_node(node1->left, node1->right);
	connect_two_node(node2->left, node2->right);
	//连接不同父节点的两个点
	connect_two_node(node1->right, node2->left);
}
#endif

struct Node* connect(struct Node* root) {
#if 0
	if (root == NULL) {
		return NULL;
	}

	connect_two_node(root->left, root->right);
	return root;
#else
	if (root == NULL) {
		return NULL;
	}

	struct Node *head = root;
	while (head->left != NULL) {
		struct Node *p;
		for (p = head; p != NULL; p = p->next) {
			p->left->next = p->right;
			p->right->next = p->next == NULL ? NULL : p->next->left;
		}
		head = head->left;
	}

	return root;
#endif
}

//Fastest
void connect_left_to_right(struct Node* left, struct Node* right)
{
    if (left && right) {
        left->next = right;
        connect_left_to_right(left->right, right->left);
    }
}

struct Node* connect(struct Node* root)
{
    if (root) {
        connect_left_to_right(root->left, root->right);
        connect(root->left);
        connect(root->right);
    }
    return root;
}