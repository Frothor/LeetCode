import bisect
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        intervals = sorted([[b,e,indx] for indx, [b,e] in enumerate(intervals)])
        res = [-1] * len(intervals)
        begining_vals = [b for b,e,indx in intervals]
        
        for b,e,indx in intervals:
            x = bisect.bisect_left(begining_vals, e)
            if x != len(begining_vals):
                res[indx] = intervals[x][-1]
        
        return res

class Solution:
    def bSearch(self, prev, intervals, i, j):
        while i < j:
            mid = (i + j) // 2
            if intervals[mid][0] == prev:
                return mid
            elif intervals[mid][0] > prev:
                j = mid
            else:
                i = mid+1
        return i
        
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        # remember original indexes in intervals before we sort
        ind = [b[0] for b in sorted(enumerate(intervals), key=lambda i:i[1])]
        # sort by start point
        intervals.sort(key = lambda a:a[0])
        res = [0]*len(intervals)
        # for each endpoint search for right interval
        for i in range(len(intervals)-1):
            r = self.bSearch(intervals[i][1], intervals, i+1, len(intervals))
            if r < len(intervals):
                res[ind[i]] = ind[r]
            else:
                res[ind[i]] = -1

        res[ind[-1]] = -1
        return res

#Most common
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        lefts = sorted([[interval[0], i] for i, interval in enumerate(intervals)])
        ans = []
        for x,y in intervals:
            i = bisect.bisect_left(lefts, [y, -float("inf")])
            if i >= len(lefts):
                ans += [-1]
            else:
                ans += [lefts[i][1]]
        return ans

#Fastest
from bisect import bisect_right


class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        d = {}

        for i, (start, end) in enumerate(intervals):
            if start not in d: d[start] = i

        starts = list(sorted(d))

        result = []

        for start, end in intervals:
            if end in d:
                result.append(d[end])
            elif end > starts[-1]:
                result.append(-1)
            else:
                idx = bisect_right(starts, end)
                result.append(d[starts[idx]])

        return result