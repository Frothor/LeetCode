class Solution:
    def findMinArrowShots(self, points):
        points.sort(key = lambda x: x[1])
        n, count = len(points), 1
        if n == 0: return 0
        curr = points[0]
        
        for i in range(n):
            if curr[1] < points[i][0]:
                count += 1
                curr = points[i]
                
        return count  

#Third fastest
class Solution:
    # sort by the end, consider the first one a0, if others after it has a start less than a0[0], should be ok with the 
    # same arrow
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        
        points.sort(key=lambda x : x[1])
        n = 0
        cur = -sys.maxsize - 1
        for p in points:
            if p[0] <= cur:
                continue
            n += 1
            cur = p[1]
        return n

#Second fastest
class Solution:
  def findMinArrowShots(self, points: List[List[int]]) -> int:
    if not points:
      return 0
    
    points.sort(key=lambda x:x[1])
    _, right_bound = points[0]
    # print(points)
    ans = 0
    for point in points[1:]:
      if point[0] > right_bound:
        _, right_bound = point
        ans += 1
    return ans + 1

#Fastest
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        points.sort(key=lambda x:x[1])
        count=1
        begin=points[0][1]
        for start,end in points:
            if start >begin:
                count+=1
                begin=end
        return count
