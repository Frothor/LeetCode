class Solution:
    def longestMountain(self, A: List[int]) -> int:
        n, max_len = len(A), 0
        state, length = 0, 1
        for i in range(n-1):
            if state in [0, 1] and A[i+1] > A[i]:
                state, length = 1, length + 1
            elif state == 2 and A[i+1] > A[i]:
                state, length = 1, 2
            elif state in [1, 2] and A[i+1] < A[i]:
                state, length = 2, length + 1
                max_len = max(length, max_len)
            else:
                state, length = 0, 1
                
        return max_len

#Fourth fastest
class Solution:
    def longestMountain(self, A: List[int]) -> int:
        if len(A) <= 2:
            return 0
        prev = A[0]
        counter = 0
        max_count = 0
        mode = "asc"
        has_descended = False
        for item in A:
            if item > prev:
                if mode == "asc":
                    counter += 1
                else:
                    max_count = max(max_count, counter)
                    counter = 1
                    mode = "asc"
            elif item < prev:
                if counter >= 1 or mode == "desc":
                    counter += 1
                    mode = "desc"
                    has_descended = True
                else:
                    max_count = max(max_count, counter)
                    counter = 0
            elif item == prev:
                if mode == "desc":
                    max_count = max(max_count, counter)
                    counter = 0
                    mode = "asc"
                else:
                    counter = 0
                    max_count = max(max_count, counter)
            prev = item
        max_count = max(max_count, counter)
        if max_count > 0 and has_descended:
            return max_count + 1
        return 0

#Third fastest
class Solution:
    def longestMountain(self, A: List[int]) -> int:
        if len(A) < 3:
            return 0
        res = 0
        up = down = False
        count = 0
        for i in range(len(A) - 1):
            delta = A[i+1] - A[i]
            if delta > 0:
                if up:
                    count += 1
                else:
                    down = False
                    up = True
                    res = max(res, count)
                    count = 2
            elif delta < 0:
                if up:
                    up = False
                    down = True
                    count += 1
                elif down:
                    count += 1
            else:
                if down:
                    res = max(res, count)
                count = 0
                up = down = False
        if down:
            res = max(res, count)
        return res

#Second fastest
class Solution:
    def longestMountain(self, A: List[int]) -> int:
        
        downhill = True
        prev = -1
        cur_len = 0
        maxlen = 0 
        for a in A:
            
            if downhill:
                if prev <= a:
                    maxlen = max(maxlen, cur_len)
                    if prev == -1 or prev == a:
                        cur_len = 1
                    else:
                        cur_len = 2
                    downhill = False
                else:
                    cur_len += 1
                
            else:
                if prev < a:
                    cur_len += 1
                else:
                    if cur_len > 1 and prev > a:
                        cur_len += 1
                        downhill = True
                    else:
                        cur_len = 1
                        downhill = False
                    
            prev = a
            
        if downhill:
            maxlen = max(maxlen, cur_len)
            
        if maxlen < 3:
            return 0
        return maxlen

#Fastest
class Solution:
    def longestMountain(self, A: List[int]) -> int:
        up=0
        down=0
        ans=0
        for i in range(0,len(A)-1):
            if A[i]<A[i+1]:
                if down==0:
                    up+=1
                else:
                    up=1
                    down=0
                    
            elif A[i]>A[i+1]:
                if up>0:
                    down+=1
                    mountain=up+down+1
                    if ans<mountain:
                        ans=mountain
                
            else:
                up=0
                down=0

            
        
        return ans