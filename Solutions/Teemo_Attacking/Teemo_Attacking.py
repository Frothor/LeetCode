#most common
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if len(timeSeries) == 0:
            return 0
        poisonTime = 0
        for i in range(len(timeSeries)-1):
            poisonTime += min(duration, timeSeries[i+1] - timeSeries[i])
        return poisonTime + duration

#Fastest
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if not timeSeries: return 0
        lasthit = timeSeries[0]
        poisoned = 0
        for t in timeSeries[1:]:
            x = t - lasthit
            poisoned += x if x < duration else duration
            lasthit = t
        
        return poisoned + duration