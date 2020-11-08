//Third fastest
var findTilt = function(root) {
    const tilt = { val: 0 };
    dfs(root, tilt);
    return tilt.val;
};

function dfs(root, tilt) {
    if (!root) return 0;
    let left = dfs(root.left, tilt);
    let right = dfs(root.right, tilt);
    tilt.val += Math.abs(left - right);
    return root.val + left + right;
}

//Second fastest
var findTilt = function(root, result = 0) {
    if(!root) return 0;
    function helper(node) {
      if(!node) return 0;
      let left = helper(node.left);
      let right = helper(node.right);
      result += Math.abs(left - right);
      return node.val + left + right;
    }
    helper(root);
    
    return result
  };

//Fastest
var findTilt = function(root) {
    let tilt = 0
    const subtree = (node) => {
        let left = 0
        let right = 0
        if (!node) return 0
        if (node.left) {
            left = subtree(node.left)
        }
        if (node.right) {
            right = subtree(node.right)
        }
        tilt += Math.abs(left - right)
        return (left + right + node.val)
    }
    subtree(root)
    return tilt
};