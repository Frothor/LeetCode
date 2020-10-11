class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        res = []
        remaining = Counter(s)
        
        for c in s:
            if c not in res:
                while res and res[-1] >= c and remaining[res[-1]] > 0:
                    res.pop()
                res.append(c)
            remaining[c]-=1
        
        return "".join(res)

#Third fastest
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        if not s:
            return ""
        n = len(s)
        d = collections.defaultdict(list)
        for i in range(n):
            c = s[i]
            d[c].append(i)
            
        stack = []
        for i in range(n):
            c = s[i]
            if i > d[c][0]:
                continue
            while stack and stack[-1] > c:
                t = stack[-1]
                if d[t][-1] > i:
                    stack.pop()
                    while d[t] and d[t][0] < i:
                        d[t].pop(0)
                else:
                    break

            if i == d[c][0]:
                stack.append(c)
                        
        return "".join(stack)

#Second fastest
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        
        """
        cdadabcc
        
        01234567
        43131244
        
        1: 2, 4
        2: 5
        3: 1, 3
        4: 0, 6, 7
        
        stack = []
        c d 
        a d b c 
        
        """
        
        last_index = {}
        
        for i, char in enumerate(s):
            last_index[char] = i
            
        stack = []
        used  = set()
        
        i = 0
        while i < len(s):
            curr_char = s[i]
            if curr_char not in used:
                while stack and stack[-1] > curr_char and i < last_index[stack[-1]]:
                    used.discard(stack.pop())
                used.add(curr_char)
                stack.append(curr_char)
            i += 1
        
        return ''.join(stack)


#Fastest
class Solution:#use dict to record the last index of char,then traverse,while res里最后一个字母比char大并且后面也会出现，则pop，直至char比res的最后一个小或者最后一个是最后一次出现，确保res记录的是最每个字母必须出现一次的原则下的升序排列，则append char
    def removeDuplicateLetters(self, s: str) -> str:
        d={c:i for i,c in enumerate(s)}
        res=""
        for i,x in enumerate(s):
            if x not in res:
                while res and  x<res[-1] and i<d[res[-1]]:
                    res=res[:-1]
                res+=x
        return res