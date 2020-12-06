//Fourth fastest
var connect = function(root) {
  if(!root) return root;
  
  // bfs
  let q = [root];
  
  while(q.length > 0){
    let len = q.length;
    for(let i = 0; i < len; i++){
      let currNode = q.shift();
      
      if(i < len-1){
        currNode.next = q[0]
      } else {
        currNode.next = null
      }
      
      if(currNode.left) q.push(currNode.left);
      if(currNode.right) q.push(currNode.right);
    }
  }
  
  return root;
};

//Third fastest
var connect = function(root) {
    var leftmost = root;
    while (leftmost != null) {
        var curr = leftmost; // traverse level above, and connect level below
        var next = null; // next leftmost
        var prev = null; // prev in level below
        
        while (curr) {
            if (curr.left) {
                if (!prev) {
                    next = curr.left;
                    prev = next;
                } else {
                    prev.next = curr.left;
                    prev = prev.next;
                }
            }
            
            if (curr.right) {
                if (!prev) {
                    next = curr.right;
                    prev = next;
                } else {
                    prev.next = curr.right;
                    prev = prev.next;
                }
            }
            
            curr = curr.next;
        }
        
        leftmost = next;
    }
    
    return root;
};

//Second fastest
var connect = function(root) {
    var stack = [null]
    var curr = root
    var prev
    var left
    
    while(stack.length){
        left = null
        prev = null
        while(curr !== null){
            if(curr.left !== null){
                stack.unshift(curr.left)
                if(prev === null){
                    prev = curr.left
                    left = curr.left
                }else{
                    prev.next = curr.left
                }
                prev = curr.left
            }
            if(curr.right !== null){
                stack.unshift(curr.right)
                if(prev === null){
                    prev = curr.right
                    left = curr.right
                }else{
                    prev.next = curr.right
                }
                prev = curr.right
            }
            curr = stack.pop()
                        
        }
        if(stack.length && stack[0] !== null){
            stack.unshift(null)
        }
        curr = stack.pop()
    }
    
    return root
    
};

//Fastest
var connect = function(root) {
    if(!root) return root
    
    let queue = [root]
    
    while(queue.length){
        let size = queue.length
    
        for(let i = 0; i < size; i++){
            let current = queue.shift()
            
            if(i < size - 1) current.next = queue[0]
            
            if(current.left) queue.push(current.left)
            if(current.right) queue.push(current.right)
        }
    }
    return root
};