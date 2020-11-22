#Fourth fastest
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        MORSE = [".-","-...","-.-.","-..",".","..-.","--.",
                 "....","..",".---","-.-",".-..","--","-.",
                 "---",".--.","--.-",".-.","...","-","..-",
                 "...-",".--","-..-","-.--","--.."]

        temp = []
        for word in words:
            t = ""
            for c in word: 
                t += MORSE[ord(c)-ord('a')]
            temp.append(t)
        return len(set(temp))

#Third fastest
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
      dic = {}
      morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
      for idx, m in enumerate(morse):
        dic[chr(idx+97)] = m
      
      result = []
      for mess in words:
        tr = ""
        for ch in mess:
          tr += dic[ch]
        result += [tr]
      
      return len(set(result))

#Second fastest
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        m = {}
        
        for x, y in zip(
            [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."],
            'abcdefghijklmnopqrstuvwxyz'
        ):
            m[y] = x
        
        result = set()
        
        for word in words:
            result.add(
                ''.join([m[c] for c in word])
            )
        
        return len(result)


#Fastest
# Platform: leetcode.com
# No. 804. Unique Morse Code Words
# Link: https://leetcode.com/problems/unique-morse-code-words/
# Difficulty: Easy
# Dev: Chumicat
# Date: 2020/11/15
# Submission: https://leetcode.com/submissions/detail/420221386/
# (Time, Space) Complexity : O(n), O(n)
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        table = {'i': '..', 's': '...', 'd': '-..', 'h': '....', 'l': '.-..', 'b': '-...', 
                 'a': '.-', 'u': '..-', 'k': '-.-', 'v': '...-', 'z': '--..', 'x': '-..-', 
                 'n': '-.', 'r': '.-.', 'g': '--.', 'f': '..-.', 'p': '.--.', 'c': '-.-.', 
                 'm': '--', 'w': '.--', 'o': '---', 'q': '--.-', 'j': '.---', 'y': '-.--', 
                 'e': '.', 't': '-',}
        return len({"".join(table[c] for c in word) for word in words})
