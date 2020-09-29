* Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxPathSum = function(root) {
    if(!root) {
        return 0;
    }
    
    const globalMaxSum = {
        value: -Infinity
    };
    maxPathSumRecursive(root, globalMaxSum);
    return globalMaxSum.value;
};

var maxPathSumRecursive = function(currentNode, globalMaxSum) {
    if(currentNode === null) {
        return 0;
    }
    // Find max path sum at left and right subtrees
    let maxPathSumFromLeft = maxPathSumRecursive(currentNode.left, globalMaxSum);
    let maxPathSumFromRight = maxPathSumRecursive(currentNode.right, globalMaxSum);
    
	// ignore path sums which are negative, as we are searching for max global path sum
    maxPathSumFromLeft = Math.max(maxPathSumFromLeft, 0);
    maxPathSumFromRight = Math.max(maxPathSumFromRight, 0);
    
	// Math Path Sum at current node would be maxLeft + maxRight + currentNodeValue
    let localMaxPathSum = maxPathSumFromLeft + maxPathSumFromRight + 
                            currentNode.val;
    
    globalMaxSum.value = Math.max(globalMaxSum.value, localMaxPathSum);
    
	// Return the max that can be achieved at this subtree (= max(leftPathSum, rightPathSum) + currentNodeValue
    return Math.max(maxPathSumFromLeft, maxPathSumFromRight) + currentNode.val;
}

/*
I recommend building up from basic examples. Once you build your program bottom-up, you can start to verify the program.

1. no node
2. single node [1]
3. two nodes [1,2]
4. three nodes [1,2,3]
5. four nodes [4,null,1,null,null,2,3]
6. negative numbers [-1, 2]
*/
var maxPathSum = function(root) {
	let max = -Infinity
	note(root)
	return max
	
		function note(node) {
			if(node === null) return 0
			let left = Math.max(note(node.left), 0)
			let right = Math.max(note(node.right), 0)
			let currMax = right + node.val + left 
			if(currMax > max) max = currMax
			return node.val + Math.max(left, right)
		}
};