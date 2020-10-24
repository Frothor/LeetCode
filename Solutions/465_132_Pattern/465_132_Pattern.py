class Solution:
    def find132pattern(self, nums):
        min_list = list(accumulate(nums, min))
        stack, n = [], len(nums)
        
        for j in range(n-1, -1, -1):
            if nums[j] > min_list[j]:
                while stack and stack[-1] <= min_list[j]:
                    stack.pop()
                if stack and stack[-1] < nums[j]:
                    return True
                stack.append(nums[j])           
        return False

#Another fast
'''
[-1,3,2,0]
[3,1,4,2]
[1,2,3,4]
'''

class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        
        N = len(nums)
        
        stack = []
        
        middle = -float('inf')
        
        for val in nums[::-1]:
            if val < middle:
                return True
            
            while stack and stack[-1] < val:
                middle = stack.pop()
                
            stack.append(val)
        return False