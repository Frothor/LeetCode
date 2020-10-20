class Solution {
public:
    // our initial blank slate
    Node* nodes[101] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    void createNode(Node *originalNode) {
        // checking if we already created that node
		if (!nodes[originalNode->val]) {
            nodes[originalNode->val] = new Node(originalNode->val);
        }
		// adding neighbours
        for (auto n: originalNode->neighbors) {
            // checking if the neighbour exist, otherwise we create it
            if (!nodes[n->val]) createNode(n);
            // adding the neighbour
            nodes[originalNode->val]->neighbors.push_back(nodes[n->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if (node) createNode(node);
        return nodes[1];
    }
};

//Secomd fastest
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node -> val, {});
            for (Node* neighbor : node -> neighbors) {
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};

//Fastest
class Solution {
public:
    unordered_map<int, Node*> nodeMap;
    Node* cloneGraph(Node* node) {
        if(node == NULL) {
            return NULL;
        }
        if(nodeMap.find(node->val) != nodeMap.end()) {
            return nodeMap[node->val];
        }
        Node* newNode = new Node(node->val);
        nodeMap[node->val] = newNode;  // should put into map before copy neighbor
                                       // neighbor can habe this node as neighbor !!!
        for(auto neighbor : node->neighbors) {
            Node* newNeighbor = cloneGraph(neighbor);
            newNode->neighbors.push_back(newNeighbor);
        }
        return newNode;
    }
};