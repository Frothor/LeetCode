class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        d, T = Counter(), 60
        for t in time: d[t%T] += 1
        ans = sum(d.get(i,0)*d.get(T-i,0) for i in range(1, T//2))
        q1, q2 = d.get(0,0), d.get(T//2, 0)
        return ans + q1*(q1-1)//2 + q2*(q2-1)//2

#Third fastest
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        
        mcs = [0 for i in range(60)]
        for t in time:
            mod = t % 60
            mcs[mod] += 1
        print(mcs)
        ret = 0
        for i in range(31):
            if i == 0 or i == 30:
                ret += mcs[i]*(mcs[i]-1)//2
            else:
                ret += mcs[i] * mcs[60-i]
       
        return ret 


#Second fastest
from collections import Counter
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        updated_time = [each%60 for each in time]
        counts = Counter(updated_time)
        res = (counts[0]*(counts[0]-1))/2
        for each in counts:
            if each == 30:
                res += (counts[each]*(counts[each]-1))/2
            else:
                res += (counts[each]*counts[60-each])/2
        return int(res)

#Fastest
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        arr = [0 for _ in range(60)]
        count = 0
        for elem in time:
            arr[elem % 60] += 1
        
        for i in range(0, 31):
            if arr[i] == 0:
                continue
            elif (i == 0 or i == 30):

                count += int(arr[i] * (arr[i] - 1) / 2)
            else:
                count += arr[i] * arr[60-i]
        return count