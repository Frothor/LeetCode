# LeetCode Gas Station Solution
## [Python] O(n) greedy solution, explained

Let us first evaluate differences between our **gas** and **cost**, because this is what we need in the end. Now, let us start from first place and check if we can fulfill problem conditions: it means that all **cumulative** sums should be not negative. If we get negative cumulative sum, it means, that we can not succeed using current starting index, so we need to take next starting index. In fact we can do better: imagine, we have i as starging index and at some moment we have cumulative sum which is negative:

**d_i + ... _ d_j < 0.**

Note also, that it is the first time we have this sum negative. But it means, that if we consider any **k**, such that **i+1 <=k < j**, then sum **d_k + ... + d_j** also will be negatie, because sum **d_i + ... d_{k-1}** will be positive. It means, that the next candidate for starting index should be **j+1**.

Imagine example **-2 -2 -2 3 3**. Note, that our gas stations are on circle, so let us use duplication trick and traverse **-2 -2 -2 3 3 -2 -2 -2 3 3**. If we apply our logic, we will find **-2 -2 -2 3 3 -2 -2 -2 3 3**: it means if we have solution, starting index will be before first **n**.

If we have **-2 -2 -2 3 2**, then we have **-2 -2 -2 3 2 -2 -2 -2 3 2**, so starting index is not before first **n**.

**Complexity:** Time complexity is **O(n)**, because we have two passes over our data and space complexity is also **O(n)**, because I evaluate **diffs** (it can be easily reduced to **O(1)**).

```
class Solution:
    def canCompleteCircuit(self, gas, cost):
        diffs = [a-b for a,b in zip(gas, cost)]
        n = len(diffs)
        cumsum, out = 0, 0
        for i in range(2*n):
            cumsum += diffs[i%n]
            if cumsum < 0:
                cumsum = 0
                out = i + 1
                
        return -1 if out > n else out
```

**With O(1) space complexity**
```
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # diffs = [a-b for a,b in zip(gas, cost)]
        n = len(gas)
        cumsum, out = 0, 0
        for i in range(2*n):
            # cumsum += diffs[i%n]
            cumsum += gas[i%n] - cost[i%n]
            if cumsum < 0:
                cumsum = 0
                out = i + 1
                
        return -1 if out > n else out
```

**
[Link to original post](https://leetcode.com/problems/gas-station/discuss/860396/Python-O(n)-greedy-solution-explained)
