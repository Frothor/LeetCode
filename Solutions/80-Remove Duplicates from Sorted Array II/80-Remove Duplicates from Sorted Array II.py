#Fourth fastest
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
      count, i = 1, 1
      while i < len(nums):
        count = count + 1 if nums[i] == nums[i-1] else 1
        if count > 2: nums.remove(nums[i])
        else: i += 1
      # print(nums)
      return i

#Third fastest
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        check_index = 0
        i = 1
        count = 0
        
        while i < len(nums):
            if nums[check_index] == nums[i]:
                count += 1
                
                if count > 1:
                    nums.remove(nums[i])
                    count -= 1
                    i -= 1
                i += 1
            else:
                check_index = i
                i = check_index + 1
                count = 0            
          
        return len(nums)

#Second fastest
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        j = 0
        count = 0
        for i in range(1, len(nums)):
            if nums[i] == nums[j]:
                count += 1
                if count < 2:
                    j += 1
                    nums[j], nums[i] = nums[i], nums[j]
            else:
                j += 1
                nums[j], nums[i] = nums[i], nums[j]
                count = 0
        return j+1

#Fastest
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        j, count = 1,1
        
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                count += 1
            else:
                count = 1
                
            if count <= 2:
                nums[j] = nums[i]
                j+=1
        print("length is: ",j)        
        return j