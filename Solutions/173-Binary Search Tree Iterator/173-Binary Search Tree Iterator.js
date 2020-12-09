//Third fastest
//
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
 */
var BSTIterator = function(root) {
    this.cache = []
    const traverse = (node) => {
        if (node) {
            if (node.left) traverse(node.left)
            this.cache.push(node.val)
            if (node.right) traverse(node.right)
        }
    }
    traverse(root)
};

/**
 * @return the next smallest number
 * @return {number}
 */
BSTIterator.prototype.next = function() {
    return this.cache.shift()
};

/**
 * @return whether we have a next smallest number
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function() {
    return this.cache.length > 0
};

/** 
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */

//Another
var BSTIterator = function(root) {
    this.sortedArray = []
    let inorder = (root) =>{
        if(root === null){
            return 
        }
        
        inorder(root.left)
        this.sortedArray.push(root.val)
        inorder((root.right))
        
    }
    inorder(root)
    this.index = -1
};

/**
 * @return the next smallest number
 * @return {number}
 */
BSTIterator.prototype.next = function() {
    this.index+=1
    return this.sortedArray[this.index]
};

/**
 * @return whether we have a next smallest number
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function() {
    return this.index+1 < this.sortedArray.length
};

//Second fastest
var BSTIterator = function(root) {
    this.stack = [];
    
    if (!root) return;
    
    const traverse = node => {
        if (!node) return;
        
        traverse(node.left);
        this.stack.push(node.val);
        traverse(node.right);
    };
    traverse(root);
};

/**
 * @return {number}
 */
BSTIterator.prototype.next = function() {
    return this.stack.shift();
};

/**
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function() {
    return this.stack.length > 0;
};

 //Fastest
 var BSTIterator = function(root) {
    
    this.arr = traverse(root, [])
    this.pointer = -1
};

var traverse = function(root, arr){
    if(root==null)
        return

    traverse(root.left, arr)
    arr.push(root.val)
    traverse(root.right, arr)
    
    return arr
}


BSTIterator.prototype.next = function() {
    this.pointer++
    if(this.pointer>this.arr.length-1)
        return null
    return this.arr[this.pointer]
};


BSTIterator.prototype.hasNext = function() {
    return this.pointer+1 > this.arr.length-1 ? false : true
};