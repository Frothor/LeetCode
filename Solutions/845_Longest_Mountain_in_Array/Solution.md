# LeetCode Medium 845. Longest Mountain in Array Solution
## Approach #1: Two Pointer [Accepted]
### Intuition

Without loss of generality, a mountain can only start after the previous one ends.

This is because if it starts before the peak, it will be smaller than a mountain starting previous; and it is impossible to start after the peak.

### Algorithm

For a starting index base, let's calculate the length of the longest mountain `A[base], A[base+1], ..., A[end]`.

If such a mountain existed, the next possible mountain will start at `base = end`; if it didn't, then either we reached the end, or we have `A[base] >= A[base+1]` and we can start at `base + 1`.

### Example

Here is a worked example on the array `A = [1, 2, 3, 2, 1, 0, 2, 3, 1]`:

![diagram1](images/diagram1.png)

`base` starts at `0`, and `end` travels using the first while loop to `end = 2` (`A[end] = 3`), the potential peak of this mountain. After, it travels to `end = 5` (`A[end] = 0`) during the second while loop, and a candidate answer of 6 (`base = 0, end = 5`) is recorded.

Afterwards, base is set to `5` and the process starts over again, with `end = 7` the peak of the mountain, and `end = 8` the right boundary, and the candidate answer of 4 (`base = 5, end = 8`) being recorded.

### Java
```java
class Solution {
    public int longestMountain(int[] A) {
        int N = A.length;
        int ans = 0, base = 0;
        while (base < N) {
            int end = base;
            // if base is a left-boundary
            if (end + 1 < N && A[end] < A[end + 1]) {
                // set end to the peak of this potential mountain
                while (end + 1 < N && A[end] < A[end + 1]) end++;

                // if end is really a peak..
                if (end + 1 < N && A[end] > A[end + 1]) {
                    // set end to the right-boundary of mountain
                    while (end + 1 < N && A[end] > A[end + 1]) end++;
                    // record candidate answer
                    ans = Math.max(ans, end - base + 1);
                }
            }

            base = Math.max(end, base + 1);
        }

        return ans;
    }
}
```

### Pyuthon
```python
class Solution(object):
    def longestMountain(self, A):
        N = len(A)
        ans = base = 0

        while base < N:
            end = base
            if end + 1 < N and A[end] < A[end + 1]: #if base is a left-boundary
                #set end to the peak of this potential mountain
                while end+1 < N and A[end] < A[end+1]:
                    end += 1

                if end + 1 < N and A[end] > A[end + 1]: #if end is really a peak..
                    #set 'end' to right-boundary of mountain
                    while end+1 < N and A[end] > A[end+1]:
                        end += 1
                    #record candidate answer
                    ans = max(ans, end - base + 1)

            base = max(end, base + 1)

        return ans
```

### Complexity Analysis

* Time Complexity: ***O(N)***, where ***N*** is the length of `A`.

* Space Complexity: ***O(1)***.

## [Python] one pass, O(1) space, explained

Let us traverse our numbers and keep two variables: `state` and `length`, where:

1. `state` is current state of our mountain: it is `0` in the beginning and also means that we can not start our mountain from given index. `state` equal to `1` means, that we are on increasing phase of our mountain and `state` equal `2` means, that we are on decreasing phase of our mountain.
2. `length` is current length of mountain built so far.

Now, we need to carefully look at our states and see what we need to do in one or another situation:

1. If `state` is equal to `0` or `1` and next element is more than current, it means we can continue to build increasing phase of mountain: so, we put `state` equal to `1` and increase `length` by `1`.
2. If `state` is equal to `2` and next element is more then curren, it means, that previous mountain just finished and we are currently buildind next mountain, for examle in `0,1,0,2,0`: first mountain is `0,1,0` and second is `0,2,0`. In this case we already build `2` elements of new mountain (mountains have `1` common element), so we put `length = 2` and `state = 1`.
3. If `state` is equal to `1` or `2` and next element is less than current, it means that we are on the decreasing phase of mountain: we put `state = 2` and also increase `length` by `1`. Note, that only here we need to update `max_len`, because our mountain is legible on this stage.
4. Finally, if we have some other option: it is either next element is equal to current, or we have state `0` and next element is less than previous, we need put our `state` and `length` to values as we just started.

**Complexity:** time complexity is `O(n)`, we make one pass over data, space complexity is `O(1)`.

```python
class Solution:
    def longestMountain(self, A):
        n, max_len = len(A), 0
        state, length = 0, 1
        for i in range(n-1):
            if state in [0, 1] and A[i+1] > A[i]:
                state, length = 1, length + 1
            elif state == 2 and A[i+1] > A[i]:
                state, length = 1, 2
            elif state in [1, 2] and A[i+1] < A[i]:
                state, length = 2, length + 1
                max_len = max(length, max_len)
            else:
                state, length = 0, 1
                
        return max_len
```

[Link to original post](https://leetcode.com/problems/longest-mountain-in-array/discuss/937652/Python-one-pass-O(1)-space-explained)