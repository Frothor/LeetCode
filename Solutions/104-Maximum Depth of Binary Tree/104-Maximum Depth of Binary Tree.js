//Fourth fastest
var maxDepth = function(root) {
    if(!root) return 0;
    let maxDepth = 1; // 
    
    const dfs = (root, depth) => {
        if(root) depth++;
        if(root.left) {
          dfs(root.left, depth);  
        } 
        if(root.right) {
            dfs(root.right, depth);
        }
        maxDepth = Math.max(maxDepth, depth)
    }
    
    dfs(root, 0);
    return maxDepth;
};

//Third fastest
var maxDepth = function(root) {
    // input validation
    if (!root) return 0;
    
    return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
};

//Second fastest
var maxDepth = function(root) {
    
    if(root === null) return 0;
    
    return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
};

//Fastest
var maxDepth = function(root) {
  if(!root) {
      return 0;
  }  
    return 1 + Math.max(maxDepth(root.left),maxDepth(root.right));
};