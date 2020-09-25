# LeetCode Largest Number
## Approach #1 Sorting via Custom Comparator [Accepted]
### Intuition

To construct the largest number, we want to ensure that the most significant digits are occupied by the largest digits.

### Algorithm

First, we convert each integer to a string. Then, we sort the array of strings.

While it might be tempting to simply sort the numbers in descending order, this causes problems for sets of numbers with the same leading digit. For example, sorting the problem example in descending order would produce the number *9534303*, while the correct answer can be achieved by transposing the *3* and the *30*. Therefore, for each pairwise comparison during the sort, we compare the numbers achieved by concatenating the pair in both orders. We can prove that this sorts into the proper order as follows:

Assume that (without loss of generality), for some pair of integers *a* and *b*, our comparator dictates that *a* should precede *b* in sorted order. This means that  *a⌢b > b⌢a* (where ⌢ represents concatenation). For the sort to produce an incorrect ordering, there must be some *c* for which *b* precedes *c* and *c* precedes *a*. This is a contradiction because *a⌢b > b⌢a* and *b⌢c > c⌢b* implies *a⌢c > c⌢a*. In other words, our custom comparator preserves transitivity, so the sort is correct.

Once the array is sorted, the most "signficant" number will be at the front. There is a minor edge case that comes up when the array consists of only zeroes, so if the most significant number is *0*, we can simply return *0*. Otherwise, we build a string out of the sorted array and return it.

### Java
```java
class Solution {
    private class LargerNumberComparator implements Comparator<String> {
        @Override
        public int compare(String a, String b) {
            String order1 = a + b;
            String order2 = b + a;
           return order2.compareTo(order1);
        }
    }

    public String largestNumber(int[] nums) {
        // Get input integers as strings.
        String[] asStrs = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            asStrs[i] = String.valueOf(nums[i]);
        }

        // Sort strings according to custom comparator.
        Arrays.sort(asStrs, new LargerNumberComparator());

        // If, after being sorted, the largest number is `0`, the entire number
        // is zero.
        if (asStrs[0].equals("0")) {
            return "0";
        }

        // Build largest number from sorted array.
        String largestNumberStr = new String();
        for (String numAsStr : asStrs) {
            largestNumberStr += numAsStr;
        }

        return largestNumberStr;
    }
}
```

### Python3
```python
class LargerNumKey(str):
    def __lt__(x, y):
        return x+y > y+x
        
class Solution:
    def largestNumber(self, nums):
        largest_num = ''.join(sorted(map(str, nums), key=LargerNumKey))
        return '0' if largest_num[0] == '0' else largest_num
```

### Complexity Analysis

* Time complexity : ***O(nlgn)***

Although we are doing extra work in our comparator, it is only by a constant factor. Therefore, the overall runtime is dominated by the complexity of **sort**, which is ***O(nlgn)*** in Python and Java.

* Space complexity : ***O(n)***

Here, we allocate ***O(n)*** additional space to store the copy of **nums**. Although we could do that work in place (if we decide that it is okay to modify **nums**), we must allocate ***O(n)*** space for the final return string. Therefore, the overall memory footprint is linear in the length of **nums**.

## [Python] 2 lines solution, using sort, explained

Note, that we need to somehow sort our data, but be carefull about it: if we have **3**, **32** and **31**, then we need to choose **3** as the first element. However if we have **3**, **34** and **32**, then we need to chose **34** as the first element. So, let us for each two numbers **x** and **y** decide which one is better: we need to compare **xy** and **yx** and choose the best one: we work with **x** and **y** as with strings: for example for **x = 3** and **y = 32**, we need to compare **xy = 332** and **yx = 323**. Also it can be shown that if **xy >= yx** and **yz >= zy**, then **xz >= zx**, this means that we have transitivity property, and this is enough to ensure that our sort is consistent: https://en.wikipedia.org/wiki/Comparison_sort

**Complexity:** time complexity is **O(n log n)**, if we assume that we can make comparison in constant time. In practise, we use strings and compare them, so complexity will be ineed **O(1)**. Space complexity is **O(n)** to keep sorted numbers.

**Note** I use **cmp_to_key** function from **functools** library, which is imported in leetcode already. Also in the end we can have results like **00**, which we need to make **0**, so we use **str(int(...))** trick.

```python
class Solution:
    def largestNumber(self, nums):
        compare = lambda a, b: -1 if a+b > b+a else 1 if a+b < b+a else 0
        return str(int("".join(sorted(map(str, nums), key = cmp_to_key(compare)))))
```

**Comment:** Your compare lambda can be dropped to compare = lambda a, b: -1 if a+b > b+a else 0

[Link to original post](https://leetcode.com/problems/largest-number/discuss/863489/Python-2-lines-solution-using-sort-explained)