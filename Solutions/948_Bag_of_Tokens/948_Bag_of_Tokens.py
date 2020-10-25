class Solution:
    def bagOfTokensScore(self, tokens, P):
        tokens.sort()
        beg, end, S, max_S = 0, len(tokens) - 1, 0, 0
        while beg <= end:
            if tokens[beg] <= P:
                P -= tokens[beg]
                S += 1
                max_S = max(max_S, S)
                beg += 1
            elif S >= 1:
                P += tokens[end]
                S -= 1
                end -= 1
            else: break
        return max_S

#Third fastest
class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        tokens,l,r,points,ans=sorted(tokens),0,len(tokens)-1,0,0
        #print(tokens)
        while l<=r:
            if tokens[l]<=P:
                P-=tokens[l]
                points+=1
                l+=1
            elif points>=1:
                points-=1
                P+=tokens[r]
                r-=1
            else:
                break
            ans=max(ans,points)
        return ans

#Second fastest
from collections import deque

class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        tokens = sorted(tokens)
        tokens = deque(tokens)
        score = 0
        power = P
        while tokens:
            if power >= tokens[0]:
                power -= tokens[0]
                score += 1
                tokens.popleft()
            elif score > 0 and len(tokens) > 1 and tokens[-1] >= tokens[0]:
                power += tokens[-1]
                score -= 1
                tokens.pop()
            else:
                tokens.pop()
        return score

#Fastest
class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        tokens.sort()
        if not tokens or P < tokens[0]:
            return 0
        score = 0
        left, right = 0, len(tokens) - 1
        while left <= right:
            if P >= tokens[left]:
                P -= tokens[left]
                left += 1
                score += 1
            else:
                if right - left > 1:
                    P += tokens[right]
                    right -= 1
                    score -= 1
                else:
                    break
        return score
