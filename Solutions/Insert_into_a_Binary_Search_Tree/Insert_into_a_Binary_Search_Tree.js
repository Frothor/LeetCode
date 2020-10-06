var insertIntoBST = function (root, val) {
  function recurse(node) {
    if (!node) return new TreeNode(val);
    if (val > node.val) node.right = recurse(node.right);
    else node.left = recurse(node.left);
    return node;
  }
  return recurse(root);
};

//Second fastest
var insertIntoBST = function (root, val) {
  if (!root) {
    return new TreeNode(val);
  }
  if (root.val >= val) {
    root.left = insertIntoBST(root.left, val);
  } else {
    root.right = insertIntoBST(root.right, val);
  }
  return root;
};

//Fastest
var insertIntoBST = function (root, val) {
  let current = root;

  if (!root) {
    root = new TreeNode(val, null, null);
    return root;
  }

  while (true) {
    if (val < current.val) {
      if (current.left) {
        current = current.left;
      } else {
        current.left = new TreeNode(val, null, null);
        return root;
      }
    } else if (val > current.val) {
      if (current.right) {
        current = current.right;
      } else {
        current.right = new TreeNode(val, null, null);
        return root;
      }
    }
  }
};
