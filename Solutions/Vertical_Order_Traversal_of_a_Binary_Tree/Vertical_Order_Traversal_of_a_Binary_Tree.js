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
 * @return {number[][]}
 */
var verticalTraversal = function(root) {
    if (root == null) {
        return [];
    }
    
    const queue = [];
    
    queue.push([root, 0, 0]);
    const list = [];
    while(queue.length > 0) {
        const [node, row, column] = queue.shift();
        
        
        if (node) {
            queue.push([node.left, row + 1, column - 1])
            queue.push([node.right, row + 1, column + 1])
            list.push([node.val, row, column]);
        }
    }
  
  const compare = (a, b) => {
    if (a[2] - b[2] === 0 ) {
      
      if (a[1] - b[1] === 0) {
        return a[0] - b[0];
      }
    }
    
    return a[2] - b[2]
  }
  
   list.sort(compare)
  
  const map = new Map();
  for(let i = 0; i < list.length; i++) {
    const [value, row, column] = list[i]
    
    if (map.has(column)) {
      map.get(column).push(value)
    } else {
      map.set(column, [value]);
    }
  }
  
  return [...map.values()]
};



//Most common:
var verticalTraversal = function(root) {
    let min = 0;
    let max = 0;
    const map = new Map();
    
    (function buildMap(root, row, col) {
        if(!root) return;
        map.set(col, (map.get(col) || []).concat({row, val: root.val}));
        min = Math.min(min,col);
        max = Math.max(max, col);
        buildMap(root.left, row+1, col-1, map);
        buildMap(root.right, row+1, col+1, map);
    })(root, 0, 0)
    
    let result = [];
    for (let i = min; i <= max; i++) {
        let nodes = map.get(i);
        nodes.sort((a,b)=> {
            if(a.row !== b.row) return a.row-b.row;
            else return a.val-b.val;
        });
        let vals = nodes.map(x=>x.val);
        result.push(vals);
    }
    
    return result;
};

//Fastest:
var verticalTraversal = function(root) {
    function node(row, val) {
        return {row, val};
    }
    let min = 0;
    let max = 0;
    let map = build(root, 0,0,new Map());
    let result = [];
    for(let i=min; i<=max; i++) {
        let nodes = map.get(i);
        nodes.sort((a,b)=> {
            if(a.row !== b.row) return a.row-b.row;
            else return a.val-b.val;
        });
        let vals = nodes.map(x=>x.val);
        result.push(vals);
    }
    return result;
    
    function build(root, row, col, map) {
        if(!root) return map;
        if(!map.has(col)) map.set(col, []);
        map.get(col).push(new node(row, root.val));
        min = Math.min(min,col);
        max = Math.max(max, col);
        map = build(root.left, row+1, col-1, map);
        return build(root.right, row+1, col+1, map);
    }
};