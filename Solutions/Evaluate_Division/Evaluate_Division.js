/**
 * @param {string[][]} equations
 * @param {number[]} values
 * @param {string[][]} queries
 * @return {number[]}
 */
var calcEquation = function (equations, values, queries) {
  const graph = new Graph();
  for (let i = 0; i < equations.length; i++) {
    let [start, end] = equations[i];
    graph.addEdge(start, end, values[i]);
    graph.addEdge(end, start, 1 / values[i]);
  }
  const answer = [];
  for (let [start, end] of queries) {
    let res = graph.findCost(start, end);
    answer.push(res == -Infinity ? -1 : res);
  }
  return answer;
};

class Graph {
  constructor() {
    this.map = new Map();
  }

  addEdge(start, end, weight) {
    if (this.map.has(start)) {
      this.map.get(start).push({ end, weight });
    } else {
      this.map.set(start, [{ end, weight }]);
    }
  }

  findCost(source, destination) {
    let visited = {};

    const inner = (start) => {
      if (!this.map.has(start)) {
        return -Infinity;
      }
      if (start == destination) {
        return 1;
      }
      visited[start] = 1;
      let answer = -Infinity;
      for (let { end, weight } of this.map.get(start)) {
        if (!visited[end]) {
          answer = Math.max(answer, inner(end) * weight);
        }
      }
      return answer;
    };

    return inner(source);
  }
}

//Most common
/**
 * @param {string[][]} equations
 * @param {number[]} values
 * @param {string[][]} queries
 * @return {number[]}
 */
var calcEquation = function (equations, values, queries) {
  const graph = {};
  const res = [];

  for (let i = 0; i < equations.length; i++) {
    let A = equations[i][0];
    let B = equations[i][1];
    let value = values[i];
    if (graph[A] === undefined) {
      graph[A] = { [B]: value };
    } else {
      graph[A][B] = value;
    }

    if (graph[B] === undefined) {
      graph[B] = { [A]: 1.0 / value };
    } else {
      graph[B][A] = 1.0 / value;
    }
  }

  for (let query of queries) {
    if (!(query[0] in graph) || !(query[1] in graph)) {
      res.push(-1.0);
      continue;
    }
    if (query[0] === query[1]) {
      res.push(1.0);
      continue;
    }
    if (!dfs(query[0], query[1], new Set(), 1)) {
      res.push(-1.0);
    }
  }
  return res;

  function dfs(s, d, visited, product) {
    if (visited.has(s)) return false;

    visited.add(s);
    const neighbors = graph[s];
    if (d in neighbors) {
      res.push(product * neighbors[d]);
      return true;
    }

    for (let node in neighbors) {
      if (dfs(node, d, visited, product * neighbors[node])) return true;
    }
    return false;
  }
};

//Fastest
/**
 * @param {string[][]} equations
 * @param {number[]} values
 * @param {string[][]} queries
 * @return {number[]}
 */
var calcEquation = function (equations, values, queries) {
  const relationships = new Map();
  for (let i = 0; i < equations.length; i++) {
    let [var1, var2] = equations[i];
    let weight = values[i];
    let inverseWeight = 1 / weight;

    relationships.set(
      var1,
      { ...(relationships.get(var1) || {}), [var2]: weight },
    );
    relationships.set(
      var2,
      { ...(relationships.get(var2) || {}), [var1]: inverseWeight },
    );
  }

  const dfs = (v, target, seen) => {
    const varRelations = relationships.get(v);
    seen[v] = true;
    for (let key in varRelations) {
      if (seen[key]) continue;

      if (target === key) return varRelations[target];
      const val = dfs(key, target, seen);
      if (val !== -1) return val * varRelations[key];
    }
    return -1;
  };

  let results = [];
  for (let i = 0; i < queries.length; i++) {
    const query = queries[i];
    if (query[0] === query[1] && relationships.has(query[0])) {
      results.push(1);
      continue;
    }
    results.push(dfs(query[0], query[1], {}));
  }
  return results;
};
