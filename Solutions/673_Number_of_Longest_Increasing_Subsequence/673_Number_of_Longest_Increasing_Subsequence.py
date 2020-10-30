#Second fastest
class Solution:
    def findNumberOfLIS(self, nums):
        if not nums: return 0
        n = len(nums) + 1
    
        decks, ends_decks, paths = [[] for _ in range(n)], [float("inf")]*n, [[0] for _ in range(n)]
        for num in nums:
            idx = bisect.bisect_left(ends_decks, num)
            n_paths = 1
            if idx > 0:
                l = bisect.bisect(decks[idx-1], -num)
                n_paths = paths[idx-1][-1] - paths[idx-1][l]
            
            decks[idx].append(-num)
            ends_decks[idx] = num
            paths[idx].append(n_paths + paths[idx][-1])
                
        return paths[paths.index([0]) - 1][-1]

#Fastest
class Solution:
    def findNumberOfLIS(self, nums):
        if not nums: return 0
    
        decks, ends_decks, paths = [], [], []
        for num in nums:
            deck_idx = bisect.bisect_left(ends_decks, num)
            n_paths = 1
            if deck_idx > 0:
                l = bisect.bisect(decks[deck_idx-1], -num)
                n_paths = paths[deck_idx-1][-1] - paths[deck_idx-1][l]
                
            if deck_idx == len(decks):
                decks.append([-num])
                ends_decks.append(num)
                paths.append([0,n_paths])
            else:
                decks[deck_idx].append(-num)
                ends_decks[deck_idx] = num
                paths[deck_idx].append(n_paths + paths[deck_idx][-1])
                
            #print(decks)
            #print(paths)
            #print("@@@@@")
                
        return paths[-1][-1]