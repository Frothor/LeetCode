# LeetCode 735 Asteroid Collision Solution
## Approach #1: Stack [Accepted]
### Intuition

A row of asteroids is stable if no further collisions will occur. After adding a new asteroid to the right, some more collisions may happen before it becomes stable again, and all of those collisions (if they happen) must occur right to left. This is the perfect situation for using a *stack*.

### Algorithm

Say we have our answer as a stack with rightmost asteroid `top`, and a `new` asteroid comes in. If new is moving right (`new > 0`), or if `top` is moving left (`top < 0`), no collision occurs.

Otherwise, if `abs(new) < abs(top)`, then the new asteroid will blow up; if `abs(new) == abs(top)` then both asteroids will blow up; and if `abs(new) > abs(top)`, then the top asteroid will blow up (and possibly more asteroids will, so we should continue checking.)

### Java
```java
class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack();
        for (int ast: asteroids) {
            collision: {
                while (!stack.isEmpty() && ast < 0 && 0 < stack.peek()) {
                    if (stack.peek() < -ast) {
                        stack.pop();
                        continue;
                    } else if (stack.peek() == -ast) {
                        stack.pop();
                    }
                    break collision;
                }
                stack.push(ast);
            }
        }

        int[] ans = new int[stack.size()];
        for (int t = ans.length - 1; t >= 0; --t) {
            ans[t] = stack.pop();
        }
        return ans;
    }
}
```

### Python
```python
class Solution(object):
    def asteroidCollision(self, asteroids):
        ans = []
        for new in asteroids:
            while ans and new < 0 < ans[-1]:
                if ans[-1] < -new:
                    ans.pop()
                    continue
                elif ans[-1] == -new:
                    ans.pop()
                break
            else:
                ans.append(new)
        return ans
```

### Complexity Analysis

* Time Complexity: ***O(N)***, where ***N*** is the number of asteroids. Our stack pushes and pops each asteroid at most once.

* Space Complexity: ***O(N)***. We use a stack to keep track of the intermediate results. In the worst case, the states do not evolve at the end, i.e. we need ***O(N)*** space where ***N*** is the number of input asteroids.