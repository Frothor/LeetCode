//Third fastest
const inOrderTraversal = (node, result) => {
    if(node) {
        inOrderTraversal(node.left, result);
        result.push(node.val)
        inOrderTraversal(node.right, result);
    }
}

const constructTree = (arr) => {
    const root = new TreeNode(null);
    let current = root;
    
    for(let i = 0; i < arr.length; i++) {
        current.right = new TreeNode(arr[i])
        current = current.right;
    }
    return root.right;
    
}

var increasingBST = function(root) {
    const result = [];
    inOrderTraversal(root, result);
    return constructTree(result);
};

//Second fastest
  function TreeNode(val, left, right) {
      this.val = (val===undefined ? 0 : val)
      this.left = (left===undefined ? null : left)
      this.right = (right===undefined ? null : right)
  }

var increasingBST = function(root) {
    let ans = new TreeNode();
    let curr = ans;
    const inorder = node => {
        if (!node) return;
        inorder(node.left);
        curr.right = new TreeNode(node.val);
        curr = curr.right;
        inorder(node.right);
    }
    inorder(root);
    return ans.right;
};

//Fastest
const increasingBST = root => {
    if (!root) return null
    const head = new TreeNode()
    let curr = head
    const traverse = node => {
        if (!node) return null
        traverse(node.left)
        const n = new TreeNode(node.val)
        curr.right = n
        curr = curr.right
        traverse(node.right)
    }
    traverse(root)
    return head.right
}