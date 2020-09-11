[Python] dp solution, explained

#Let dp1[i] be the maximum product which ends with i-th index and dp2[i] be the minimum product which ends with i-the index. Why we need both maximum and minimum? Because we can have big negative number, which then multiplied by negative will give big positive number.
#
#So, let us traverse all numbers and update our dp1 and dp2:

#1.If nums[k] > 0, then biggest number dp1[k] can be obtained from dp1[k-1] * nums[k] or nums[k]. The smallest number dp2[k] is equal to dp2[k-1] * nums[k].
#2.If nums[k] <= 0, then the biggest number is dp1[k] = dp2[k-1] * nums[k] and the smallest number is dp2[k] = min(dp1[k-1] * nums[k], nums[k]).
#3.Finally, we return maximum of dp1.
#4Complexity: both time and space is O(n). Space complexity can be improved to O(1), because we always use only previous elements in our dp1 and dp2 tables.

class Solution:
    def maxProduct(self, nums):
        N = len(nums)
        dp1 = [0] * N
        dp2 = [0] * N
        dp1[0] = dp2[0] = nums[0]
        
        for k in range(1, N):
            if nums[k] > 0:
                dp1[k] = max(dp1[k-1] * nums[k], nums[k])
                dp2[k] = dp2[k-1] * nums[k]
            else:
                dp1[k] = dp2[k-1] * nums[k]
                dp2[k] = min(dp1[k-1] * nums[k], nums[k])
                
        return max(dp1)

#Fastest
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if (len(nums) == 1):
            return nums[0]
        if 0 in nums:
            nums = self.splitByZero(nums)
            products = []
            
            for arr in nums:
                products.append(self.maxProductNoZeros(arr))
                
            products.append(0)
            print(products)
            return max(products)
        else:
            return self.maxProductNoZeros(nums)
            
    def splitByZero(self, nums):
        retArr = [] #2d array
        row = []
        for num in nums:
            if num == 0:
                if len(row) > 0:
                    retArr.append(row)
                    row = []
            else:
                row.append(num)
        if len(row) > 0:
            retArr.append(row)
        return retArr
    
    def maxProductNoZeros(self, nums):        
        if (len(nums) == 1):
            return nums[0]
        
        countNeg = 0
        for num in nums:
            if num < 0:
                countNeg += 1
                
        if (countNeg % 2) == 0:
            #include whole array
            prod = 1
            for num in nums:
                prod *= num
            return prod
        
        #odd number of negatives in array - find whether we should eliminate the last or the first
        elimFirstProd = 1
        i = 0
        while nums[i] > 0 and i < len(nums):
            i += 1
        while i < len(nums)-1:
            i += 1
            elimFirstProd *= nums[i]
            
            
        elimLastProd = 1
        i = len(nums)-1
        while (nums[i] > 0) and i >= 0:
            i -= 1
        while i > 0:
            i -= 1
            elimLastProd *= nums[i]
            
            
        return max(elimFirstProd, elimLastProd)