# LeetCode Contains Duplicate III Solution

## [C++] O(N) time complexity | Explained | Buckets | O(K) space complexity
### Explanation

We use the concept of sliding window and buckets together to achieve an optimal solution with O(N) time complexity.

Sliding window ensures only those indices are considered whose the absolute difference is at most k. We only consider k indices at a time. This fulfills the second condition.

Buckets are used to ensure that the absolute difference between two numbers is at most t. Let's take a deeper look at them.
We (floor) divide each number by t+1 and put it in a bucket with key as the quotient.
For example,
```
[1,5,2,4,3,9,1,5,9], k = 2, t = 3

1 // (3+1) = 0
5 // (3+1) = 1
2 // (3+1) = 0
4 // (3+1) = 1
3 // (3+1) = 0
9 // (3+1) = 2

Here, Bucket[0] will contain numbers 0,1,2,3.
Bucket[1] will contain numbers 4,5,6,7.
Bucket[2] will contain numbers 8,9,10,11.

On observing carefully, we can see that the absolute difference
between any two numbers in any bucket is at most t, which is what we want.

Also, there can be a case where the neighbouring bucket has some number
whose absolute difference with a number in the current bucket is at most t.
For instance, 2 lies in Bucket[0] and 4 lies in Bucket[1] and 4 - 2 = 2 < 3 (=t).
This can only happen in neighbouring buckets. Therefore, we need to check for this too.
```

### Code
```c++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        
        if(n == 0 || k < 0  || t < 0) return false;
        
        unordered_map<int,int> buckets;
        
        for(int i=0; i<n; ++i) {
            int bucket = nums[i] / ((long)t + 1);
            
			// For negative numbers, we need to decrement bucket by 1
			// to ensure floor division.
			// For example, -1/2 = 0 but -1 should be put in Bucket[-1].
			// Therefore, decrement by 1.
            if(nums[i] < 0) --bucket;
            
            if(buckets.find(bucket) != buckets.end()) return true;
            else {
                buckets[bucket] = nums[i];
                if(buckets.find(bucket-1) != buckets.end() && (long) nums[i] - buckets[bucket-1] <= t) return true;
                if(buckets.find(bucket+1) != buckets.end() && (long) buckets[bucket+1] - nums[i] <= t) return true;
                
                if(buckets.size() > k) {
                    int key_to_remove = nums[i-k] / ((long)t + 1);
                    
                    if(nums[i-k] < 0) --key_to_remove;
                    
                    buckets.erase(key_to_remove);
                }
            }
        }
        
        return false;
    }
};
```

## [Python] SortedList O(n log k) solution, explained.

In my opinion it is more like **hard** problem, because brute-force solution will get you TLE and all other solutions uses some not easy trick: either heaps or BST or bucket sort. If you know some other solution without these ideas, please let me know!

In this problem we need to iterate over window of size **k+1** and check if there is numbers with difference **<=t** in this window. What we need to do efficiently is to add and remove elements from our window, and my choice of data structure is BST, which is implemented in **SortedList** in python. So on each step we have sorted list of elements in this window. Imagine the case:

**[1, 3, 7, 12]** and new number we need to insert is **10**, and **t = 2**. Then we need to consider range **[8,12]** and check if we have numbers in our **SList** in this range. We can do two binary searches here: **bisect_left** for left boundary and **bisect_right** for right boundary. Also we need to check if **pos1 != len(SList)**, if this is the case, it means that new number is bigger than bigges number in list + **t**, so in this case we just put it directly to our list. If **pos1 != pos2**, this means, that we found some number i our **[nums[i] - t, nums[i] + t]** range, so we immediatly return **True**.

**Complexity**: time complexity is **O(n log k)**, because we do **n** steps, each one with **O(log k)** complexity to do binary search, remove and add elements. Space complexity is **O(k)** to keep our **SortedList** updated.

```python
from sortedcontainers import SortedList

class Solution:
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        SList = SortedList()
        for i in range(len(nums)):
            if i > k: SList.remove(nums[i-k-1])   
            pos1 = bisect_left(SList, nums[i] - t)
            pos2 = bisect_right(SList, nums[i] + t)
            
            if pos1 != pos2 and pos1 != len(SList): return True
            
            SList.add(nums[i])
        
        return False
```

**PS** because of time complexity **O(n log k)**, this solution will not be on top, there is **O(n)** bucket sort solution, but in my opinion it is for certain hard level.