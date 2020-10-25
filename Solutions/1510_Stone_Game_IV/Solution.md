# LeetCode 1510. Stone Game IV Solution
## Overview
You probably can guess from the problem title, this is the fourth problem in the series of [Stone Game](https://leetcode.com/problems/stone-game/) problems. Those problems are similar, but have considerable differences, making their solutions quite different. It's highly recommended to finish them all.

Here, two approaches are introduced: DFS with memorization and DP approach.

## Approach 1: DFS with memoization
### Intuition

First, let's analyze the problem.

According to [Zermelo's_theorem](https://en.wikipedia.org/wiki/Zermelo%27s_theorem_(game_theory)), given n stones, either Alice has a must-win strategy, or Bob has one. Therefore, for Alice, the current state is either "must-win" or "must-lose". But how to determine which one it is?

>For convenience, in the following context, "the current player" refers to the player now removing the stones, and "state i" refers to when there is i stones remaining.

>Now the problem asks whether the current player will win in state `n`.

If we can go to a known state where Bob must lose, then we know Alice must win in the current state. All Alice has to do is to move the corresponding number of stones to go to that state. Therefore we need to find out which state Bob must lose.

Note that after going to the next state, Bob becomes the player removing the stones, which is the position of Alice in the current state. Therefore, to find out whether Bob will lose in the next state, we just need to check whether our function gives `False` for remaining stones.

### Algorithm

Let function `dfs(remain)` represents whether the current player must win with `remain` stones remaining.

To find out the result of `dfs(n)`, we need to iterate `k` from 0 to check whether there exits `dfs(remain - k*k)==False`. To prevent redundant calculate, use a map to store the result of `dfs` function.

Don't forget the base case `dfs(0)==False` and `dfs(1)==True`.

>Note: After reading the Algorithm part, it is recommended to try to write the code on your own before reading the solution code.

### Java
```java
class Solution {
    public boolean winnerSquareGame(int n) {
        HashMap<Integer, Boolean> cache = new HashMap<>();
        cache.put(0, false);
        return dfs(cache, n);
    }

    public static boolean dfs(HashMap<Integer, Boolean> cache, int remain) {
        if (cache.containsKey(remain)) {
            return cache.get(remain);
        }
        int sqrt_root = (int) Math.sqrt(remain);
        for (int i = 1; i <= sqrt_root; i++) {
            // if there is any chance to make the opponent lose the game in the next round,
            // then the current player will win.
            if (!dfs(cache, remain - i * i)) {
                cache.put(remain, true);
                return true;
            }
        }
        cache.put(remain, false);
        return false;
    }
}
```

### Python3
```python
class Solution:
    def winnerSquareGame(self, n: int) -> bool:

        @lru_cache(maxsize=None)
        def dfs(remain):
            if remain == 0:
                return False

            sqrt_root = int(remain**0.5)
            for i in range(1, sqrt_root+1):
                # if there is any chance to make the opponent lose the game in the next round,
                #  then the current player will win.
                if not dfs(remain - i*i):
                    return True

            return False

        return dfs(n)
```
There some tricks that we used in the code above.

In the Python code, we use `@lru_cache` instead of a map to store the result of dfs. It's a useful grammar sugar in Python.

In the Java code, we don't have things like `@lru_cache` in Python, so here we use a simple HashMap. However, we can still use some tricks, if you want -- using an array instead of a map: we can use `0` to mark the unvisited nodes, use `1` to mark the `true` results, and use `2` to mark the `false` results. Also, we can just use an array of bytes, which uses less memory than an array of ints.

Note that the speed would be a little faster if you iterate `i` from `sqrt_root` to `0` due to the data characteristics.

### Complexity Analysis

Assume N is the length of `arr`.

* Time complexity: ***O(Nsqrt(N))*** since we spend ***O(sqrt(N))*** at most for each dfs call, and there are ***O(N)*** dfs calls in total.

* Space complexity: ***O(N)*** since we need spaces of ***O(N)*** to store the result of dfs.

## Approach 2: DP
### Intuition

DFS with memorization is very similar to dp. We can also use dp to solve this problem.

We can just use a single `dp[i]` array to store whether the player now removing stones wins with `i` stones remaining.

### Algorithm

Let `dp[i]` represents the result of the game with `i` stones. `dp[i]==True` means the current player must win, and `dp[i]==False` means the current player must lose, when both players play optimally.

The next step is to find out how to calculate `dp[i]`.

We can iterate all possible movements, and check if we can move to a False state. If we can, then we found a must-win strategy, otherwise, we must lose since the opponent has a must-win strategy in this case.

More clearly, we can iterate k from 0 and check if there exists `dp[i - k * k]==False`. Of course, `i - k*k >= 0`.

Finally, we only need to return `dp[n]`.

>Note: After reading the Algorithm part, it is recommended to try to write the code on your own before reading the solution code.

### Java
```java
class Solution {
    public boolean winnerSquareGame(int n) {
        boolean[] dp = new boolean[n + 1];
        for (int i = 0; i < n + 1; i++) {
            for (int k = 1; k * k <= i; k++) {
                if (dp[i - k * k] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}
```

### Python
```python
class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [False]*(n+1)
        for i in range(1, n+1):
            for k in range(1, int(i**0.5)+1):
                if dp[i-k*k] == False:
                    dp[i] = True
                    break
        return dp[n]
```

Also, we can employ DP in a slightly different way.

### Intuition

Let's think in the backtrack way. If we have a state `i` that we know the current player must lose, what can we infer?

-- Any other states that can go to `i` must be `True`.

Let's say in another state `j` the current player in `j` can go to `i` by removing stones. In this case, the state `j` is `True` since the current player must win.

How to find all the state `j`? Well, we can iterate over the square numbers and add them to `i`.

### Algorithm

Still, let `dp[i]` represent the result of the game of i stones. `dp[i]==True` means the first player (Alice) must win, and `dp[i]==False` means the second player (Bob) must win when both players play optimally.

When we get to a `False` state, we mark all accessible states as `True`. When we get to a True state, just continue (Why? Well... because it's useless).

Finally, we only need to return `dp[n]`.

>Note: After reading the Algorithm part, it is recommended to try to write the code on your own before reading the solution code.

### Java
```java
class Solution {
    public boolean winnerSquareGame(int n) {
        boolean[] dp = new boolean[n + 1];
        for (int i = 0; i <= n; i++) {
            if (dp[i]) {
                continue;
            }
            for (int k = 1; i + k * k <= n; k++) {
                dp[i + k * k] = true;
            }
        }
        return dp[n];
    }
}
```

### Python3
```python
class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [False]*(n+1)
        for i in range(n+1):
            if dp[i]:
                continue
            for k in range(1, int(n**0.5)+1):
                if i+k*k <= n:
                    dp[i+k*k] = True
                else:
                    break
        return dp[n]
```

### Complexity Analysis

Assume ***N*** is the length of `arr`.

* Time complexity: ***O(N sqrt(N))***since we iterate over the `dp` array and spend ***O(sqrt(N))*** at most on each element.

* Space complexity: ***O(N)*** since we need a `dp` array.

## [Python] DP solution, using game theory, explained
In this problems we have game with two persons, and we need to understand who is winning, if they play with optimal strategies. In this game at each moment of time we have several (say `k`) stones, and we say that it is **position** in our game. At each step, each player can go from one position to another. Let us use classical definitions:

1. The empty game (the game where there are no moves to be made) is a losing position.
A position is a winning position if at least one of the positions that can be obtained from this position by a single move is a losing position.
A position is a losing position if every position that can be obtained from this position by a single move is a winning position.
Why people use definitions like this? Imagine that we are in winning position, then there exists at least one move to losing position (property 2), so you make it and you force your opponent to be in loosing position. You opponent have no choice to return to winning position, because every position reached from losing position is winning (property 3). So, by following this strategy we can say, that for loosing positions Alice will loose and she will win for all other positions.

So, what we need to check now for position state: all positions, we can reach from it and if at least one of them is False, our position is winning and we can immedietly return True. If all of them are True, our position is loosing, and we return False. Also we return False, if it is our terminal position.

Complexity: For each of n positions we check at most sqrt(n) different moves, so overall time complexity is O(n sqrt(n)). Space complexity is O(n), we keep array of length n.

class Solution:
    def winnerSquareGame(self, n):
        
        @lru_cache(None)
        def dfs(state):
            if state == 0: return False
            for i in range(1, int(math.sqrt(state))+1):
                if not dfs(state - i*i): return True
            return False
        
        return dfs(n)