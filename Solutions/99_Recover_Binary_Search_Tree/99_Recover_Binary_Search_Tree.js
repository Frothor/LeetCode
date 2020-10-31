/*
The Idea
1. In-order dfs traverse the tree in ascending order (very Important)
2. Save a record of the previous node, if the current node is smaller than the previous node, that means we've found 2 potential elements that will be swapped.
3. Out of the 2 potential elements, we are sure that the bigger one must be swapped, however, the smaller one aren't sure, so we need to continue the dfs.
*The idea of the swapping mechanism is exactly the same in "sorting an almost sorted array"
*/

var recoverTree = function(root) {
    let prev = null, big = null, small = null;
    let dfs = function(root) {
        if (!root) return;
        dfs(root.left);
        if (prev != null && prev.val > root.val) {
            small = root; // potential smaller number that needs to be swapped
            if (!big) big = prev; // assured bigger number that needs to be swapped
            else return;
        }
        prev = root;
        dfs(root.right);
    }
    
    dfs(root);
    [big.val, small.val] = [small.val, big.val];
};

//Third fastest
var recoverTree = function(root) {
    if(!root) return root
    let list = inorder(root)
    let list_val = list.map((v)=>v.val)
    list_val.sort((a,b)=>a-b)
    for(let i = 0;i<list.length;i++){
        list[i].val = list_val[i]
    }
    return root
};

function inorder(root, arr=[]){
    if(root){
        inorder(root.left, arr)
        arr.push(root)
        inorder(root.right, arr)
    }
    return arr
}

//Second fastest
var recoverTree = function(root) {
    let first = null, second = null, prev = new TreeNode(-Infinity);
    // inorder(root);
    inorder2(root);
    let tmp = first.val;
    first.val = second.val;
    second.val = tmp;
    
    function inorder2(root) {
      const s = [];
      let p = root;
    
      while(s.length || p) {
        if (p) {
          s.push(p);
          p = p.left;
        } else {
          const node = s.pop();
          if (prev && prev.val >= node.val) {
              if(!first) {
                first = prev;
              }
            second = node;
          }
  
          p = node.right;
          prev = node;
        }
      }
    }
    
  };
  

//Fastest
var recoverTree = function(root) {
    let firstNode = null, secondNode = null, prevNode = null
    
    const findSegments = (root) => {
        if (root == null) return
        findSegments(root.left)
        if (prevNode  && prevNode.val > root.val) {
            if (!firstNode )
                firstNode = prevNode
            secondNode = root
        }
        prevNode = root
        findSegments(root.right)
    }
    
    findSegments(root)
    let x = firstNode.val
    firstNode.val = secondNode.val
    secondNode.val = x
    
};