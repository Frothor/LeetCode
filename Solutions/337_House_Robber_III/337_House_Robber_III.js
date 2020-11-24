//https://leetcode.com/problems/house-robber-iii/discuss/495936/JavaScript-DFS-with-Memo
var rob = function(root) {
    return robImpl(root, new Map());
};

function robImpl(node, memo) {
    if (node == null) {
        return 0;
    } else if (memo.has(node)) {
        return memo.get(node);
    }
    
    const res = Math.max(node.val + 
             (node.left != null ? robImpl(node.left.left, memo) : 0) +
             (node.left != null ? robImpl(node.left.right, memo) : 0) +
             (node.right != null ? robImpl(node.right.left, memo) : 0) +
             (node.right != null ? robImpl(node.right.right, memo) : 0),
             robImpl(node.left, memo) + 
             robImpl(node.right, memo));
    memo.set(node, res);
    return res;
}

//Fastest
const memo = new Map()
var rob = function(root) {
    if(memo.has(root)) return memo.get(root)
    if(!root){
        memo.set(root, 0)
        return 0
    }
    
    let notRobRoot = rob(root.left) + rob(root.right)
    
    let robRoot = root.val
    robRoot += root.right? rob(root.right.right)+rob(root.right.left) : 0
    robRoot += root.left? rob(root.left.right)+rob(root.left.left) : 0
    
    const result = Math.max(notRobRoot, robRoot)
    memo.set(root, result)
    return result
};