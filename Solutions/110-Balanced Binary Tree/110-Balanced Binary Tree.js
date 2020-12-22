//Third fastest
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */


var isBalanced = function(root) {
    let result = true;
    const innerFunc = (node) => {
        if (!node) return 0;
        
        let l = innerFunc(node.left);
        let r = innerFunc(node.right);
        if (Math.abs(l - r) > 1) result = false;
        return Math.max(l, r) + 1
    }
    innerFunc(root)
    return result
};


//Second fastest
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function(root) {
    let isBalanced = true;
    
    function findHeight(root) {
        if (!root) {
            return 0
        }
        if (isBalanced === false) return; // optimisation: early exit

        let leftHeight = findHeight(root.left);
        let rightHeight = findHeight(root.right);
        let diff = Math.abs(leftHeight - rightHeight);

        if (diff > 1) {
            isBalanced = false;
        }
        
        return Math.max(leftHeight, rightHeight) + 1;
    }
    
    findHeight(root);
    return isBalanced;
};

//Fastest
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function(root) {
    let balanced = true;
    
    const depthTrav = (root) => {
        if (!root) return 0;
        if(!balanced) return;
        
        const leftHeight = depthTrav(root.left);
        const rightHeight = depthTrav(root.right);
        const heightDiff = leftHeight - rightHeight;
      
        if (heightDiff > 1 || heightDiff < -1) {
          balanced = false;
        }
        
        return Math.max(leftHeight, rightHeight) + 1;
    }
    
    depthTrav(root);
    return balanced;
}