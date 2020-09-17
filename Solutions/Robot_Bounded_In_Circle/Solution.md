# LeetCode Robot Bounded In Circle
## [Python] O(n) solution, explained

Let **dx, dy** be directions of our robot and **x,y** be its coordinates. Then using linear algepra we can say that if we rotate to the left, then **dx, dy = -dy, dx**, similar if we rotate to the right. So, now we can easily follow the place of our robot. How to understand if his path will be bounded by some circle? We need to understand if he is going to loop. There are **3** possible options where path will be bounded.

1. In the end it will arrive to the starting position.
2. It will not arrive to the starting position and his orientation is rotated to the left or to the right. Then it can be shown easily that after 4 loops robot will return to the original place.
3. It will not arrive to the start and his orientation is opposite, then after **2** loops he will arrive at the starting place.

So, let us just check that after **4** times we traverse our **instructions** robot will be at the start, that is all!

**Complexity:** Time complexity is **O(4n)**, space complexity is **O(1)**.

```python
class Solution:
    def isRobotBounded(self, instructions):
        dx, dy, x, y = 0, 1, 0, 0
        for l in 4*instructions:
            if l == "G": 
                x, y = x+dx, y+dy
            elif l == "L":
                dx, dy = -dy, dx
            else:
                dx, dy = dy, -dx
                
        return (x,y) == (0,0)
```

**PS** I realized that we do not really need to traverse **instructions** 4 times, we can just return **(x,y) == 0 or (dx, dy) != (0,1)**, but this solution was already provided by others, so I left my solution as it is.

[Link to original post](https://leetcode.com/problems/robot-bounded-in-circle/discuss/850437/Python-O(n)-solution-explained)

## [C++] Simple Solution Explained, 100% Time, ~60% Space

The intuition to solve this problem is that our finite state machine is going to be in a cyclical condition in 2 cases:

* it does not move at the end of the tick;
* it points in a different direction.

In order to verify that, we set a few variables:

* **dir**, representing our direction in a **0 - 3** range, initially set to **0** (North);
* **x** and **y**, both initialised to **0** and meant to register the overall movement from the start;
* **moves** an array of updates associated with movements for different values of **dir**, which I admitted doing just to avoid having to type 4 different conditionals to update the coordinates, sacrificing a bit more of memory.

Then we parse through the string of commands character by character, updating either **dir** (for either **'L'** or **'G'**) or **x** and **y** (for **'G'**) as we go.

At the end, I return if the robot either did not move at all at the end of the turn (both **x** and **y** are **0**) or if did not change its direction (**dir** is still set to **0**) :)

The code:
```c++
class Solution {
public:
    bool isRobotBounded(string instructions) {
        // dir 0 => N, 1 => W, 2 => S, 3 => E
        int dir = 0, x = 0, y = 0,
		// moving N, W, S and E
		moves[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        for (char c: instructions) {
            switch(c) {
                // going forward
				case 'G':
                    // updating the coordinates
					x += moves[dir][0];
                    y += moves[dir][1];
                    break;
                // turning left
				case 'L':
                    dir = (dir + 3) % 4;
                    break;
                // turning right
                case 'R':
                    dir = (dir + 1) % 4;
                    break;
            }
        }
        // return if it didn't move or didn't turn
		return !x && !y || dir;
    }
};
```

[Link to original post](https://leetcode.com/problems/robot-bounded-in-circle/discuss/850427/C%2B%2B-Simple-Solution-Explained-100-Time-~60-Space)