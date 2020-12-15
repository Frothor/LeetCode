class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        return sorted([i * i for i in nums])

#Third fastest
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        newArr = []
        for num in nums:
            newArr.append(num * num)
        
        return sorted(newArr)

#Second fastest
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        return sorted((a *a)for a in A)

#Fastest
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        return sorted(x*x for x in A)