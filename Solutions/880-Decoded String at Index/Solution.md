# LeetCode Medium 880. Decoded String at Index Solution
## Approach 1: Work Backwards
### Intuition

If we have a decoded string like `appleappleappleappleappleapple` and an index like `K = 24`, the answer is the same if `K = 4`.

In general, when a decoded string is equal to some word with `size` length repeated some number of times (such as `apple` with `size = 5` repeated 6 times), the answer is the same for the index `K` as it is for the index `K % size`.

We can use this insight by working backwards, keeping track of the size of the decoded string. Whenever the decoded string would equal some `word` repeated `d` times, we can reduce `K` to `K % (word.length)`.

### Algorithm

First, find the length of the decoded string. After, we'll work backwards, keeping track of `size`: the length of the decoded string after parsing symbols `S[0], S[1], ..., S[i]`.

If we see a digit `S[i]`, it means the size of the decoded string after parsing `S[0], S[1], ..., S[i-1]` will be `size / Integer(S[i])`. Otherwise, it will be `size - 1`.

### C++
```c++
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long size = 0;
        int N = S.size();

        // Find size = length of decoded string
        for (int i = 0; i < N; ++i) {
            if (isdigit(S[i]))
                size *= S[i] - '0';
            else
                size++;
        }

        for (int i = N-1; i >=0; --i) {
            K %= size;
            if (K == 0 && isalpha(S[i]))
                return (string) "" + S[i];

            if (isdigit(S[i]))
                size /= S[i] - '0';
            else
                size--;
        }
        return "";
    }
};
```

### Java
```java
class Solution {
    public String decodeAtIndex(String S, int K) {
        long size = 0;
        int N = S.length();

        // Find size = length of decoded string
        for (int i = 0; i < N; ++i) {
            char c = S.charAt(i);
            if (Character.isDigit(c))
                size *= c - '0';
            else
                size++;
        }

        for (int i = N-1; i >= 0; --i) {
            char c = S.charAt(i);
            K %= size;
            if (K == 0 && Character.isLetter(c))
                return Character.toString(c);

            if (Character.isDigit(c))
                size /= c - '0';
            else
                size--;
        }

        throw null;
    }
}
```

### Python3
```python
class Solution(object):
    def decodeAtIndex(self, S, K):
        size = 0
        # Find size = length of decoded string
        for c in S:
            if c.isdigit():
                size *= int(c)
            else:
                size += 1

        for c in reversed(S):
            K %= size
            if K == 0 and c.isalpha():
                return c

            if c.isdigit():
                size /= int(c)
            else:
                size -= 1
```

### Complexity Analysis

* Time Complexity: ***O(N)***, where ***N*** is the length of `S`.

* Space Complexity: ***O(1)***.

## [Python] O(n) solution, explained

Let us iterate over our string `S` and check lengths of string we have after each step. Let us consider example `S = hi2bob3`.

1. `h`, length = 1
2. `hi`, length = 2
3. `hi2`, string becomes `hihi` and length equal to `4`.
4. `hi2b`, string becomes `hihib`, length equal to `5`.
5. `hi2bo`, string becomes `hihibo`, length equal to `6`.
6. `hi2bob`, string becomes `hihibob`, length equal to `7`.
7. `hi2bob3`, string becomes `hihibobhihibobhihibob`, length equal to `21`.

Let us write down all these lengths into array `len`: if we have letter, we increase previous element by `1`, if it is digit, we increase previous element multiplied by this digit.

Now, we need to find letter, imagine we have `K = 18`. We will traverse our `S` from the end and check `K % lens[i]`.

1. `18 < 21`, so on this step we do nothing.
2. `18 % 7 = 4`, it means, that string `hihibob` repeated `3` times and we need to choose element number `4` from this string.
3. `4 < 6`, `4 < 5`, so we skip these two steps
4. Now we have `K = 4` and `lens[i] = 4`, and we make `K = 0`. We are good, we can stop? Not exactly, the problem, that now we on the place `hi2` and we are on digit symbol, so we need to continue.
5. Now, `K = 0` and `lens[i] = 2`, and also we have string `hi` so far, so we can stop and answer will be `i`.

**Complexity:** time complexity is `O(n)`, space complexity as well. Space complexity can be reduced to `O(1)`, if we do not store `lens` and only the last one and go back on the fly.

```python
class Solution:
    def decodeAtIndex(self, S, K):
        lens, n = [0], len(S)
        for c in S:
            if c.isdigit():
                lens.append(lens[-1]*int(c))
            else:
                lens.append(lens[-1] + 1)
                
        for i in range(n, 0, -1):
            K %= lens[i]
            if K == 0 and S[i-1].isalpha():
                return S[i-1]
```

[Link to original post](https://leetcode.com/problems/decoded-string-at-index/discuss/979066/Python-O(n)-solution-explained)