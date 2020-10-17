class Solution:
    def findRepeatedDnaSequences(self, s):
        Count = Counter([s[i-10:i] for i in range(10, len(s) + 1)])
        return [key for key in Count if Count[key] > 1]  

#Third fastest
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        if len(s) < 10:
            return []
        if len(s) == 10:
            return []
        d = {}
        ans = []
        for i in range(len(s) - 9):
            key = s[i:i + 10]
            if key in d:
                d[key] += 1
                if d[key] == 2:
                    ans.append(key)
            else:
                d[key] = 1
        return ans

#Second fastest
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        if s is None or len(s)==0:
            return []
        
        n= len(s)
        result = set()
        hashset =set()
        for i in range(n-10+1):
            sub = s[i:i+10]
            if sub in hashset:
                result.add(sub)
                
            hashset.add(sub)
        
        return list(result)
        

#Fastest
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        # Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
        
        seen = set()
        res = set()
        for i in range(len(s)):
            new = s[i: i+10]
            if new in seen:
                res.add(new)
            else:
                seen.add(new)
        return res