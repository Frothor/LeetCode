class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def dfs(ind, built):
            if ind == len(nums):
                ans.append(built)
                return

            stop = built.index(nums[ind]) if nums[ind] in built else ind
            
            for i in range(stop+1):
                dfs(ind+1, built[:i]+[nums[ind]]+built[i:])

        ans = []
        dfs(0, [])  
        return ans

#Third fastest
class Solution:
    from collections import deque
    import itertools
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return [nums]
        ret = [deque([nums[0]])]
        for val in itertools.islice(nums, 1, None):
            ret = self.join_perm(ret,val)
        return [list(x) for x in ret]

    def join_perm(self, perms, val):
        ret = set()
        for iq in perms:
            for i in range(len(iq)+1):
                if i >0 and val == iq[i-1]:
                    continue
                q = deque(iq)
                q.insert(i, val)
                ret.add(tuple(q))
        del perms
        return ret

#Second fastest
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def dfs(nums, start):
            if start >= len(nums):
                res.append(nums)
                return
            for i in range(start, len(nums)):
                if i > start and nums[i] == nums[start]:
                    continue
                nums[i], nums[start] = nums[start], nums[i]
                dfs(nums.copy(), start + 1)
                #nums[i], nums[start] = nums[start], nums[i]
        res = []
        nums.sort()
        dfs(nums, 0)
        return res

#Fastest
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for x in nums:
            # only insert up to the first occurrence rest.index(head)
            # because any slot after the first occurrence can be thought as 
            # the duplicate of the first occurrence as the inserted element 
            # and the slot being the existing one.
            res = [path[:i] + [x] + path[i:] for path in res for i in range((path + [x]).index(x) + 1)]

        return res