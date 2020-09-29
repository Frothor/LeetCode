class Solution:
    def checkValidString(self, s: str) -> bool:
        l, w = 0, 0            # counter for '(' and '*'
        for i in s:
            if i == '(':       # count '('
                l += 1
            elif i == ')':
                l -= 1         # decrement '('
                if l < 0:      # out of '(' to offset ')'
                    if l + w  < 0:   # if not enough '*' wildcard
                        return False
                    w -= 1     # update counters
                    l = 0
            else:
                w += 1
        
		# same as above, but in reverse
        r, w = 0, 0
        for i in s[::-1]:
            if i == ')':
                r += 1
            elif i == '(':
                r -= 1
                if r < 0:
                    if r + w < 0:
                        return False
                    w -= 1
                    r = 0
            else:
                w += 1
        
        return True

#Second fastest
class Solution:
    def checkValidString(self, s: str) -> bool:
        if not s:
            return True
        
        stars = []
        left = []

        for i in range(len(s)):
            if s[i] == '(':
                left.append(i)
            elif s[i] == '*':
                stars.append(i)
            elif s[i] == ')':
                if len(left) > 0:
                    left.pop()
                elif len(stars) > 0:
                    stars.pop()
                else:
                    return False
        
        
        while left:
            if stars and left[-1] < stars[-1]:
                stars.pop()
                left.pop()
            else:
                break
        
        return len(left) == 0



#Fastest
class Solution:
    def checkValidString(self, s: str) -> bool:
        left, star = [], []
        for i, ch in enumerate(s):
            if ch == '(':
                left.append(i)
            elif ch == '*':
                star.append(i)
            else:
                if left:
                    left.pop()
                elif star:
                    star.pop()
                else:
                    return False
        
        while star:
            if not left:
                return True
            elif star[-1] > left[-1]:
                star.pop()
                left.pop()
                
            else:
                return False
        
        return left == []