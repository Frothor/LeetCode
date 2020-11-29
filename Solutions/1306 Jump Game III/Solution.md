# LeetCode Medium 1306. Jump Game III Solution
## Overview
You probably can guess from the problem title, this is the third problem in the series of [Jump Game](https://leetcode.com/problems/jump-game/) problems. Those problems are similar, but have considerable differences, making their solutions quite different.

Here, two approaches are introduced: *Breadth-First Search* approach and *Depth-First Search* approach.

## Approach 1: Breadth-First Search
Most solutions start from a brute force approach and are optimized by removing unnecessary calculations. Same as this one.

A naive brute force approach is to iterate all the possible routes and check if there is one reaches zero. However, if we already checked one index, we do not need to check it again. We can mark the index as visited by make it negative.

### Java
```java
class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;

        Queue<Integer> q = new LinkedList<>();
        q.add(start);

        while (!q.isEmpty()) {
            int node = q.poll();
            // check if reach zero
            if (arr[node] == 0) {
                return true;
            }
            if (arr[node] < 0) {
                continue;
            }

            // check available next steps
            if (node + arr[node] < n) {
                q.offer(node + arr[node]);
            }
            if (node - arr[node] >= 0) {
                q.offer(node - arr[node]);
            }
            // mark as visited
            arr[node] = -arr[node];
        }
        return false;
    }
}
```

### Python3
```python
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        q = [start]

        while q:
            node = q.pop(0)
            # check if reach zero
            if arr[node] == 0:
                return True
            if arr[node] < 0:
                continue

            # check available next steps            
            for i in [node + arr[node], node - arr[node]]:
                if 0 <= i < n:
                    q.append(i)

            # mark as visited
            arr[node] = -arr[node]

        return False
```

### Complexity Analysis

Assume ***N*** is the length of `arr`.

* Time complexity: ***O(N)*** since we will visit every index at most once.

* Space complexity : ***O(N)*** since it needs `q` to store next index. In fact, `q` would keep at most two levels of nodes. Since we got two children for each node, the traversal of this solution is a binary tree. The maximum number of nodes within a single level for a binary tree would be ***N/2***, so the maximum length of `q` is ***O(N/2 + N/2)=O(N)***.

## Approach 2: Depth-First Search
DFS is similar to BFS but differs in the order of searching. You should consider DFS when you think of BFS.

Still, we make the value negative to mark as visited.

### Java
```java
class Solution {
    public boolean canReach(int[] arr, int start) {
        if (start >= 0 && start < arr.length && arr[start] >= 0) {
            if (arr[start] == 0) {
                return true;
            }
            arr[start] = -arr[start];
            return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
        }
        return false;
    }
}
```

### Python
```python
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        if 0 <= start < len(arr) and arr[start] >= 0:
            if arr[start] == 0:
                return True

            arr[start] = -arr[start]
            return self.canReach(arr, start+arr[start]) or self.canReach(arr, start-arr[start])

        return False
```

### Complexity Analysis

Assume ***N*** is the length of `arr`.

* Time complexity: ***O(N)***, since we will visit every index only once.

* Space complexity: ***O(N)*** since it needs at most ***O(N)*** stacks for recursions.