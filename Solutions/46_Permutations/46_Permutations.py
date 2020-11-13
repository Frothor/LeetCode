#Fourth fastest
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        ans = [[]]
        for x in nums:
            new_ans = []
            for cur in ans:
                for k in range(len(cur) + 1):
                    copy = cur[:]
                    copy.insert(k, x)
                    new_ans.append(copy)
            ans = new_ans
        return ans

#Third fastest
import itertools
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return list(itertools.permutations(nums))


#Second fastest
class Solution(object):
    def permute(self, nums):
        def recur(i, s, vis):
            if i>=0:
                vis[i] = True
                s += str(nums[i]) + ' '
            if len(s.split())==len(nums):
                res.add(s)
                return
            for j in range(len(nums)):
                if not vis[j]:
                    recur(j, s, copy.deepcopy(vis))
        
                    
        res = set()
        recur(-1, '', [False]*len(nums))
        return [[int(e) for e in s.split()] for s in res]

#Fastest
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        # backtraking
        # Time: O(n!)
        # Space: O(n)
        res = []
        
        if not nums:
            return res
        
        self.backtrack(nums, res, [])
        return res
    
    def backtrack(self, nums, res, path):
        if not nums:
            res.append(path)
            return 
        for i in range(len(nums)):
            self.backtrack(nums[:i]+nums[i+1:], res, path+[nums[i]])