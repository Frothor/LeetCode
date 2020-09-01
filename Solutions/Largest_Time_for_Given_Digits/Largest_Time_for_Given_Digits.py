#MOST COMMON
class Solution:

    def largestTimeFromDigits(self, A: List[int]) -> str:
        valid = -1
        possible = itertools.permutations(A)
        for h,i,j,k in possible:
            hour = h*10 + i
            minute = j*10 + k
            if hour < 24 and minute < 60:
                valid = max(valid, hour*60+minute)
            
        if valid == -1:
            return ""
        hour = valid // 60
        minute = valid - (hour*60)
        return "{:02d}:{:02d}".format(hour, minute)


#FASTEST
from collections import Counter

class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        def getMaxLessThan(A, upperChar):
            maxChar = -1
            for char in A:
                if (maxChar == -1 and char <= upperChar) or (char >= maxChar and char <= upperChar):
                    maxChar = char
            return maxChar
        
        solution = ''
        
        digits = A.copy()
        if 0 in digits:
            h1 = 0
            digits.remove(0)
            
            h2 = max(digits)
            digits.remove(h2)
            
            if min(digits) <= 5:
                m1 = getMaxLessThan(digits, 5)
                digits.remove(m1)
                
                m2 = max(digits)
                digits.remove(m2)
                
                solution = '{}{}:{}{}'.format(h1, h2, m1, m2)
        
        digits = A.copy()
        if 1 in digits:
            h1 = 1
            digits.remove(1)
            
            h2 = max(digits)
            digits.remove(h2)
            
            if min(digits) <= 5:
                m1 = getMaxLessThan(digits, 5)
                digits.remove(m1)

                m2 = max(digits)
                digits.remove(m2)

                solution = '{}{}:{}{}'.format(h1, h2, m1, m2)
        
        digits = A.copy()
        if 2 in digits:
            h1 = 2
            digits.remove(2)
            
            if min(digits) <= 3:
                h2 = getMaxLessThan(digits, 3)
                digits.remove(h2)
                
                if min(digits) <= 5:
                    m1 = getMaxLessThan(digits, 5)
                    digits.remove(m1)
                    
                    m2 = max(digits)
                    digits.remove(m2)
                    
                    solution = '{}{}:{}{}'.format(h1, h2, m1, m2)
        
        return solution