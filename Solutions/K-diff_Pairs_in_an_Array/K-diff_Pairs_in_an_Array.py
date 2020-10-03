class Solution:
    def findPairs(self, nums, k):
        count = Counter(nums)
        if k > 0:
            res = sum([i + k in count for i in count])
        else:
            res = sum([count[i] > 1 for i in count])
        return res

#Fastest
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k != 0:
            s = set(nums)
            ans = 0
            for i in s:
                if i-k in s: ans += 1
            return ans
        else:
            s = set()
            used = set()
            ans = 0
            for i in nums:
                if i in s and i not in used: 
                    ans += 1
                    used.add(i)
                else: s.add(i)
            return ans
                