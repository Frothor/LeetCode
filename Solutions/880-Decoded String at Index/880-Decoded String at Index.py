#Third fastest
"""
Currently crazy shitty
"""

class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        N=0
        for i, letter in enumerate(S):
            if letter.isdigit():
                N *= int(letter)
            else:
                N += 1
            if K <= N:
                break
        for j in range(i, -1, -1):
            char = S[j]
            if char.isdigit():
                N = N / int(char)
                K = K % N
            else:
                if K == N or K == 0:
                    return char
                else:
                    N -= 1
                
        
        
        
        """
        decodedString = ''
        for letter in S:
            if len(decodedString) < K:
                try:
                    repeats = int(letter)
                    newDecodedString = decodedString * repeats
                    decodedString = newDecodedString
                except ValueError:
                    decodedString += letter
            else:
                break
        return decodedString[K-1]
        """

#Second fastest
class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        N=0
        for x in range(len(S)):
            if S[x].isdigit():
                N*=int(S[x])
            else:
                N+=1
            if N>=K:
                break
        for back in range(x,-1,-1):
            if S[back].isdigit():
                N/=int(S[back])
                K%=N
            else:
                if K==N or K==0:
                    return S[back]
                N-=1

#Fastest
class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        size = 0
        for c in S:
            if c.isalpha():
                size += 1
            else:
                size *= int(c)
       
        for c in reversed(S):
            K %= size
            if K == 0 and c.isalpha():
                return c
            if c.isdigit():
                size /= int(c)
            else:
                size -= 1