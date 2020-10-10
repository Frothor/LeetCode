//Fourth fastest
var serialize = function(root) {
    let preorder = [];
    let dfs = function(node) {
        if (node==null) return;
        preorder.push(node.val);
        dfs(node.left);
        dfs(node.right);
    }
    dfs(root);
    return preorder.join(',');
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    if (data == '') return null;
    let preorder = data.split(',');
        let recur = function(lower, upper) {
        if (Number(preorder[0]) < lower || Number(preorder[0]) > upper) return null;
        if (preorder.length == 0) return null;
        let root = new TreeNode(preorder.shift());
        root.left = recur(lower, root.val);
        root.right = recur(root.val, upper);
        return root;
    }
    return recur(-Infinity, Infinity);
};


//Third fastest
function serialize (root) {
    const res = []
    helper(root)
    return res.join(',')
  
    function helper (node) {
      if (!node) return
  
      res.push(node.val)
      helper(node.left)
      helper(node.right)
    }
  }
  function deserialize (data) {
    if (!data) {
      return null
    }
    return helper(data.split(','), Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY)
  
    function helper (queue, lower, upper) {
      if (!queue.length) {
        return null
      }
      const val = +queue[0]
      if (val < lower || val > upper) {
        return null
      }
      queue.shift()
      const root = new TreeNode(val)
      root.left = helper(queue, lower, val)
      root.right = helper(queue, val, upper)
      return root
    }
  }

//Second fastest
var serialize = function(root) {
    if (root == null) return "";
    
    const res = [];

    postOrderTraversal(root);

    return res.join("#");
    
    function postOrderTraversal(node) {
        if (node) {
            postOrderTraversal(node.left);
            postOrderTraversal(node.right);       
            res.push(node.val);
        }
    }
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    if (data == "") return null;
    
    const nums = data.split("#");
    let index = nums.length - 1;

    return preorderTraversal(Number.MIN_SAFE_INTEGER, Number.MAX_SAFE_INTEGER);
    
    function preorderTraversal(lowerBound, upperBound) {
        if (index < 0) return null;
        
        const currNum = parseInt(nums[index]);
        
        if (currNum < lowerBound || currNum > upperBound) return null;
        
        const root = new TreeNode(currNum);
        index--;
        
        root.right = preorderTraversal(currNum, upperBound);
        root.left = preorderTraversal(lowerBound, currNum);
    
        return root;
    }
};


//Fastest
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    const str = [];
    
    postOrderTraversal(root);
    
    return str.join("#");
    
    function postOrderTraversal(node) {
        if (node) {
            postOrderTraversal(node.left);
            postOrderTraversal(node.right);
            str.push(node.val);
        }
    }
    

};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    if (data.length == 0) return null;
    
    const nums = data.split("#");

    let index = nums.length - 1;
    
    return postOrderTraversal(Number.MIN_SAFE_INTEGER, Number.MAX_SAFE_INTEGER);
    
    function postOrderTraversal(lowerBound, upperBound) {
        if (index < 0) return null;
        if (lowerBound > upperBound) return null;
        
        const curr_val = parseInt(nums[index]);
        
        if (curr_val < lowerBound || curr_val > upperBound) return null;
        
        const curr_node = new TreeNode(curr_val);
        index--;
        
        curr_node.right = postOrderTraversal(curr_val, upperBound);
        curr_node.left = postOrderTraversal(lowerBound, curr_val);
        
        return curr_node;
    }

};

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */