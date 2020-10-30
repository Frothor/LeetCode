# LeetCode 673. Number of Longest Increasing Subsequence Solution
## Approach 1: Dynamic Programming
### Intuition and Algorithm

Suppose for sequences ending at `nums[i]`, we knew the length `length[i]` of the longest sequence, and the number `count[i]` of such sequences with that length.

For every `i < j` with `A[i] < A[j]`, we might append `A[j]` to a longest subsequence ending at `A[i]`. It means that we have demonstrated `count[i]` subsequences of length `length[i] + 1`.

Now, if those sequences are longer than `length[j]`, then we know we have `count[i]` sequences of this length. If these sequences are equal in length to `length[j]`, then we know that there are now `count[i]` additional sequences to be counted of that length (ie. `count[j] += count[i]`).

### Java
```java
class Solution {
    public int findNumberOfLIS(int[] nums) {
        int N = nums.length;
        if (N <= 1) return N;
        int[] lengths = new int[N]; //lengths[i] = length of longest ending in nums[i]
        int[] counts = new int[N]; //count[i] = number of longest ending in nums[i]
        Arrays.fill(counts, 1);

        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < j; ++i) if (nums[i] < nums[j]) {
                if (lengths[i] >= lengths[j]) {
                    lengths[j] = lengths[i] + 1;
                    counts[j] = counts[i];
                } else if (lengths[i] + 1 == lengths[j]) {
                    counts[j] += counts[i];
                }
            }
        }

        int longest = 0, ans = 0;
        for (int length: lengths) {
            longest = Math.max(longest, length);
        }
        for (int i = 0; i < N; ++i) {
            if (lengths[i] == longest) {
                ans += counts[i];
            }
        }
        return ans;
    }
}
```

### Python
```python
class Solution(object):
    def findNumberOfLIS(self, nums):
        N = len(nums)
        if N <= 1: return N
        lengths = [0] * N #lengths[i] = longest ending in nums[i]
        counts = [1] * N #count[i] = number of longest ending in nums[i]

        for j, num in enumerate(nums):
            for i in xrange(j):
                if nums[i] < nums[j]:
                    if lengths[i] >= lengths[j]:
                        lengths[j] = 1 + lengths[i]
                        counts[j] = counts[i]
                    elif lengths[i] + 1 == lengths[j]:
                        counts[j] += counts[i]

        longest = max(lengths)
        return sum(c for i, c in enumerate(counts) if lengths[i] == longest)
```

### Complexity Analysis

* Time Complexity: ***O(N^2)*** where ***N*** is the length of `nums`. There are two for-loops and the work inside is ***O(1)***.

* Space Complexity: ***O(N)***, the space used by `lengths` and `counts`.

## Approach 2: Segment Tree
### Intuition

Suppose we knew for each length `L`, the number of sequences with length `L` ending in `x`. Then when considering the next element of `nums`, updating our knowledge hinges on knowing the number of sequences with length `L-1` ending in `y < x`. This type of query over an interval is a natural fit for using some sort of tree.

We could try using Fenwick trees, but we would have to store ***N*** of them, which naively might be ***O(N^2)*** space. Here, we focus on an implementation of a Segment Tree.

### Algorithm

Implementing Segment Trees is discussed in more detail [here](https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/). In this approach, we will attempt a variant of segment tree that doesn't use lazy propagation.

First, let us call the "value" of an interval, the longest length of an increasing subsequence, and the number of such subsequences in that interval.

Each node knows about the interval of `nums` values it is considering `[node.range_left, node.range_right]`, and it knows about `node.val`, which contains information on the value of interval. Nodes also have `node.left` and `node.right` children that represents the left and right half of the interval `node` considers. These child nodes are created on demand as appropriate.

Now, `query(node, key)` will tell us the value of the interval specified by `node`, except we'll exclude anything above `key`. When key is outside the interval specified by `node`, we return the answer. Otherwise, we'll divide the interval into two and query both intervals, then `merge` the result.

What does `merge(v1, v2)` do? Suppose two nodes specify adjacent intervals, and have corresponding values `v1 = node1.val`, `v2 = node2.val`. What should the aggregate value, `v = merge(v1, v2)` be? If there are longer subsequences in one node, then `v` will just be that. If both nodes have longest subsequences of equal length, then we should count subsequences in both nodes. Note that we did not have to consider cases where larger subsequences were made, since these were handled by `insert`.

What does `insert(node, key, val)` do? We repeatedly insert the `key` into the correct half of the interval that `node` specifies (possibly a point), and after such insertion this node's value could change, so we merge the values together again.

Finally, in our main algorithm, for each `num in nums` we `query` for the value `length`, `count` of the interval below `num`, and we know it will lead to `count` additional sequences of length `length + 1`. We then update our tree with that knowledge.

### Java
```java
class Solution {
    public Value merge(Value v1, Value v2) {
        if (v1.length == v2.length) {
            if (v1.length == 0) return new Value(0, 1);
            return new Value(v1.length, v1.count + v2.count);
        }
        return v1.length > v2.length ? v1 : v2;
    }

    public void insert(Node node, int key, Value val) {
        if (node.range_left == node.range_right) {
            node.val = merge(val, node.val);
            return;
        } else if (key <= node.getRangeMid()) {
            insert(node.getLeft(), key, val);
        } else {
            insert(node.getRight(), key, val);
        }
        node.val = merge(node.getLeft().val, node.getRight().val);
    }

    public Value query(Node node, int key) {
        if (node.range_right <= key) return node.val;
        else if (node.range_left > key) return new Value(0, 1);
        else return merge(query(node.getLeft(), key), query(node.getRight(), key));
    }

    public int findNumberOfLIS(int[] nums) {
        if (nums.length == 0) return 0;
        int min = nums[0], max = nums[0];
        for (int num: nums) {
            min = Math.min(min, num);
            max = Math.max(max, num);
        }
        Node root = new Node(min, max);
        for (int num: nums) {
            Value v = query(root, num-1);
            insert(root, num, new Value(v.length + 1, v.count));
        }
        return root.val.count;
    }
}

class Node {
    int range_left, range_right;
    Node left, right;
    Value val;
    public Node(int start, int end) {
        range_left = start;
        range_right = end;
        left = null;
        right = null;
        val = new Value(0, 1);
    }
    public int getRangeMid() {
        return range_left + (range_right - range_left) / 2;
    }
    public Node getLeft() {
        if (left == null) left = new Node(range_left, getRangeMid());
        return left;
    }
    public Node getRight() {
        if (right == null) right = new Node(getRangeMid() + 1, range_right);
        return right;
    }
}

class Value {
    int length;
    int count;
    public Value(int len, int ct) {
        length = len;
        count = ct;
    }
}
```

### Python
```python
class Node(object):
    def __init__(self, start, end):
        self.range_left, self.range_right = start, end
        self._left = self._right = None
        self.val = 0, 1 #length, count
    @property
    def range_mid(self):
        return (self.range_left + self.range_right) / 2
    @property
    def left(self):
        self._left = self._left or Node(self.range_left, self.range_mid)
        return self._left
    @property
    def right(self):
        self._right = self._right or Node(self.range_mid + 1, self.range_right)
        return self._right

def merge(v1, v2):
    if v1[0] == v2[0]:
        if v1[0] == 0: return (0, 1)
        return v1[0], v1[1] + v2[1]
    return max(v1, v2)

def insert(node, key, val):
    if node.range_left == node.range_right:
        node.val = merge(val, node.val)
        return
    if key <= node.range_mid:
        insert(node.left, key, val)
    else:
        insert(node.right, key, val)
    node.val = merge(node.left.val, node.right.val)

def query(node, key):
    if node.range_right <= key:
        return node.val
    elif node.range_left > key:
        return 0, 1
    else:
        return merge(query(node.left, key), query(node.right, key))

class Solution(object):
    def findNumberOfLIS(self, nums):
        if not nums: return 0
        root = Node(min(nums), max(nums))
        for num in nums:
            length, count = query(root, num-1)
            insert(root, num, (length+1, count))
        return root.val[1]
```

### Complexity Analysis

* Time Complexity: ***O(NlogN)*** where ***N*** is the length of `nums`. In our main for loop, we do ***O(logN)*** work to `query` and `insert`.

* Space Complexity: ***O(N)***, the space used by the segment tree.

## [Python] Short O(n log n) solution, beats 100%, explained

The idea of my solution is to use so-called Patience sort: https://en.wikipedia.org/wiki/Patience_sorting

The idea is to keep several `decks`, where numbers in each deck are decreasing. Also when we see new card, we need to put it to the end of the leftest possible deck. Also we have `paths`: corresponing number of LIS, ending with given num. That is in `paths[0]` we keep number of LIS with length `1`, in `paths[k]` we keep number of LIS with length `k+1`. (we keep cumulative sums) Also we keep `ends_decks` list to have quick access to end of our decks.

**Property:** It can be proved, that each LIS can be formed as choosing not more than one number from each deck and choosing them, looking at decks from left to right.

Imagine, that we have `nums = [1,3,5,4,7,10,8,2,8]`, then we have the following `decks` and `paths` step by step:

`decks = [[-1]] paths = [[0, 1]]`
`decks = [[-1], [-3]] paths = [[0, 1], [0, 1]]`
`decks = [[-1], [-3], [-5]] paths = [[0, 1], [0, 1], [0, 1]]`
`decks = [[-1], [-3], [-5, -4]] paths = [[0, 1], [0, 1], [0, 1, 2]]`
`decks = [[-1], [-3], [-5, -4], [-7]] paths = [[0, 1], [0, 1], [0, 1, 2], [0, 2]]`
`decks = [[-1], [-3], [-5, -4], [-7], [-10]] paths = [[0, 1], [0, 1], [0, 1, 2], [0, 2], [0, 2]]`
`decks = [[-1], [-3], [-5, -4], [-7], [-10, -8]] paths = [[0, 1], [0, 1], [0, 1, 2], [0, 2], [0, 2, 4]]`
`decks = [[-1], [-3, -2], [-5, -4], [-7], [-10, -8]] paths = [[0, 1], [0, 1, 2], [0, 1, 2], [0, 2], [0, 2, 4]]`
`decks = [[-1], [-3, -2], [-5, -4], [-7], [-10, -8, -8]] paths = [[0, 1], [0, 1, 2], [0, 1, 2], [0, 2], [0, 2, 4, 6]]`

We use negative numbers, so each deck is sorted in increasing way instead of decreasing.

When we see new `num`, then we first find `deck_idx:` number of deck we need to put this `num`. Now, we want to find number of LIS, ending with this `num`: for this we need to look at previous deck and find the place of `num` inside this deck: here we use our **property**, we update our `n_path`.

Now, we need to decide where we put this number:

1. If our `deck_idx` is equal to `len(decks)`, it means, that we need to create new `deck`: we create new deck with one element, update `ends_decks` and also append `n_paths` to our `paths`.
2. In opposite case, we need to add `nums` to the end of corresponding deck, again update `ends_decks` and update our `pathcs[deck_idx]`: it will consist of two parts: `n_paths`: number of paths, such that previous element is from previous or before decks. Also we have `paths[deck_idx][-1]`, because we keep cumulative sums inside.

Finally, we return `paths[-1][-1]`, it is number of LIS with the biggest length.

**Complexity** is `O(n log n)`, because for each new num we process it in `O(log n)`. Space complexity is `O(n)`. When I run it, i have times, I have times from 60ms to 72ms, where `60`ms beats 100% of python solutions.

```python
class Solution:
    def findNumberOfLIS(self, nums):
        if not nums: return 0
    
        decks, ends_decks, paths = [], [], []
        for num in nums:
            deck_idx = bisect.bisect_left(ends_decks, num)
            n_paths = 1
            if deck_idx > 0:
                l = bisect.bisect(decks[deck_idx-1], -num)
                n_paths = paths[deck_idx-1][-1] - paths[deck_idx-1][l]
                
            if deck_idx == len(decks):
                decks.append([-num])
                ends_decks.append(num)
                paths.append([0,n_paths])
            else:
                decks[deck_idx].append(-num)
                ends_decks[deck_idx] = num
                paths[deck_idx].append(n_paths + paths[deck_idx][-1])
              
        return paths[-1][-1]
```

**Shorter version** it can be written in shorter version, if we prefill our `decks`, `decks_ends` and `paths` first. However I do no know if we can do binary search in python by **key**: if we can, we can remove `ends_decks` at all and simplify it even more. Can somebody help me with it?

```python
class Solution:
    def findNumberOfLIS(self, nums):
        if not nums: return 0
        n = len(nums) + 1
    
        decks, ends_decks, paths = [[] for _ in range(n)], [float("inf")]*n, [[0] for _ in range(n)]
        for num in nums:
            idx = bisect.bisect_left(ends_decks, num)
            n_paths = 1
            if idx > 0:
                l = bisect.bisect(decks[idx-1], -num)
                n_paths = paths[idx-1][-1] - paths[idx-1][l]
            
            decks[idx].append(-num)
            ends_decks[idx] = num
            paths[idx].append(n_paths + paths[idx][-1])
                
        return paths[paths.index([0]) - 1][-1]
```

PS: see also my solution of problem 300: Longest Increasing Subsequence: https://leetcode.com/problems/longest-increasing-subsequence/discuss/667975/Python-3-Lines-dp-with-binary-search-explained

[Link to original post](https://leetcode.com/problems/number-of-longest-increasing-subsequence/discuss/916196/Python-Short-O(n-log-n)-solution-beats-100-explained)