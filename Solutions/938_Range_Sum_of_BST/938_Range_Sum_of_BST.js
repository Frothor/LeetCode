//Fourth fastest
var rangeSumBST = function(root, L, R) {
    let sum = 0;
    function calSum(node) {
        if(node != 0 && node.val >= L && node.val <=R){
            sum+= node.val
        }
        if( node.val <= R && node.right != null)
        calSum(node.right);
        if(node.val >= L && node.left != null)
        calSum(node.left)
    }
    calSum(root);
    return sum;
    
};

//Third fastest
var rangeSumBST = function(root, L, R) {
    let sum = 0;
     traverse(root);
     return sum;
     
     function traverse(node) {
         
         if(!node) {
             return;
         }
         
         if(node.val < L) {
             traverse(node.right);
             return;
         }
         
         if(node.val > R) {
             traverse(node.left);
             return;
         }
         
         sum+= node.val;
         traverse(node.right)
         traverse(node.left)
         
         
     }
 };
 
 //need to traverse the bst
 
 //check if the node is greater =  than L
 //check if the node is less or = to R
 // add to L

//Second fastest
var rangeSumBST = function(root, L, R) {
    // travere by inorder -> sorted result
    let stack = [root];
    let result = [];
    while (stack.length) {
      let cur = stack.pop();
      result.push(cur.val);
      cur.left && stack.push(cur.left);
      cur.right && stack.push(cur.right);
    }
    return result.reduce((acc, cur) => {
      if (L <= cur && cur <= R) {
        return acc + cur;
      }
      return acc;
    }, 0);  
  };

//Fastest
var rangeSumBST = function(root, L, R) {
    let total=0
    const search=(node)=>{
    if (!node)return 0
    if(node.val>=L){
       if(node.val<=R){
           total+=node.val
       }
    }
   node.val>L && search(node.left)
   node.val<R && search(node.right)
    }
    search(root)
    return total
}