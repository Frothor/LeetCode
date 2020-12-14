//https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/discuss/969896/JavaScript-TypeScript-Solution
//Third fastest
var subtreeWithAllDeepest = function (root) {
  if (!root) return root;

  const left = getDepth(root.left);
  const right = getDepth(root.right);

  if (left > right) {
    return subtreeWithAllDeepest(root.left);
  }

  if (left < right) {
    return subtreeWithAllDeepest(root.right);
  }

  return root;
};

const getDepth = (node) => {
  if (!node) return 0;

  const left = getDepth(node.left);
  const right = getDepth(node.right);

  return Math.max(left, right) + 1;
};

//Another
var subtreeWithAllDeepest = function(root) {   
    return dfs(root, 0)[0];        
};


function dfs(root, depth) {
    if(root == null) return [null, depth];
    
    const leftNode = dfs(root.left, depth + 1);
    const rightNode = dfs(root.right, depth + 1);
    
    if (leftNode[1] === rightNode[1]) {
        return [root, leftNode[1]];
    } else {
        return leftNode[1] < rightNode[1] ? rightNode : leftNode;
    }
};

//Second fastest
const subtreeWithAllDeepest = (root) => {
	const findLCA = (node) => {
		if (node === null) return false;
			if (node.val in hash) {
			if (maxLeaves.length === 1) LCA = node;
			return true;
		}

		var left = findLCA(node.left),
			right = findLCA(node.right);

		if (left && right) {
			LCA = node;
			return true;
		} else if (left || right) {
			return true;
		}
		return false;
	};

	const findDeepestNodes = (node, depth) => {
		if (node === null) return null;

		depth++;

		let left = findDeepestNodes(node.left, depth),
			right = findDeepestNodes(node.right, depth);

		// Is it a leaf?
		if (left === null && right === null) {
			if (depth > maxDepth) {
				maxDepth = depth;
				maxLeaves = [node];
			} else if (depth === maxDepth) {
				maxLeaves.push(node);
			}
		}

		depth--;
		return [maxDepth, maxLeaves];
	};

	var maxDepth = -1,
		maxLeaves = [];
	// Find deepest leaves or leaf
	[maxDepth, maxLeaves] = findDeepestNodes(root, -1);

	var hash = {};
	maxLeaves.forEach((leaf) => {
		hash[leaf.val] = true;
	});

	var LCA = root;
	// Find parent that has both in left and right subtree
	findLCA(root);

	return LCA;
};

//Fastest
var subtreeWithAllDeepest = function(root) {
    function _dfs(node) {
      if (!node) return new Result(null, 0);
      
      let left = _dfs(node.left);
      let right = _dfs(node.right);
      if (left.dist < right.dist) return new Result(right.node, right.dist+1);
      if (left.dist > right.dist) return new Result(left.node, left.dist+1);
      return new Result(node, left.dist+1);
    } 
    
    class Result {
      constructor(node, dist) {
        this.node = node;
        this.dist = dist;
      }
    }
    
    return _dfs(root).node;
  };