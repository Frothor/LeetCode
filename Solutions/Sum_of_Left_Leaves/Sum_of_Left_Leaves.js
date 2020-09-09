//DFS

function sumOfLeftLeaves(node, isLeft = false) {
  if (!node) {
    return 0;
  }
  if (isLeft && !node.left && !node.right) {
    return node.val;
  }
  let sum = 0;
  sum += sumOfLeftLeaves(node.left, true);
  sum += sumOfLeftLeaves(node.right, false);
  return sum;
}

//BFS
function sumOfLeftLeaves(root) {
  if (!root) return 0;
  return bfs([], [root], 0);

  function bfs(leftNodes, rightNodes, sum) {
    if (!leftNodes.length && !rightNodes.length) {
      return sum;
    }
    const newLeftNodes = [], newRightNodes = [];
    for (let node of leftNodes) {
      if (!node.left && !node.right) sum += node.val;
      node.left && newLeftNodes.push(node.left);
      node.right && newRightNodes.push(node.right);
    }
    for (let node of rightNodes) {
      node.left && newLeftNodes.push(node.left);
      node.right && newRightNodes.push(node.right);
    }
    return bfs(newLeftNodes, newRightNodes, sum);
  }
}