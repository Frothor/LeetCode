#https://leetcode.com/problems/partition-equal-subset-sum/discuss/950617/Python-Fastest-dp-with-bit-manipulation-explained
class Solution:
    def canPartition(self, A):
        a = reduce(lambda a, num: a|(a<<num), A, 1)
        return sum(A)%2 == 0 and a & (1 << (sum(A)//2)) != 0

#Another
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sumn = sum(nums) 
        if sumn % 2 or len(nums) < 2 :
            return False
        
        subSum = sumn // 2
        nums.sort(reverse = True)
        
        for i in range(1 ,len(nums)) :
            tmp = nums[0]
            for j in range(i ,len(nums)) :
                tmp += nums[j]
                if tmp > subSum :
                    tmp -= nums[j]
                elif tmp == subSum :
                    return True
        
        return nums[0] == subSum
