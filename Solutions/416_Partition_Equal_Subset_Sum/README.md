# LeetCode Medium 416. Partition Equal Subset Sum
Given a **non-empty** array `nums` containing **only positive integers**, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

### Example 1:
```
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
```

### Example 2:
```
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
``` 

### Constraints:

* `1 <= nums.length <= 200`
* `1 <= nums[i] <= 100`

## [Python] Fastest dp with bit manipulation, explained
The idea here is to use usual dp with states, but to encode them with numbers. Let me explain on small example, what I mean. Imagine, that we have numbers `A = [1,5,11,5]`, then let us start with `a = 1`:

1. Step 1, what numbers, we can get, using only first number `1`: it is only `1`, so `a = 11`: we have onese on the places we can represent.
2. Step 2, what numbers we can get, using only numbers `1` and 5: it is `1`, `5` and `6`, and `a = 1100011`
3. Step 3, what numbers we can get, using numbers `1`, `5`, `11`? it is `1,5,6,11,12,16,17`, so `a = 110001100001100011`, where we have ones on exactly the places which can be represented with some sum of numbers.
4. Step 4, we have now `a = 11000110001110001100011`

Finally, we need to just check if we have 1 in the middle of this number or not.

**Complexity:** time complexity is `O(N*n)`, where `N = sum(A)` and `n = len(A)`. Space complexity is `O(N)`. Note, that in practice however it will work several times faster than usual dp due to fast bit operations.
```python
class Solution:
    def canPartition(self, A):
        a = reduce(lambda a, num: a|(a<<num), A, 1)
        return sum(A)%2 == 0 and a & (1 << (sum(A)//2)) != 0

```

**Update:** oneliner from **rkmd**:

```python
return not (t := sum(A)) % 2 and reduce(lambda a, x: a | a << x, A, 1) & 1 << t // 2
```

[Link to original post](https://leetcode.com/problems/partition-equal-subset-sum/discuss/950617/Python-Fastest-dp-with-bit-manipulation-explained)