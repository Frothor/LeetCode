class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        def inverse(i, j):
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i, j = i + 1, j - 1
        
        n = len(nums)
        k = k % n
        inverse(0, n-1)
        inverse(0, k-1)
        inverse(k, n-1)
        return nums

#Fourth fastest
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        ret = [nums[i] for i in range(len(nums))] 
        
        for i in range(len(nums)):
            nums[(i + k)% len(nums)] = ret[i]
                
        
        
#         k = k % len(nums)
        
#         if not k:
#             return nums
        
#         visited = 0 
#         ptr = 0
#         temp = None
        
#         while visited < len(nums):
#             if temp == None:
#                 temp = nums[ptr]
#             else:
#                 temp2 = nums[ptr]
#                 nums[ptr] = temp
#                 temp = temp2
            
#             ptr = (ptr + k) % len(nums)
#             visited += 1

#Third fastest
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if k == 0:
            return
        
        # if k is greater than the length of the list we don't need to 
        #rotate through the whole thing to get the desired result
        if k > len(nums):
            k = k % len(nums)
            
        prepend = nums[-k:]
        nums[-k:], nums[0:0] = [], prepend


#Second fastest
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k = k % n
        nums[:] = nums[n - k:] + nums[:n - k]

#Fastest
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        a = nums[len(nums)-k:]
        a += nums[0: len(nums) - k]
        nums[:] = a