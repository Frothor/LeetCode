class Solution:
    def minCostToMoveChips(self, P):
        return min((odd := sum(1 for p in P if p%2)), len(P) - odd)

#Third fastest
class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        '''
        1. when move from even position to even position
        2. when move from odd position to odd position the cost 
            is 0 because the difference is divisible by 2
        3. if it is in mixed position, will need to move all to a even, 
            odd, then move to 1 position with cost = 1
        
        '''
        odd_count = len([p for p in position if p%2!=0])
        even_count = len([p for p in position if p%2==0])
        
        if even_count>odd_count:
            return odd_count
        
        return even_count

#Second fastest
class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        odd = 0
        even = 0
        for p in position:
            if p % 2 == 0:
                odd += 1
            else:
                even += 1
        return min(odd, even)

#Fastest
class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        d = {}
        a = 0
        b = 0
        for i in position:
            if i not in d:
                d[i]=1
            else:
                d[i]+=1
        for i in d:
            if i%2==0:
                a +=d[i]
            else:
                b+=d[i]
        return min(a,b)