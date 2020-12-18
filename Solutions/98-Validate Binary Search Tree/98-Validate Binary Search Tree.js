//Third fastest
var isValidBST = function(root) {
    function validate(node, min, max) {
      if (!node) return true 
      // if (min < node.val && node.val < max) return validate(node.left, min, node.val) && validate(node.right, node.val, max)
      if (min >= node.val || node.val >= max) return false
      return validate(node.left, min, node.val) && validate(node.right, node.val, max)
    }
    return validate(root, -Infinity, Infinity)
  };

//Second fastest
function do_inorder_traversal(pNode, elements) {
    if (pNode.left) {
        do_inorder_traversal(pNode.left, elements)
    }
    elements.push(pNode.val)
    if (pNode.right) {
        do_inorder_traversal(pNode.right, elements)
    }
}

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function(root) {
    let children = [];
    
    // Empty tree
    if (!root) {
        return true;
    }
    
    do_inorder_traversal(root, children);
    
    for (let i = 0; i < children.length - 1; i++) {
        if ((children[i] <= children[i-1]) || (children[i] >= children[i+1])) {
            return false;
        }
    }

    
    return true;
};

//Fastest
var isValidBST = function(root){
    if(root==null)return true;
    
    function help(root, lower, upper){
        if(root==null)return true;
        
        return (lower==null || root.val>lower)
        &&(upper==null || root.val<upper)
        && help(root.left, lower, root.val)
        && help(root.right, root.val, upper);
    }
    
    return help(root, null, null);
}
var isValidBST1 = function(root) {
    if(root==null)return true;
    
    function isGreater(root, val){
        if(root==null)return true;
        
        return root.val>val && isGreater(root.left, val)&&isGreater(root.right, val);
    }
    function isLesser(root, val){
        if(root==null)return true;
        
        return root.val<val && isLesser(root.left, val) && isLesser(root.right, val);
    }
    
    return isGreater(root.right, root.val) && isLesser(root.left, root.val) && isValidBST(root.left)&&isValidBST(root.right);
};