# LeetCode Largest Component Size by Common Factor Solution
## Solution 1 - [Python] Union find solution, explained
If you try to run usual dfs/bfs on this problem, you will get TLE, so we need to think something smarter. Note, that if two numbers has common factor more than 1, it means that they have **prime** common factor. So, let us for example consider all even numbers: they all have prime common factor **2**, so we can immediatly say, that they should be in the same group. Consider all numbers which are divisible by **3**, they also can be put in the same group. There is special data stucture: Disjoint set (https://en.wikipedia.org/wiki/Disjoint-set_data_structure), which is very suitable for these type of problems.

Let us consider example **[2,3,6,7,4,12,21,39]** an go through my code:

1. **primes_set(self,n)** return set of unique prive divisors of number **n**, for example for **n = 12** it returns set **[2,3]** and for **n=39** it returns set **[3,13]**.
2. Now, what is primes defaultdict? For each found prime, we put indexes of numbers from **A**, which are divisible by this prime. For our example we have: **2: [0,2,4,5], 3:[1,2,5,6,7], 7:[3,6], 13:[7]**. So, what we need to do now? We need to union **0-2-4-5**, **1-2-5-6-7** and **3-6**.
3. That exaclty what we do on the next step: iterate over our **primes** and create connections with **UF.union(indexes[i], indexes[i+1])**
4. Finally, when we made all connections, we need to find the biggest group: so we find parent for each number and find the bigges frequency.

**Complexity**: this is interesting part. Let **n** be length of **A** and let **m** be the biggest possible number. Function **primes_set** is quite heavy: for each number we need to check all numbers before its square root (if number is prime we can not do better with this approach), so complexity of **primes_set** is **O(sqrt(m))**. We apply this function n times, so overall complexity of this function will be **O(n * sqrt(m))**. We also have other parts of algorithm, where we put prime numbers to dictionary, complexity will be **O(n * log(m))** at most, because each number has no more, than **log(m)** different prime divisors. We also have the same number of **union()** calls, which will work as **O(1)** if we use it with ranks, and slower if we use it without ranks as I did, but still fast enough to be better than our bottleneck: O(n*sqrt(m)) complexity for prime factors generation. That is why I use Union Find without ranks: if you want to improve algorighm, you need to deal with **primes_set()** function.
Space complexity is **O(n*log(m))** to keep all prime factors and to keep our **DSU** data structure.

```python
class DSU:
    def __init__(self, N):
        self.p = list(range(N))

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        self.p[xr] = yr

class Solution:
    def primes_set(self,n):
        for i in range(2, int(math.sqrt(n))+1):
            if n % i == 0:
                return self.primes_set(n//i) | set([i])
        return set([n])

    def largestComponentSize(self, A):
        n = len(A)
        UF = DSU(n)
        primes = defaultdict(list)
        for i, num in enumerate(A):
            pr_set = self.primes_set(num)
            for q in pr_set: primes[q].append(i)

        for _, indexes in primes.items():
            for i in range(len(indexes)-1):
                UF.union(indexes[i], indexes[i+1])

        return max(Counter([UF.find(i) for i in range(n)]).values())
```

[Link to original post](https://leetcode.com/problems/largest-component-size-by-common-factor/discuss/819919/Python-Union-find-solution-explained)