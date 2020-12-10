#https://leetcode.com/problems/valid-mountain-array/discuss/966752/Python-One-pass-explained
class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        n = len(arr)
        beg, end = 0, n - 1
        while beg != n-1 and arr[beg + 1] > arr[beg]: beg += 1
        while end != 0 and arr[end - 1] > arr[end]: end -= 1 
        return beg == end and end != n-1 and beg != 0

#Third fastest
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A)<3 or A[0]>=A[1]:
            return False
			
        uphill = True
        
        for i in range(1,len(A)):
            if uphill:
                if A[i-1]>=A[i]:
                    uphill = False
            if not uphill:
                if A[i-1]<=A[i]:
                    return False
        return not uphill

#Second fastest
class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        n = len(arr)
        if n < 3: return False
        top, bottom = 0, 0
        for i in range(1, n):
            if arr[i] <= arr[i-1]:
                top = i-1
                break
        if top in (0, n-1): 
            return False
        for i in range(top+1, n):
            if arr[i] >= arr[i-1]:
                return False
        return True

s = Solution()
print(s.validMountainArray([1,3,2]))
print(s.validMountainArray([3,5,5]))
print(s.validMountainArray([0,3,2,1]))
print(s.validMountainArray([0,1,2,3,4,5,6,7,8,9]))
print(s.validMountainArray([3,7,6,4,3,0,1,0]))

#Fastest
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        n = len(A)
        if n < 3: return False
        inc = A[0] < A[1]
        k = 0
        for i in range(1, n):
            if inc and A[i-1] >= A[i]: 
                k += 1
                inc = False
            if not inc and A[i-1] <= A[i]:
                return False
        return k == 1
                
            
        
#         maxq = deque()
#         minq = deque()
#         for i, a in enumerate(A):
#             while maxq and A[maxq[-1]] <= a: maxq.pop()
#             while minq and A[minq[-1]] >= a: minq.pop()
#             maxq.append(i)
#             minq.append(i)
#         print(maxq, minq)
#         return len(maxq) + len(minq) == n + 1
