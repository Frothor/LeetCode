#Fourth fastest
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ans = []
        
        if not nums:
            return ans
        
        count = 1
        
        for i in range(1, len(nums)):
            if nums[i - 1] + 1 == nums[i]:
                count += 1
            else:
                ans.append((str(nums[i - 1] - count + 1) + "->" if count > 1 else "" ) + str(nums[i - 1]))
                count = 1
                
        ans.append((str(nums[-1] - count + 1) + "->" if count > 1 else "" ) + str(nums[-1]))
        return ans

#Third fastest
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:

#         #Solution#1
#         ans = []
        
#         if (len(nums) == 0): return ans
        
#         start, end = 0, 0
#         for end in range(1, len(nums)):
#             # print("%d~%d" % (start, end))
#             if (nums[start] + (end-start) != nums[end]):
#                 if (start==end-1):
#                     ans.append("%d" % nums[start])
#                 else:
#                     ans.append("%d->%d" % (nums[start], nums[end-1]))
#                 start = end
        
#         # print("%d~%d" % (start, end))
#         if (start==end):
#             ans.append("%d" % nums[start])
#         else:
#             ans.append("%d->%d" % (nums[start], nums[end]))
            
#         return ans
    
        #Solution#1v2
        ans = []
        l = len(nums)
        if (l == 0): return ans
        start = 0
        for end in range(l+1):
            #print("%d~%d" % (start, end))
            if (end == l or 
                nums[start] + (end-start) != nums[end]):
                if (start==end-1): 
                    ans.append("%d" % nums[start])
                else: 
                    ans.append("%d->%d" % (nums[start], nums[end-1]))
                start = end
        return ans

#Second fastest
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ans = []
        if len(nums) == 0:
            return ans
        if len(nums) == 1:
            return [str(nums[0])]
        
        start = nums[0]
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1] + 1:
                if start == nums[i - 1]:
                    ans.append(str(nums[i - 1]))
                else:
                    ans.append(str(start) + '->' + str(nums[i - 1]))
                start = nums[i]
            if i == len(nums) - 1:
                if start == nums[i]:
                        ans.append(str(start))
                else:
                    ans.append(str(start) + '->' + str(nums[i]))                
            
        return ans

#Fastest
def makeRange(ci, cj):
    if ci == cj:
        return str(ci)
    else:
        return f"{ci}->{cj}"

class Solution:
    
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        
        idx, ci, cj = nums[0]-1, nums[0], nums[0]
        res = []
        
        for n in nums:
            if n != (idx+1):
                res.append(makeRange(ci, cj))
                ci = idx = n
            else:
                idx += 1
            cj = n
        
        res.append(makeRange(ci, cj))
        return res