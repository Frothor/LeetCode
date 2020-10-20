//Third fastest
var cloneGraph = function(node) {
    const visited = new Set()
    if (!node) {
        return null
    }
    const queue = [node]
    
    const nodeMap = { [node.val]: new Node(node.val, []) }
    
    while (queue.length > 0) {
        const n = queue.pop()
        if (visited.has(n.val)) {
            continue
        }
        
        visited.add(n.val)
        
        for (const neighbor of n.neighbors) {
            if (!(neighbor.val in nodeMap)) {
                nodeMap[neighbor.val] = new Node(neighbor.val, [])
            }
            nodeMap[n.val].neighbors.push(nodeMap[neighbor.val])
            queue.push(neighbor)
        }
    }
    
    return nodeMap[node.val]
};

//Second fastest
var cloneGraph = function(node) {
    if (!node) return node;
    return collectAllNodes(node).get(node.val);
};

function collectAllNodes(node, results = new Map()) {
    
    if (!results.has(node.val)) {
        let cloned = new Node(node.val);
        results.set(node.val, cloned);
        
        for (let neighbor of node.neighbors) {
            collectAllNodes(neighbor, results);
            cloned.neighbors.push(results.get(neighbor.val))
        }
    }
    
    return results;
    
}

//Fastest
/**
 * // Definition for a Node.
 * function Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {Node} node
 * @return {Node}
 */
var cloneGraph = function(node, map = new Map()) {
  if (!node) return node;
  if (map.has(node)) return map.get(node);
  const newNode = new Node(node.val);
  map.set(node, newNode);
  node.neighbors.forEach(el => {
    newNode.neighbors.push(cloneGraph(el, map));
  });
  return newNode;
};