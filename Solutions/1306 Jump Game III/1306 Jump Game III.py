#Fourth fastest
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        if arr[start] == 0:
            return True
        queue = [start]
        visited = set([])
        while(len(queue) != 0):
            # print(queue)
            element = queue.pop()
            left = element - arr[element]
            if left >= 0 and left not in visited:
                if arr[left] == 0:
                    return True
                visited.add(left)
                queue.append(left)
            right = element + arr[element]
            if right < len(arr) and right not in visited:
                if arr[right] == 0:
                        return True
                visited.add(right)
                queue.append(right)
        return False

#Third fastest
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
       
        visited={}
        self.li=[]
        
        if arr[start]==0:
            return True
        
        def do_bfs():
            
            
            li=[]
            for start in self.li:
                visited[start]=None
                if start+arr[start]<len(arr) and (start+arr[start]) not in visited:

                    if arr[start+arr[start]]==0:
                        return False
                    else:
                        li.append(start+arr[start])

                if start-arr[start]>-1 and (start-arr[start]) not in visited:

                    if arr[start-arr[start]]==0 :
                        return False
                    else:
                        li.append(start-arr[start])
            self.li=li
            if self.li!=[]:
                return True
            else:
                return False
        
        self.li=[start]
        ct=0
        while do_bfs():
            ct+=1
        if self.li==[]:
            return False
        else:
            return True

#Second fastest
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        def solve(arr,start,n):
            nonlocal flag
            if arr[start]==0:
                flag=True
                return
            if start in visited:
                return
            if start-arr[start]>=0:
                visited[start]=True
                solve(arr,start-arr[start],n)
            if start+arr[start]<n:
                visited[start]=True
                solve(arr,start+arr[start],n)
        visited={}
        flag=False
        solve(arr,start,len(arr))
        return flag

#Fastest
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        def solve(arr,start,n):
            nonlocal flag
            if arr[start]==0:
                flag=True
                return
            if start in visited:
                return
            if start-arr[start]>=0:
                visited[start]=True
                solve(arr,start-arr[start],n)
            if start+arr[start]<n:
                visited[start]=True
                solve(arr,start+arr[start],n)
        visited={}
        flag=False
        solve(arr,start,len(arr))
        return flag