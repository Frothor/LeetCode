#What you need to do in this problem is just iterate over string and find groups of equal symbols, and then return the length of the longest group. Natural way to do it is to use functionality of itertools library, more precisely groupby function. By definition, if we do not specify arguments for groupby, it will create groups exactly with equal elements, so what we need to do is just to choose group with the biggest size and return it!

#Complexity: time and space complexity is O(n), because we iterate over our data once, but also we need to have space to keep our groupby object.

class Solution:
    def maxPower(self, s: str) -> int:
         return max(len(list(j)) for _,j in groupby(s))

#Third fastest
class Solution:
    def maxPower(self, s: str) -> int:
        curr=''
        count=0
        mx=0
        for i in s:
            if i == curr:
                count+=1
            else:
                curr = i
                if count > mx:
                    mx = count
                count=0
                
        if count > mx:
                mx = count
        return mx + 1

#Second fastest
class Solution:
    def maxPower(self, s: str) -> int:
        curr=''
        count=0
        mx=0
        for i in s:
            if i == curr:
                count+=1
            else:
                curr = i
                if count > mx:
                    mx = count
                count=0
                
        if count > mx:
                mx = count
        return mx + 1

#Fastest
class Solution:
    def maxPower(self, s):
        s = chain(s, '\n')
        res = cur = 1
        prev = next(s)
        for x in s:
            if x != prev:
                if cur > res:
                    res = cur
                cur = 1
            else:
                cur += 1
            prev = x
        return res