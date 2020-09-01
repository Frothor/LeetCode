//1. Find a node which has a key as a value.
//2. When current node has a key, we should remove the current node value and replace it with right prev/next node value of current node.
//    If it has left child, change current value with predecessor node value.
//    Else if it has right child, change currnt value with successor node value.
//    If it has no children, it returns null
//3. Recursively delete prev/next node we used for replacing. (If there were no children, it will be terminated.)
//Time Complexity: O(H) it depends on the height of tree
//Space Complexity: O(H)

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} node
 * @return {number}
 */
const successor = node => {
    node = node.right;
    while (node.left) {
        node = node.left;
    }
    return node.val;
}
/**
 * @param {TreeNode} node
 * @return {number}
 */
const predecessor = node => {
    node = node.left;
    while (node.right) {
        node = node.right;
    }
    return node.val;
}
/**
 * @param {TreeNode} root
 * @param {number} key
 * @return {TreeNode}
 */
var deleteNode = function(root, key) {
    if (!root) {
        return null;
    }
    if (root.val < key) {
        root.right = deleteNode(root.right, key);
    }
    else if (root.val > key) {
        root.left = deleteNode(root.left, key);
    }
    else {
        if (root.left) {
            root.val = predecessor(root);
            root.left = deleteNode(root.left, root.val);
        }
        else if (root.right) {
            root.val = successor(root);
            root.right = deleteNode(root.right, root.val);
        }
        else {
            root = null;
        }
    }
    return root;
};


//MOST COMMON
/**
 * @param {TreeNode} root
 * @param {number} key
 * @return {TreeNode}
 */
var deleteNode = function(root, key) {
    let node = root;
    return _deleteHelperVA(node, key);
};

function _deleteHelperVA(node,val) {
    if (node == null) {
        return null;
    }
    else if (val < node.val) {
        node.left = _deleteHelperVA(node.left, val);
        return node; 
    }
    else if (val > node.val) {
        node.right = _deleteHelperVA(node.right, val);
        return node;
    }
    else {
        if (node.left == null && node.right == null) {
            return null;
        }
        else if (!node.left) {
            return node.right; 
        }
        else if (!node.right) {
            return node.left; 
        }
        [node.right, minNodeSubtree] = _findMinNode(node.right);
        minNodeSubtree.left = node.left;
        minNodeSubtree.right = node.right;
        return minNodeSubtree; 
    }
}

function _findMinNode(node) {
    if (node.left == null) {
        return [node.right, node];
    }
    [node.left, minNode] = _findMinNode(node.left);
    return [node, minNode]; 

}

//FASTEST
var findParent = function(node, key) {
    
    if(key < node.val) {
        //if(node.left == null) return null;
        if(node.left.val == key) return node;
        else return findParent(node.left, key);
    }
    else if(key > node.val) {
        //if(node.right == null) return null;
        if(node.right.val == key) return node;
        else return findParent(node.right, key);
    }
};

var findNode = function(node, key) {
    if(node==null) return null;
    if(node.val == key) return node;
    else if(key < node.val) return findNode(node.left, key);
    else return findNode(node.right, key);
};

var isLeafNode = function(node) {
    return (node.left==null && node.right==null);
};

var hasRightChildOnly = function(node) {
    return (node.left==null && node.right!=null);
};

var hasLeftChildOnly = function(node) {
    return (node.left!=null && node.right==null);
};

var hasBothchildren = function(node) {
    return (node.left!=null && node.right!=null);
};

var findPredecessor = function(node) {
    node = node.left;
    while(node.right) node = node.right;
    return node;
};

var findSuccessor = function(node) {
    node = node.right;
    while(node.left) node = node.left;
    return node;
};

var deleteNode = function(root, key) {
    
    if(root==null) return null;
    
    if(key < root.val) {
        root.left = deleteNode(root.left, key);
    }
    else if(key > root.val) {
        root.right = deleteNode(root.right, key);
    }
    
    else {
        if(isLeafNode(root)) root = null;
        else if(root.left) {
            root.val = findPredecessor(root).val;
            root.left = deleteNode(root.left, root.val);
        }
        else if(root.right) {
            root.val = findSuccessor(root).val;
            root.right = deleteNode(root.right, root.val);
        }
    }
   
    return root;
};