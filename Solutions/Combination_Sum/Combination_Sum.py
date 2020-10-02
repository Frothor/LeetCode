class Solution:
    def combinationSum(self, candidates, target):
        def BackTr(target, curr_sol, k):  
            if target == 0:
                self.sol.append(curr_sol)

            if target < 0 or k >= len(candidates):
                return

            for i in range(k, len(candidates)):
                BackTr(target - candidates[i], curr_sol + [candidates[i]], i)
        
        self.sol = []
        BackTr(target, [], 0)   
        return self.sol

#Most common
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        n = len(candidates)
        def dfs(cur, start, target):
            # base case
            if target == 0:
                res.append(cur[:])
                return
            
            for i in range(start, n):
                if candidates[i] > target:
                    return
                    
                cur.append(candidates[i])
                dfs(cur, i, target - candidates[i])
                cur.pop()
                
                
        candidates.sort()
        dfs([], 0, target)
        return res

#Second Fastest
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = [set() for _ in range(target + 1)]
        res[0].add(())
        for num in candidates:
            for off in range(0, target - num + 1):
                for seq in res[off]:
                    res[num + off].add(seq + (num,))
        return res[target]
        
        # candidates.sort()
        # res = []
        # def subSum(prefix, target, i):
        #     if (i < len(candidates)) and (target >= candidates[i]):
        #         subSum(prefix, target, i + 1)
        #         subSum(prefix + [candidates[i]], target - candidates[i], i)
        #     if target == 0: res.append(prefix)
        # subSum([], target, 0)
        # return res

#Fastest
class Solution:
    def recursor(self, target, order, index):
        for i, x in enumerate(self.candidates[index :]):
            if target >= 2 * x:
                self.recursor(target - x, order + [x], index + i)
            elif x == target:
                self.ans.append(order + [x])
            elif x > target:
                break

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.ans = []
        self.candidates = sorted(candidates)
        self.recursor(target, [], 0)
        return self.ans
