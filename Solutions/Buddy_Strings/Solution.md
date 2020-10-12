# LeetCode Buddy Strings Solution
## Approach 1: Enumerate Cases
### Intuition

If the characters at the index of `i` in both strings are identical, *i.e.* `A[i] == B[i]`, we call the characters at the index `i` as *matched*.

If swapping `A[i]` and `A[j]` would demonstrate that `A` and `B` are buddy strings, then `A[i] == B[j]` and `A[j] == B[i]`. That means among the four free variables `A[i], A[j], B[i], B[j]`, there are only two cases: either `A[i] == A[j]` or not.

### Algorithm

Let's work through the cases.

In the case `A[i] == A[j] == B[i] == B[j]`, then the strings `A` and `B` are equal. So if `A == B`, we should check each index `i` for two matches with the same value.

In the case `A[i] == B[j], A[j] == B[i], (A[i] != A[j])`, the rest of the indices match. So if `A` and `B` have only two unmatched indices (say `i` and `j`), we should check that the equalities `A[i] == B[j] and A[j] == B[i]` hold.

#### Java
```java
class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A.length() != B.length()) return false;
        if (A.equals(B)) {
            int[] count = new int[26];
            for (int i = 0; i < A.length(); ++i)
                count[A.charAt(i) - 'a']++;

            for (int c: count)
                if (c > 1) return true;
            return false;
        } else {
            int first = -1, second = -1;
            for (int i = 0; i < A.length(); ++i) {
                if (A.charAt(i) != B.charAt(i)) {
                    if (first == -1)
                        first = i;
                    else if (second == -1)
                        second = i;
                    else
                        return false;
                }
            }

            return (second != -1 && A.charAt(first) == B.charAt(second) &&
                    A.charAt(second) == B.charAt(first));
        }
    }
}
```

#### Python
```python
class Solution(object):
    def buddyStrings(self, A, B):
        if len(A) != len(B): return False
        if A == B:
            seen = set()
            for a in A:
                if a in seen:
                    return True
                seen.add(a)
            return False
        else:
            pairs = []
            for a, b in itertools.izip(A, B):
                if a != b:
                    pairs.append((a, b))
                if len(pairs) >= 3: return False
            return len(pairs) == 2 and pairs[0] == pairs[1][::-1]
```

### Complexity Analysis

* Time Complexity: ***O(N)***, where ***N*** is the length of `A` and `B`.

* Space Complexity: ***(1)***.

## [C++] Efficient Solution Explained, 100% Time, ~10% Space

I have to admit I lowered my guard and this tricky one threw a few tricky edge jabs in my face.

Well, good experience and good learning then :)!

Okay, first of all I declared just 2 support variables:

* `lenA` that, you guessed it, will store the length of the first string;
* `diff` that will store how many mismatches we found in the string and/or where (basically acting as 2 variables in 1, to save memory):
    * a negative value, like `-1`, the initial value, or `-2` means that we found an even number of mismatches (`0` or `2`, respectively);
    * a non-negative value, means we found a single mismatch and the value itself is the index of said difference among the 2 strings.

Next step: getting rid of some edge cases, returning `false` when either:

* the 2 strings have different length;
* the 2 strings are too short (you cannot swap anything with less than 2 characters).

The first condition guarantees us that if we are proceeding, now we know both strings have the same size.

And proceding we go, looping through each character with the index `i`, so that every time we find a mismatch between `a[i]` and `b[i]`, we go and check `diff's` value:

* `-1` means that we did not find any mismatch so far, so we just updated it to be the `i`, storing where the mismatch happened;
* `-2` means we already found 2 mismatches, so this is the third and we just have to return `false`;
* a non negative value means we found one previous mismatch, so now we go and check:
    * if `a[diff] == b[i] && a[i] == b[diff]` it means that they values are no swappable, so again we can just return `false`;
    * otherwise we are fine and just update `diff` to `-2`.

Once the loop is done, we will return `true` if we either:

* found 2 mismatches (`diff == -2`), which is the ideal case;
* or we found 0 mismatches (`diff == -1`), but only if we had at least 2 equal characters we might have swapped, so only if `lenA > 26` (since having only lower case letters would imply that a greater length has to repeat characters) or if `unordered_set(begin(a), end(a)).size() != lenA` - note that this option to check all the characters is more expensive, but it gets lazy evaluated only when the other condition for `diff == -1` fails, so it never runs for long strings :)

The code:

```c++
class Solution {
public:
    bool buddyStrings(string &a, string &b) {
        // support variables
        int lenA = a.size(), diff = -1;
        // edge cases, out: different sizes or too short
        if (lenA != b.size() || lenA < 2) return false; 
        for (int i = 0; i < lenA; i++) {
            // acting only when a difference is found
            if (a[i] != b[i]) {
                // checking if it is the first difference we found and in case storing i
                if (diff == -1) {
                    diff = i;
                }
                // exiting if it was the third mismatch
                else if (diff == -2) return false;
                // checking if it is a valid or invalid second match
                else {
                    // valid match
                    if (a[diff] == b[i] && a[i] == b[diff]) diff = -2;
                    // invalid match
                    else return false;
                }
            }
        }
        // checking if we found only 2 mismatches or if we found 1 and the string was
        // long enough or not made of all different characters
        return diff == -2 || diff == -1 && (lenA > 26 || unordered_set(begin(a), end(a)).size() != lenA);
    }
};
```

[Link to original post](https://leetcode.com/problems/buddy-strings/discuss/891116/)