#We can just split our string, remove all extra spaces and return length of the last word, however we need to spend O(n) time for this, where n is length of our string. There is a simple optimization: let us traverse string from the end and:

#1.find the last element of last word: traverse from the end and find first non-space symbol.
#2.continue traverse and find first space symbol (or beginning of string)
#3.return end - beg.

#Complexity: is O(m), where m is length of part from first symbol of last word to the end. Space complexity is O(1).

class Solution:
    def lengthOfLastWord(self, s):
        end = len(s) - 1
        while end > 0 and s[end] == " ": end -= 1
        beg = end
        while beg >= 0 and s[beg] != " ": beg -= 1
        return end - beg


#Fastest
import re
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not s or len(s) == 0:
            return 0
        return len(re.split('\s+', s.strip())[-1])