// Iterative Solution
var inorderTraversal = function(root) {
    if (!root) return [];
    let stack = [], res = [];
    stack.push(root);
    while (stack.length) {
        let node = stack[stack.length-1];
        if (node.left) {
            stack.push(node.left);
            node.left = null;
        }
        else {
            res.push(stack.pop().val);
            if (node.right) stack.push(node.right);    
        }
    }
    return res;
    // Time Complexity: O(n)
    // Space Complexity: O(n)
};

//Third fastest
var inorderTraversal = function(root) {
    const arr = []
  const helper = (root) => {
   if (!root) return;
 
  helper(root.left);
     arr.push(root.val);
  helper(root.right); 
  }
  helper(root);
  return arr;
};

//Second fastest
function traverse(root, arr) {
    if(root.left) { traverse(root.left, arr) }
    arr.push(root.val)
    if (root.right) { traverse(root.right, arr) }
}

var inorderTraversal = function(root) {
    let result=[]
    
    if (root) { traverse(root, result) }
    
    return result
};

//Fastest
var inorderTraversal = function(root) {
    return getValues(root, []);
};

var getValues = function(root, arr){
    if(root == null || root.val == 0) return arr;
    var left = getValues(root.left, arr);
    
    var right = getValues(root.right, arr);
    return left.concat([root.val]).concat(right);
}