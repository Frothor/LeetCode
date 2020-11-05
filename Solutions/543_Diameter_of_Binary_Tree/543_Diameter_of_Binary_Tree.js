var diameterOfBinaryTree = function(root) {
    let diameter = 0
    if(!root) return 0
    function computeDiameter(root) {
        if(!root) {
            return 0
        }
        const d1 = computeDiameter(root.left)
        const d2 = computeDiameter(root.right)
        diameter = Math.max(diameter, d1 + d2)
        return Math.max(d1, d2) + 1
    }
    computeDiameter(root)
    return diameter
};

//Third fastest
let diameterOfBinaryTree = function(root) {
    let max = 0;

    // assume node !== null
    let postOrderDFVisit = function(node) {
        let leftHeight = 0, rightHeight = 0;
        if (node.left) {
            postOrderDFVisit(node.left);
            leftHeight = node.left.height;
        }
        if (node.right) {
            postOrderDFVisit(node.right);
            rightHeight = node.right.height;
        }

        node.height = Math.max(1 + leftHeight, 1 + rightHeight);
        node.diameter = leftHeight + rightHeight;
        if (node.diameter > max) {
            max = node.diameter;
        }
    };

    if (!root) {
        return 0;
    }

    postOrderDFVisit(root);

    return max;
};

//Second fastest
var diameterOfBinaryTree = function(root) {
    let max = 0;
    
    const dfs = (node, level) => {
        if (!node) {
            return 0;
        }
        
        const left = dfs(node.left);
        const right = dfs(node.right);
        
        max = Math.max(max, left + right);
        return Math.max(left, right) + 1;
    }
    
    dfs(root, 0);
    
    return max;
    
};

//Fastest
const diameterOfBinaryTree = root => {
    let max = 0
    const traverse = node => {
        if (!node) return 0
        const left = traverse(node.left)
        const right = traverse(node.right)
        max = Math.max(left + right, max)
        return Math.max(left, right) + 1 
    }
    traverse(root)
    return max
}