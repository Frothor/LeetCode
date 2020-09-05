const getAllElements = (root1, root2) => {
  const arr1 = [];
  const arr2 = [];
  traversal(root1, arr1);
  traversal(root2, arr2);
  const ret = [];
  let idx1 = idx2 = 0;
  while (idx1 < arr1.length && idx2 < arr2.length) {
    arr1[idx1] < arr2[idx2] ? ret.push(arr1[idx1++]) : ret.push(arr2[idx2++]);
  }
  while (idx1 < arr1.length) ret.push(arr1[idx1++]);
  while (idx2 < arr2.length) ret.push(arr2[idx2++]);
  return ret;

  function traversal(node, arr) {
    if (!node) return;
    traversal(node.left, arr);
    arr.push(node.val);
    traversal(node.right, arr);
  }
};


const traversal = (node, arr = []) => {
  if (node) {
    traversal(node.left, arr);
    arr.push(node.val);
    traversal(node.right, arr);
  }
  return arr;
};
const merge = (arr1, arr2) => {
  const ret = [];
  let idx1 = idx2 = 0;
  while (idx1 < arr1.length && idx2 < arr2.length) {
    arr1[idx1] < arr2[idx2] ? ret.push(arr1[idx1++]) : ret.push(arr2[idx2++]);
  }
  while (idx1 < arr1.length) ret.push(arr1[idx1++]);
  while (idx2 < arr2.length) ret.push(arr2[idx2++]);
  return ret;
};
const getAllElements = (root1, root2) => merge(traversal(root1), traversal(root2));

//Fastest
var getAllElements = function(root1, root2) {
    const stack1 = []; 
    const stack2 = []; 
    
    const output = []; 
    
    while (root1 !== null || root2 !== null || stack1.length > 0 || stack2.length > 0) {
        while (root1 !== null) {
            stack1.push(root1); 
            root1 = root1.left; 
        }
        while (root2 !== null) {
            stack2.push(root2); 
            root2 = root2.left; 
        }
        
        if (stack2.length === 0 || stack1.length > 0 && stack1[stack1.length-1].val <= stack2[stack2.length-1].val) {
            root1 = stack1.pop(); 
            output.push(root1.val); 
            root1 = root1.right; 
        } else {
            root2 = stack2.pop(); 
            output.push(root2.val); 
            root2 = root2.right; 
        }
    }
    return output; 
};