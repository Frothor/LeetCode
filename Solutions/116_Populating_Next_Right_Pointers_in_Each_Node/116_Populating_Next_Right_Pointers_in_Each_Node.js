var connect = function(root) {
    const queue = [];
    
    if (root == null) return root;
        
    queue.push(root);
    
    while (queue.length > 0) {
        const len = queue.length;
        
        for (let i = 0; i < len; i++) {
            const node = queue.shift();
            
            if (i + 1 < len) node.next = queue[0];
                
            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }
    }
    
    return root;
};