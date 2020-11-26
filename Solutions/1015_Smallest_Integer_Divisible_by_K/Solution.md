# LeetCode Medium 1015. Smallest Integer Divisible by K
## Overview
It's an interesting problem that requires a little observation and insight. It's recommended to try a few numbers to find out some regular patterns. Below, we will discuss a simple approach to solve this problem.

## Approach 1: Checking Loop
### Intuition

We need to do two things:

1. check if the required number N exists.
2. find out `length(N)`.

The second one is easy: we only need to keep multiplying `N` by 10 and adding 1 until `N%K==0`. However, since `N` might overflow, we need to use the remainder. The pseudo-code is as below:
```
remainder = 1
length_N = 1

while remainder%K != 0
    N = remainder*10 + 1
    remainder = N%K
    length_N += 1

return length_N
```
Since the `remainder` and `N` have the same remainder of `K`, it OK to use `remainder` instead of `N`.

Now, the only problem is how to check whether the required number `N` exists.

Notice that if `N` does not exist, this while-loop will continue endlessly. However, the possible values of remainder are limited -- ranging from `0` to `K-1`. Therefore, if the while-loop continues forever, the `remainder` repeats. Also, if `remainder` repeats, then it gets into a loop. Hence, the while-loop is endless if and only if the `remainder` repeats.

In this case, we can check if the `remainder` repeats to check if the while-loop is endless:
```
remainder = 1
length_N = 1

seen_remainders = set()

while remainder%K != 0
    N = remainder*10 + 1
    remainder = N%K
    length_N += 1

    if remainder in seen_remainders
        return -1
    else
        seen_remainders.add(remainder)

return length_N
```
Now we have an algorithm that can solve the problem.

Furthermore, we can improve this algorithm with [Pigeonhole Principle](https://en.wikipedia.org/wiki/Pigeonhole_principle). Recall that the number of possible values of `remainder` (ranging from `0` to `K-1`) is limited, and in fact, the number is `K`. As a result, if the while-loop continues more than `K` times, and haven't stopped, then we can conclude that `remainder` repeats -- you can not have more than `K` different `remainder`.

Hence, if `N` exists, the while-loop must return `length_N` in the first `K` loops. Otherwise, it goes into an infinite loop.

Therefore, we can just run the while-loop `K` times, and return -1 if not stopped.

### Algorithm

We just run the while-loop `K` times, check if the remainder is 0, and return -1 if not stopped.

>Note: After reading the Algorithm part, it is recommended to try writing the code on your own before reading the solution code.

#### Java
```java
class Solution {
    public int smallestRepunitDivByK(int K) {
        int remainder = 0;
        for (int length_N = 1; length_N <= K; length_N++) {
            remainder = (remainder * 10 + 1) % K;
            if (remainder == 0) {
                return length_N;
            }
        }
        return -1;
    }
}
```

#### Python
```python
class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        remainder = 0
        for length_N in range(1,K+1):
            remainder = (remainder*10+1) % K
            if remainder == 0:
                return length_N
        return -1
```

There are a few interesting points worth pointing out in the code above:

1. We initialize `remainder` to 0, not 1, to keep code consistency because in the first loop the `remainder` changes to 1. You can also initialize it as 1, but it requires a little change in code.
2. We only run the loop `K` times at most, not `K+1`. This is because if it does not stop in the previous `K` loop, it will continue the `K+1-th` iteration, which must have repeated remainder. Therefore, it is not necessary to check the `K+1-th` iteration.

Also, note that `111...111` can never be divided by 2 or 5 because its last digit is never an even number or 5. You can just return -1 if you find that 2 or 5 is a factor of `K`.

### Complexity Analysis

* Time Complexity : ***O(K)*** since we at most run the loop ***O(K)*** times.

* Space Complexity : ***O(1)*** since we only use three ints: `K`, remainder, and `length_N`.

## [Python] Math, Pigeon holes, explained
First of all, let us notice, that if number is divisible by `2` or by `5`, then we need to return `-1` immediatly, because number ending with `1` can not divide by `2` or `5`. From now on we assume, that `K` is not divisible by `2` or `5`. Let us consider numbers:

`1`
`11`
`111`
`...`
`111...111`,

where were have `K` ones in the last group. Then, there can be only two cases:

1. All reminders of given numbers when we divide by `K` are different.
2. Some two reminders are equal.

In the first case, we have `K` numbers and also `K` possible reminders and they are all different, it means, that one of them will be equal to `0`.

In the second case, two numbers have the same reminder, let us say number `11...1111` with `a` ones and `111...11111` with `b` ones, where `b > a`. Then, difference of these two numbers will be divisible by `K`. What is the difference? It is number `11...1100...000` with `b-a` ones and `a` zeroes at the end. We already mentioned that `K` is not divisible by `2` or `5` and it follows, that `11...111` divisible by `K` now, where we have `b-a` ones.

So, we proved the following statements: **if K not divisible by 2 and 5, then N <= K**. What we need to do now is just iterate through numbers and stop when we find number divisible by `K`. To simplify our cumputation, we notice, that each next number is previous multiplied by `10` plus `1`.

**Complexity:** time complexity is `O(n)`, space is `O(1)`.
```python
class Solution(object):
    def smallestRepunitDivByK(self, K):
        if K % 2 == 0 or K % 5 == 0: return -1
        rem, steps = 1, 1
        while rem % K != 0:
            rem = (rem*10 + 1) % K
            steps += 1
        return steps
```

[Link to original post](https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/948435/Python-Math-Pigeon-holes-explained)