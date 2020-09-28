# LeetCode Subarray Product Less Than K
## Approach #1: Binary Search on Logarithms [Accepted]
### Intuition

Because log(∏ixi) = ∑ilogxi, we can reduce the problem to subarray *sums* instead of subarray products. The motivation for this is that the product of some arbitrary subarray may be way too large (potentially `1000^50000`), and also dealing with sums gives us some more familiarity as it becomes similar to other problems we may have solved before.

### Algorithm

After this transformation where every value `x` becomes `log(x)`, let us take prefix sums `prefix[i+1] = nums[0] + nums[1] + ... + nums[i]`. Now we are left with the problem of finding, for each `i`, the largest `j` so that `nums[i] + ... + nums[j] = prefix[j] - prefix[i] < k`.

Because `prefix` is a monotone increasing array, this can be solved with binary search. We add the width of the interval `[i, j]` to our answer, which counts all subarrays `[i, k]` with `k <= j`.

### Python
```python
class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        if k == 0: return 0
        k = math.log(k)

        prefix = [0]
        for x in nums:
            prefix.append(prefix[-1] + math.log(x))

        ans = 0
        for i, x in enumerate(prefix):
            j = bisect.bisect(prefix, x + k - 1e-9, i+1)
            ans += j - i - 1
        return ans
```

### Java
```java
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k == 0) return 0;
        double logk = Math.log(k);
        double[] prefix = new double[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            prefix[i+1] = prefix[i] + Math.log(nums[i]);
        }

        int ans = 0;
        for (int i = 0; i < prefix.length; i++) {
            int lo = i + 1, hi = prefix.length;
            while (lo < hi) {
                int mi = lo + (hi - lo) / 2;
                if (prefix[mi] < prefix[i] + logk - 1e-9) lo = mi + 1;
                else hi = mi;
            }
            ans += lo - i - 1;
        }
        return ans;
    }
}
```

### Complexity Analysis

* Time Complexity: ***O(NlogN)***, where ***N*** is the length of `nums`. Inside our for loop, each binary search operation takes ***O(logN)*** time.

* Space Complexity: ***O(N)***, the space used by `prefix`.

## Approach #2: Sliding Window [Accepted]
### Intuition

For each `right`, call `opt(right)` the smallest `left` so that the product of the subarray `nums[left] * nums[left + 1] * ... * nums[right]` is less than `k`. `opt` is a monotone increasing function, so we can use a sliding window.

### Algorithm

Our loop invariant is that `left` is the smallest value so that the product in the window `prod = nums[left] * nums[left + 1] * ... * nums[right]` is less than `k`.

For every right, we update `left` and `prod` to maintain this invariant. Then, the number of intervals with subarray product less than `k` and with right-most coordinate `right`, is `right - left + 1`. We'll count all of these for each value of `right`.

### Python
```python
class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        if k <= 1: return 0
        prod = 1
        ans = left = 0
        for right, val in enumerate(nums):
            prod *= val
            while prod >= k:
                prod /= nums[left]
                left += 1
            ans += right - left + 1
        return ans
```

### Java
```java
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0;
        int prod = 1, ans = 0, left = 0;
        for (int right = 0; right < nums.length; right++) {
            prod *= nums[right];
            while (prod >= k) prod /= nums[left++];
            ans += right - left + 1;
        }
        return ans;
    }
}
```

### Complexity Analysis

Time Complexity: ***O(N)***, where ***N*** is the length of `nums`. `left` can only be incremented at most `N` times.

Space Complexity: ***O(1)***, the space used by `prod`, `left`, and `ans`.

## [Python] 2 pointers O(n) solution, explained

It is given that all numbers are natural, that is they are more or equal than `1`. The idea is to use two pointers (or sliding window) approach, where at each moment of time we try to extend our window. Let us `beg, end-1` be the beginning and end of our window (it means that if `beg=end=0`, our window is empty), `P` is current product of numbers in our window and `out` is our answer we need to return.

On each iteration, we extend our window by one number to the right: however we need to check first, that the product do not exceed `k`. So, we remove numbers from the beginning of our window, until product is less then k. Note also, that we can not have `end < beg`, so we break if it is the case: it means than our window becomes empty. Finally, we update `out += end - beg + 1`: this is number of subarrays ending with `end` with product less than `k`.

**Complexity**: time complexity is `O(n)`, because on each step we increase either `beg` or `end`. Space complexity is `O(1)`.

```python
class Solution:
    def numSubarrayProductLessThanK(self, nums, k):
        out, beg, end, P = 0, 0, 0, 1
        while end < len(nums):
            P *= nums[end]
            while end >= beg and P >= k:
                P /= nums[beg]
                beg += 1
            out += end - beg + 1
            end += 1
        return out
```