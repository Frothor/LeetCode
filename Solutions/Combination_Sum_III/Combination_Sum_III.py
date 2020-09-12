#Most commmon
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]: 
        ans = []
        self.dfs(k, n, ans, [], 1)
        return ans
    
    def dfs(self, k, n, ans, rslt, i):
        if len(rslt) == k:
            if sum(rslt) == n:
                ans.append(rslt)
            return

        for j in range(i, 10):
            self.dfs(k, n, ans, rslt + [j], j + 1)

#Fastest
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        
        res = []
        self.dfs(range(1,10), k, n, 0, [], res)
        return res

    def dfs(self, nums, k, n, index, path, res):
        if k < 0 or n < 0: # backtracking 
            return 
        if k == 0 and n == 0: 
            res.append(path)
        for i in range(index, len(nums)):
            self.dfs(nums, k-1, n-nums[i], i+1, path+[nums[i]], res)
