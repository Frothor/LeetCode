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
 * @return {number}
 */

//Fourth fastest
var minDepth = function(root) {    
    if(root === null) {
        return 0;
    }
    if (root.left === null && root.right === null) {
      return 1;
    }
    let minimumDepth = Number.MAX_VALUE;
    if(root.left !== null) {
        let leftDepth = minDepth(root.left);
        minimumDepth = Math.min(leftDepth, minimumDepth);
    }
    if(root.right !== null) {
        let rightDepth = minDepth(root.right);
        minimumDepth = Math.min(rightDepth, minimumDepth);
    }
    return minimumDepth+1;
   
};

//Third fastest
var minDepth = function(root) {
    if (!root) return 0
    if (!root.left && !root.right) return 1

    let depth = Number.MAX_SAFE_INTEGER

    if (root.left) {
        depth = Math.min(minDepth(root.left), depth)
    }

    if (root.right) {
        depth = Math.min(minDepth(root.right), depth)
    }

    return depth + 1
};

//Second fastest
var minDepth = function(root) {
    if (!root) return 0;
     let queue = [] 
    queue.push(root)
    let minDepth = 0;
    while(queue.length > 0){
        minDepth++ 
        let level = queue.length
      for(let i = 0; i < level; i++){
          let node = queue.shift()
          
          if(!node.left  && !node.right ){
              return minDepth
          }
          
           if(node.right !== null){
              queue.push(node.right)
          }
          if(node.left !== null){
              queue.push(node.left)
          }
          
      }
    }
    return minDepth
};

//Fastest
var minDepth = function(root) {
    if (!root)  return 0;
    
    let depth = 1
    let queue = [root]
    while (queue.length > 0) {
        let len = queue.length
        for (let i = 0; i < len; i++) {
            let node = queue.shift()
            if (node === null) return 0
            if (node.left === null && node.right === null) return depth
            if (node.left !== null) queue.push(node.left)
            if (node.right !== null) queue.push(node.right)
        }
        depth++
    }
    return depth
};