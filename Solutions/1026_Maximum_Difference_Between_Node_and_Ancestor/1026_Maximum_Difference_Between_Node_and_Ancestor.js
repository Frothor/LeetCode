var maxAncestorDiff = function (root) {
    let result = 0;
    function helper(root, max, min) {
        if (!root) {
            if (result < max - min) {
                result = max - min;
            }
            return;
        }
        if (root.val > max) {
            max = root.val
        }
        if (root.val < min) {
            min = root.val
        }
        helper(root.left, max, min);
        helper(root.right, max, min);
    }
    helper(root, root.val, root.val);
    return result;
};

//Third fastest
var maxAncestorDiff = function(root) {
    if(!root) return 0;
    let result = 0;
    
    const dfs = (root, min, max) => {
        if(!root){
            result = Math.max(result, max - min);
        } else {
            max = Math.max(root.val, max);
            min = Math.min(root.val, min);
            dfs(root.left, min, max);
            dfs(root.right, min, max);
        }
    };
    
    dfs(root, Infinity, -Infinity);
    
    return result;
};

//Second fastest
var maxAncestorDiff = function(root) {
    
    var rst = -1;
    if(root) traverse(root);
    return rst;
    
    function traverse(root){
        let [min,max,lmin,lmax]=[root.val,root.val,root.val,root.val];
        if(root.left){
            [lmin,lmax]=traverse(root.left);
            min = Math.min(min,lmin);
            max = Math.max(max,lmax);
        } 
        if(root.right){
            [lmin,lmax]=traverse(root.right);
            min = Math.min(min,lmin);
            max = Math.max(max,lmax);
        }
        rst = Math.max(rst,Math.abs(root.val-min),Math.abs(root.val-max));
        return [min,max];
    }
};

//Fastest
var maxAncestorDiff = function(root) {
    let diff = -Infinity;
    
    let iterate = (root, max, min) => {
        if(!root) {
            if(diff < max - min) {
                diff = max - min;
            }
            return;
        }

        if(root.val > max) {
            max = root.val
        }
        
        if(root.val < min) {
            min = root.val
        }
        
        iterate(root.left, max, min)
        iterate(root.right, max, min)
    }
    
    iterate(root, root.val, root.val);
    
    return diff;
};