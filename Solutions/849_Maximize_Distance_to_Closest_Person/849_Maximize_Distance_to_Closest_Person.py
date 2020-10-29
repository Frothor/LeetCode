class Solution:
    def maxDistToClosest(self, seats):
        out = max(seats[::-1].index(1), seats.index(1))
        for seat, group in groupby(seats):
            if seat: continue
            out = max(out, (len(list(group))+1)//2)

        return out

#Fourth fastest
class Solution:
    def maxDistToClosest(self, seats: List[int]):
        start = -1
        maxgap = 0
        
        for i in range(len(seats)):
            if seats[i] == 1:
                #is there a person sitting there?
                if start == -1: maxgap = i
                   #first person (p1) 
                else: maxgap = max(maxgap, (i-start)//2)
                    #this is second person
                    #can we sit in between?
                    #if so is it better than our current best option?
                
                start = i
         # Check the last seat it it is empty could be the best choice.
        maxgap = max(maxgap, len(seats)-1-start)
        
        return maxgap

#Third fastest
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        
        distance = 0
        
        start = True
        count = 0
        for i in range(len(seats)):
            if seats[i] == 0:
                count +=1
            else:
                if start:
                    distance = max(distance, count)
                    start = False
                else:
                    distance = max(distance, ceil(count/2))
                count = 0
        distance = max(distance, count)
        return distance

#Second fastest
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        last_taken_seat = -1
        max_dist = 0
        for i, curr_seat in enumerate(seats):
            if not curr_seat:
                continue
            if last_taken_seat == -1:
                # Alex cannot sit, don't update anything
                if i != 0:
                    # otherwise sit on the first one which maximizes distance.
                    max_dist = i
            else:
                if i - last_taken_seat > 1:
                    max_dist = max(max_dist, (i - last_taken_seat) / 2)
            last_taken_seat = i
        # Check the last seat it it is empty could be the best choice.
        if not seats[-1]:
            max_dist = max(max_dist, len(seats) - 1 - last_taken_seat)
        return int(max_dist)

#Fastest
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        
        prev = None
        diff = 0
        result = -1
        
        n = len(seats)
        for i in range(n):
            if seats[i]:
                if prev is None:
                    prev = i
                    left = i
                elif i-prev > diff:
                    diff = i-prev
                    result = diff // 2
                prev = i
        
        right = n - prev - 1
        
        return max(left, right, result)