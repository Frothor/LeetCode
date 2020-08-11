# LeetCode H-Index Solution
## Solution 1 - Binary search
So, in order to meet the requirement of this problem, we need to find a way to meet the N - h condition described in the specs, and for the maximum possible value.

Well, that seems to me like a good use case of binary search and, since the problem boils down to this, I would not even bother to use the built-in C++ functions for that (lower_bound or, rather. upper_bound, but it really depends on how you play with them here).

Also, it is rather likely that in an interview you will be asked to avoid them and write your own logic, so I see no reason not to practice it here, not to mention that with the built in solutions you would have needed another vector to also store the respective index of each element (not sure you can otherwise access them, but correct me if I am wrong).

First of all I will need 3 support variables to store the coordinates of my current start (s), end (e) and average (avg), respectively, and (have to) sort my array for the BS (I mean Binary Search!) to work.

Then I will move on with it as long as my current start is <= current my end; if the condition is met (c[avg = (e + s) / 2] < c.size() - avg), then we move right (ie: towards higher values, since we sorted) updating s, otherwise we move left, updating e (ie: to lower values).

Once we have found our ideal value, we returrn c.size - s and we are done :)

The code:
```c++
class Solution {
public:
    int hIndex(vector<int>& c) {
        // 3 support variables for us
        int s = 0, e = c.size() - 1, avg;
        // the base of every happy binary search ever: having a sorted dataset
        sort(begin(c), end(c));
        // some good old binary search here to find the maximum element meeting the conditions
        while (s <= e) {
            if (c[avg = (e + s) / 2] < c.size() - avg) s = avg + 1;
            else e = avg - 1;
        }
        return c.size() - s;
    }
};
```

[Link to original post](https://leetcode.com/problems/h-index/discuss/785444/C%2B%2B-Clean-and-Simple-Binary-Search-based-Solution-Explained-~92-Time-~80-Space)

## Solution 2 - O(n): Bucket Approach

This approach **does not involve sorting** of the array, which would result in the solution being nlog n. *Hence, the overall complexity of the solution would be* ***O(n)***.
We take a bucket array of size n + 1, where n being the size of the given array.

The idea is to store the frequency of elements of the input array. If however we get a value which is larger than the size of the array, that itself won't be a candidate for h-index, so we store it at the last index value. Otherwise we just store those values at the index value. Here is an implementation.

```python
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        bucket = [0] * (len(citations) + 1)
        
        for i in range(len(citations)):
            if citations[i] > len(citations):
                bucket[len(citations)] += 1
            else:
                bucket[citations[i]] += 1
                
        count = 0
        for i in range(len(bucket) - 1, -1, -1):
            count += bucket[i]
            if count >= i:  #  If the value of count is greater than the index value then we return the index
                return i
        
        return 0  # If no such index is found then we simply return 0
```

The approach runs only twice, so the overall worst case scenario of the solution would be **O(n)**.

[Link to original post](https://leetcode.com/problems/h-index/discuss/786206/O(n)%3A-Bucket-Approach)

## Solution 3 and 4

### Solution 1: O(NlogN) sorting soltuion
```c++
class Solution {
public: //Time/Space: O(NlogN); O(1)
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend()); // descending order
        int ans = 0;
        for(int i = 0; i < citations.size(); i++) // linear search
            if(citations[i]>i) ans++;        
        return ans;        
    }
};
```

### Solution 2: O(N) counting sorting soltuion
Ref: https://leetcode.com/problems/h-index/solution/
```c++
class Solution { // Counting sort
public: // Time/Space: O(N); O(N)
    int hIndex(vector<int>& citations) {
        const int n = citations.size();
        vector<int> paper(n+1); // paper[i]: # of paper with i-citation
        for(int c: citations) paper[min(n, c)]++; // compress range with cutting-off trick, then count
        int k = n;
        for(int s = paper[k]; k > s; s += paper[k]) k--;
        return k; // when hit here: k <= s, then k is the answer, i.e., h-index
    }
};
```

[Link to original post](https://leetcode.com/problems/h-index/discuss/786007/C%2B%2B-not-all-sorting-are-equal%3A-O(NlogN)-vs-O(N))

## Solution 5 - Similar to Solution 1
```c++
class Solution {
public:
    int hIndex(vector<int>& citations) {
		// Sorting it so that 
        sort(citations.begin(), citations.end(), greater<int>());
		// while going from left to right, H-index will increase and will be matched with the decreasing no. of citations for the paper
        for(int i = 0; i < citations.size(); i++)
		// the index at which H-index (i in this case) becomes >= to no. of citations at [i], it means the H - index cannot be greater than current i 
            if(i >= citations[i]) {
				// return i due to 0 - based indexing
                return i;
            }
		//  when smallest value citation is > the total no. of citations on the paper (i.e. its size)
        return citations.size();
    }
};
```
[Link to original post](https://leetcode.com/problems/h-index/discuss/785493/Clean-C%2B%2B-solution)