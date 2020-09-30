#Third fastest
def second(nums):
    N = len(nums)
    
    nums.append(N + 1)
    for i in range(N):
        if nums[i] < 1 or nums[i] > N:
            nums[i] = N + 1
    
    for i in range(N):
        val = abs(nums[i])
        if nums[val - 1] > 0:
            nums[val - 1] = -nums[val - 1]
        
    for i in range(N):
        if nums[i] > 0:
            return i + 1
        
    return N + 1
        
def first(nums):
    N = len(nums)
    val, index = float('nan'), 0
    
    while index < N:
        if 1 <= val <= N and nums[val - 1] != val:
            nums[val - 1], val = val, nums[val - 1]
        else:
            val = nums[index]
            index += 1
    if 1 <= val <= N:
        nums[val - 1] = val
    
    for i, v in enumerate(nums):
        if i + 1 != v:
            return i + 1
    
    return N + 1

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        return second(nums)

#Second fastest
class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)

        # Base case.
        if 1 not in nums:
            return 1
        '''
        # nums = [1]
        if n == 1:
            return 2
        '''
        # Replace negative numbers, zeros,
        # and numbers larger than n by 1s.
        # After this convertion nums will contain 
        # only positive numbers.
        for i in range(n):
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = 1
        
        # Use index as a hash key and number sign as a presence detector.
        # For example, if nums[1] is negative that means that number `1`
        # is present in the array. 
        # If nums[2] is positive - number 2 is missing.
        for i in range(n): 
            a = abs(nums[i])
            # If you meet number a in the array - change the sign of a-th element.
            # Be careful with duplicates : do it only once.
            if a == n:
                nums[0] = - abs(nums[0])
            else:
                nums[a] = - abs(nums[a])
            
        # Now the index of the first positive number 
        # is equal to first missing positive.
        for i in range(1, n):
            if nums[i] > 0:
                return i
        
        if nums[0] > 0:
            return n
            
        return n + 1

#Fastest
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if nums==[]:
            return 1
        s = set(nums)
        for i in range(1,len(nums)+2): #[1]
            if i not in s:
                return i
                break
                