#  LeetCode 948. Bag of Tokens Solution
## Approach 1: Greedy
### Intuition

If we play a token face up, we might as well play the one with the smallest value. Similarly, if we play a token face down, we might as well play the one with the largest value.

### Algorithm

We don't need to play anything until absolutely necessary. Let's play tokens face up until we can't, then play a token face down and continue.

We must be careful, as it is easy for our implementation to be incorrect if we do not handle corner cases correctly. We should always play tokens face up until exhaustion, then play one token face down and continue.

Our loop must be constructed with the right termination condition: we can either play a token face up or face down.

Our final answer could be any of the intermediate answers we got after playing tokens face up (but before playing them face down.)

### Java
```java
class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        Arrays.sort(tokens);
        int lo = 0, hi = tokens.length - 1;
        int points = 0, ans = 0;
        while (lo <= hi && (P >= tokens[lo] || points > 0)) {
            while (lo <= hi && P >= tokens[lo]) {
                P -= tokens[lo++];
                points++;
            }

            ans = Math.max(ans, points);
            if (lo <= hi && points > 0) {
                P += tokens[hi--];
                points--;
            }
        }

        return ans;
    }
}
```

### Python
```python
class Solution(object):
    def bagOfTokensScore(self, tokens, P):
        tokens.sort()
        deque = collections.deque(tokens)
        ans = bns = 0
        while deque and (P >= deque[0] or bns):
            while deque and P >= deque[0]:
                P -= deque.popleft()
                bns += 1
            ans = max(ans, bns)

            if deque and bns:
                P += deque.pop()
                bns -= 1

        return ans
```

### Complexity Analysis

* Time Complexity: ***O(NlogN)***, where ***N*** is the length of tokens.

* Space Complexity: ***O(N)***.