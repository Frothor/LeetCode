class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        # Sort by start time and furthest end time first if start time is the same.
        intervals.sort(key=lambda x:(x[0], -x[1]))
        
        merged = []
        # Iterate through our intervals.
        for start, end in intervals:
		    # If we have an empty stack or the current interval starts after the last ends.
            if not merged or start >= merged[-1][-1]:
                merged.append([start, end])
			# If the current interval is contained within the previous we ignore it.
            elif start >= merged[-1][0] and merged[-1][-1] >= end:
                continue
			# Otherwise there's some overlap but we aren't concerned so we append.
            else:
                merged.append([start, end])
        # The result will be len of our appeneded intervals.
        return len(merged)

#Third fastest
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals_new = sorted(intervals, key = lambda x: (x[0], x[1]))
        
        c = 1
        m = intervals_new[0][0]
        M = intervals_new[0][1]
        for i in intervals_new:
            if m == i[0]:
                M = i[1]
            elif M <= i[0] or M < i[1]:
                c += 1
                M = i[1]
        
        return c

#Second fastest
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        count = 0
        intervals.sort(key=lambda x: (x[0], -x[1]))
        left = intervals[0][0]
        right = intervals[0][1]
        for i in range(1, len(intervals)):
            x = intervals[i]
            if x[0]>=left and x[1]<=right:
                count+=1
            elif x[0]<=right and x[1]>=right:
                right = x[1]
            elif x[0]>right:
                left = x[0]
                right = x[1]
                
        return len(intervals)-count
            

#Fastest
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        n = len(intervals)
        if not n:
            return 0
        
        inter = sorted(intervals, key=lambda x: x[0]*10**6-x[1])
        ans = n
        l, r = inter[0]
        for stard, end in inter[1:]:
            if end > r:
                r = end
            elif end <= r:
                ans -= 1
            else:
                l, r = stard, end
            
        return ans