class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        m=0
        for i in trips:
            m=max(m,i[2])
        l=[0]*(m+1)
        for i in trips:
            l[i[1]-1]+=i[0]
            l[i[2]-1]-=i[0]
        for i in range(1,len(l)):
            l[i]+=l[i-1]
        for i in range(len(l)):
            if(l[i]>capacity):
                return 0
        return 1   


#Fastest
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        pois = []
        for num, start, end in trips:
            pois.extend([(start, num), (end, -num)])
        num_used = 0
        for _, num in sorted(pois):
            num_used += num
            if num_used > capacity:
                return False
        return True