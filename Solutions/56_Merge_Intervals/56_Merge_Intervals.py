#Most common
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda x: x[0])
        
        new_intervals = []
        i = 0
        while i < len(intervals):
            j = i+1
            left, right = intervals[i]
            
            while j < len(intervals) and intervals[j][0] <= right:
                right = max(right, intervals[j][1])
                j += 1
            
            new_intervals.append([left, right])
            i = j
            
        return new_intervals

#Third fastest
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans=[]
        if len(intervals)==0:
            return ans
        elif len(intervals)==1:
            return intervals
        intervals.sort(key=lambda x: x[0])
        beg=intervals[0][0]
        end=intervals[0][1]
        for j in range(1,len(intervals)):
            i=intervals[j]
            if i[1]<=end or i[0]<=end:
                end=max(end,i[1])
            else:
                ans.append([beg,end])
                beg=i[0]
                end=i[1]
        ans.append([beg,end])
        return ans


#Second fastest
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        # sort by the start of each interval
        # then for loop the intervals, and merge if needed
        '''
        1: put the first interval in to the output
        2: compare the second of invervals to the last item in the output:
        if last.end < cur_interfval.starte: simply add the current into the output and continue
        if cur_interval.start  <= last.end <= cur_interval.end; update the last item.end = current_interva;.end
        else: cur_interval.start and cur_interval.end <= last.end, skip
        
        '''
        
        if not intervals: return []
        n = len(intervals)
        
        intervals.sort()
        
        res = [intervals[0]]
        
        
        for i in range(1, n):
            last = res[-1]
            last_start, last_end = last[0], last[1]
            
            cur_start, cur_end = intervals[i][0], intervals[i][1]
            if last_end < cur_start: res.append(intervals[i])
            elif cur_start <= last_end and last_end <= cur_end: res[-1][1] = cur_end
            elif cur_start <= last_end and cur_end <= last_end: continue
                
        return res
        
        


#Fastest
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) <= 1:
            return intervals
        intervals.sort(key=lambda x: x[0])
        answer = []
        start, end = intervals[0][0], intervals[0][1]
        for i in intervals[1:]:
            if i[0] <= end:
                end = max(end, i[1])
            else:
                answer.append([start, end])
                start, end = i[0], i[1]
        answer.append([start, end])
        return answer