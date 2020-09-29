# LeetCode Bitwise AND of Numbers Range
## Bit masks; no loops

The approach outlined here constructs a mask of all bits that the numbers between `m` and `n` would zero when AND'ed together. It then ANDs this with `m & n` to get the result. This requires no loops and a small number of operations.

### Brute force
The brute force solution is to iterate through all the numbers and perform the bitwise AND on the result.

```python
result = m
# n + 1 as the problem statement is inclusive of n
for x in range(m + 1, n + 1):
    result &= x
return x
```

### Creating a mask
Instead of doing this, we can take the AND with `n` directly as a first step:
```python
result = m & n
```

But what about all the numbers in between `m` and `n`?

Recall that the ith bit will change every 2^i increments. For example, the `i = 0` bit changes for every 2^0 = 1 you add:

```python
00
# Added 2^0, flip the i = 0 bit
01
# Added 2^0, flip the i = 0 bit again
11
# Added 2^0, flip the i = 0 bit again
10
```

The `i = 1` bit changes every 2^1 = 2 you add:
```python
000
001
# Added 2^1, flip the i = 1 bit
010
011
# Added 2^1, flip the i = 1 bit again
100
101
# Added 2^1, flip the i = 1 bit again
110
111
```

**If there is a number `m + 2^i` in between `m` and `n`, the ith bit will be flipped**. This is the key of this solution.

Because we perform a bitwise AND with every number in between `m` and `n`, *any* flip of the ith bit means the ith bit in the final result will also be zero: it will either be zero in `m` to start with, or it will be one to start with and it will flip at least once from 1 to 0 after we've added 2^i. The bitwise AND will pick up the flip to zero and it will 'stick' in the result.

Putting all this together, the most significant bit of the *difference* between `m` and `n` gives us the highest bit at which all bits will become zero.

As an example, take `m = 5` and `n = 7`. This gives:
```
m = 101
n = 111
difference = 010
```

The difference is `2`. This means the `i = 0` bit will flip, because `difference >= 2 ** 0`, and the `i = 1` bit will also flip, because `difference >= 2 ** 1`. The `i = 2` bit will not flip because `difference < 2 ** 2`.

We can find the index of the most significant by taking the base-2 logarithm.
```python
import math

difference = n - m
msb = math.floor(math.log2(difference))
```

Then we just need to create a mask out of this so that we can zero all bits at and below this index in the result.

One technique is to shift the most-significant bit up one place and then subtract one, leaving all ones. For example when the the difference is 2:

```python
difference = 2
# msb is 010
msb = 1 << 2
# Shift up by one to get 100, then subtract one to get 011
bits_to_remove = (msb << 1) - 1
```

We now have a mask of all bits which the numbers between `m` and `n` will flip.

All that's left to do is zero these bits in the result. To do this, we can just invert the mask and AND it with the `m & n` we had previously.
```python
# bits_to_remove was 011, so the inverse is 100
result &= ~bits_to_remove
```

### Final solution
After taking care of the trivial case `m` = `n`, compute the difference and the mask, and then AND together `m`, `n`, and the mask.
```python
def rangeBitwiseAnd(self, m: int, n: int) -> int:
    if m == n:
	    return m
	difference = n - m
	msb = 1 << math.floor(math.log2(difference))
	bits_to_remove = (msb << 1) - 1
	return m & n & ~bits_to_remove
```

[Link to original solution](https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/593403/Bit-masks-no-loops)