class Solution:
    def bitwiseComplement(self, N):
         return (1<<(len(bin(N)) - 2)) - 1 - N

#Fourth fastest
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        temp  = bin(N)[2:]
        ans = ''
        for i in temp:
            if i == '1':
                ans += '0'
            else:
                ans += '1'
        return int(ans,2)
        

#Third fastest
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        if N == 0:
            return 1
        
        maxx = 1
        while maxx<=N:
            maxx= maxx*2
        return(maxx-N-1)

#Second fastest
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        v = 1
        while(v < N): v = (v << 1) + 1
        return v ^ N

#Fastest
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        if N == 0:
            return 1
        
        if N == 1:
            return 0
        
        up = 2
        while up <= N:
            up = up << 1
            
        return up-1-N