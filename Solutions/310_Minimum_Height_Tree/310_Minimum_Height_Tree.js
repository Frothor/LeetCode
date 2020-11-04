//Third fastest
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findMinHeightTrees = function(n, edges) {
    if (edges.length === 0) {
        return [0];
    }
    var graph = [];
    // var degrees = new Map();
    let result = [];
    for (var i = 0; i < n; i++) {
        graph[i] = [];
    }
    for (let i = 0; i < edges.length; i++) {
        let edge = edges[i];
        graph[edge[0]].push(edge[1]);
        graph[edge[1]].push(edge[0]);
    }
    // for (var i = 0; i < n; i++) {
    //     graph[i] = [];
    //     for (var j = 0; j < edges.length; j++) {
    //         const edge = edges[j];
    //         if (edge[0] === i) {
    //             graph[i].push(edge[1]);
    //             // if (degrees.has(i)) {
    //             //     degrees.set(i, degrees.get(i) + 1);
    //             // } else {
    //             //     degrees.set(i, 1);
    //             // }
    //         }
    //         if (edge[1] === i) {
    //             graph[i].push(edge[0]);
    //             // if (degrees.has(i)) {
    //             //     degrees.set(i, degrees.get(i) + 1);
    //             // } else {
    //             //     degrees.set(i, 1);
    //             // }
    //         }
    //     }
    // }
    let leaves = [];
    for (let i = 0; i < graph.length; i++) {
        if (graph[i].length === 1) {
            leaves.push(i);
        }
    }
    let count = n;
    while (count > 2) {
        count -= leaves.length;
        let newLeaves = [];
        for (var i = 0; i < leaves.length; i++) {
            let leaf = leaves[i];
            let nextNodes = graph[leaf];
            // while (graph[leaf].length > 0) {
            //     let node = graph[leaf].shift();
            //     degrees.set(node, degrees.get(node) - 1);
            //     if (degrees.get(node) === 1) {
            //         newLeaves.push(node);
            //     }
            // }
            for (let j = 0; j < nextNodes.length; j++) {
                let nextNode = nextNodes[j];
                let index = graph[nextNode].indexOf(leaf);
                graph[nextNode].splice(index, 1);
                if (graph[nextNode].length === 1) {
                    newLeaves.push(nextNode);
                }
            }
        }
        if (newLeaves.length === 0) {
            result = leaves;
        }
        leaves = newLeaves;
    }
    return leaves;
};

//Second fastest
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findMinHeightTrees = function(n, edges) {
    if (edges.length === 0) {
        return [0];
    }
    var graph = [];
    // var degrees = new Map();
    let result = [];
    for (var i = 0; i < n; i++) {
        graph[i] = [];
    }
    for (let i = 0; i < edges.length; i++) {
        let edge = edges[i];
        graph[edge[0]].push(edge[1]);
        graph[edge[1]].push(edge[0]);
    }
    // for (var i = 0; i < n; i++) {
    //     graph[i] = [];
    //     for (var j = 0; j < edges.length; j++) {
    //         const edge = edges[j];
    //         if (edge[0] === i) {
    //             graph[i].push(edge[1]);
    //             // if (degrees.has(i)) {
    //             //     degrees.set(i, degrees.get(i) + 1);
    //             // } else {
    //             //     degrees.set(i, 1);
    //             // }
    //         }
    //         if (edge[1] === i) {
    //             graph[i].push(edge[0]);
    //             // if (degrees.has(i)) {
    //             //     degrees.set(i, degrees.get(i) + 1);
    //             // } else {
    //             //     degrees.set(i, 1);
    //             // }
    //         }
    //     }
    // }
    let leaves = [];
    for (let i = 0; i < graph.length; i++) {
        if (graph[i].length === 1) {
            leaves.push(i);
        }
    }
    let count = n;
    while (count > 2) {
        count -= leaves.length;
        let newLeaves = [];
        for (var i = 0; i < leaves.length; i++) {
            let leaf = leaves[i];
            let nextNodes = graph[leaf];
            // while (graph[leaf].length > 0) {
            //     let node = graph[leaf].shift();
            //     degrees.set(node, degrees.get(node) - 1);
            //     if (degrees.get(node) === 1) {
            //         newLeaves.push(node);
            //     }
            // }
            for (let j = 0; j < nextNodes.length; j++) {
                let nextNode = nextNodes[j];
                let index = graph[nextNode].indexOf(leaf);
                graph[nextNode].splice(index, 1);
                if (graph[nextNode].length === 1) {
                    newLeaves.push(nextNode);
                }
            }
        }
        if (newLeaves.length === 0) {
            result = leaves;
        }
        leaves = newLeaves;
    }
    return leaves;
};

//Fastest
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findMinHeightTrees = function(n, edges) {
    // edge case
    if (!n || n === 0 || n - 1 !== edges.length) { return []; }
    if (n === 1) { return [0]; }
    
    // calculate edges
    let hash = {};
    for (let i = 0; i < n; i++) {
        hash[i] = [];
    }
    
    for (let i = 0; i < edges.length; i++) {
        let edge = edges[i];
        hash[edge[0]].push(edge[1]);
        hash[edge[1]].push(edge[0]);
    }
    
    // remove leaves via BFS
    let leaves = [];
    let res = [];
    for (let i = 0; i < n; i++) {
        if (hash[i].length === 1) {
            leaves.push(i);
        }
    }
    
    let count = n;
    while (count > 2) {
        let size = leaves.length;
        count -= size;
        let newLeaves = [];
        for (let i = 0; i < size; i++) {
            let node = leaves.shift();
            let nextNodes = hash[node];
            for (let j = 0; j < nextNodes.length; j++) {
                let nextNode = nextNodes[j];
                let index = hash[nextNode].indexOf(node);
                hash[nextNode].splice(index, 1);
                if (hash[nextNode].length === 1) {
                    newLeaves.push(nextNode);
                }
            }
        }
        leaves = newLeaves;
    }
    
    return leaves;
};