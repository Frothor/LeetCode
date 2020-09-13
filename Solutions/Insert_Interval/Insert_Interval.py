class Solution:
    def insert(self, intervals, I):
        res, i = [], -1
        for i, (x, y) in enumerate(intervals):
            if y < I[0]:
                res.append([x, y])
            elif I[1] < x:
                i -= 1
                break
            else:
                I[0] = min(I[0], x)
                I[1] = max(I[1], y)
                
        return res + [I] + intervals[i+1:]

#Fastest
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        found = False
        for i in range(len(intervals)):
            if intervals[i][0] > newInterval[0]:
                intervals = intervals[:i] + [newInterval] + intervals[i:]
                found = True
                break
        
        if not found:
            intervals.append(newInterval)
        
        merged = []
        for interval in intervals:
            if len(merged) != 0 and merged[-1][1] >= interval[0]:
                merged[-1][1] = max(merged[-1][1], interval[1])
            else:
                merged.append(interval)
        
        return merged