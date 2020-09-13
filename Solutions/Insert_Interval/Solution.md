# LeetCode Insert Interval
## [Python] O(n) solution, explained
I am not sure, why this problem is marked as hard, because we do not use any smart ideas to solve it: just do what is asked: traverse our intervals and merge them. Let us consider the case: **intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]** and go through our code:

1. Interval **[1,2]** is before **[4,8]**, that is **y < I[0]**, so we just add it to our res.
2. Interval **[3,5]** is not before **[4,8]** but not after also, so it is the third case and we need to update **I: I = [3,8]** now.
3. Interval **[6,7]:** the same logic, update **I = [3,8]** now (it did not change though)
4. Interval **[8,10]:** still condition number **3**, so **I = [3,10]** now.
5. Interval **[12,16]:** it is after our I, so this is condition number **2** and we **break** from our loop: **i = 3** now.
6. Outside loop we combine **res = [1,2]**, **I = [3,10]** and **intervals[4:] = [12,16]**.

Why we use **i -= 1** inside our loop, before **break**? It can happen, that we did not visit this part and it means, that our suffix **intervals[i+1:]** should be empty.

**Complexity**: time complexity is **O(n)**, space complexity is **O(n)** as well and additional space complexity (if we do not count our output) is **O(1)**.

**Note**: that intstead of traversing our intervals with linear search, we can use binary search, however it will not reduce the overall complexity of algorithm, our result will have in average **O(n)** elements.
```python
class Solution:
    def insert(self, intervals, I):
        res, i = [], -1
        for i, (x, y) in enumerate(intervals):
            if y < I[0]:
                res.append([x, y])
            elif I[1] < x:
                i -= 1
                break
            else:
                I[0] = min(I[0], x)
                I[1] = max(I[1], y)
                
        return res + [I] + intervals[i+1:]
```

[Link to original post](https://leetcode.com/problems/insert-interval/discuss/844494/Python-O(n)-solution-explained)