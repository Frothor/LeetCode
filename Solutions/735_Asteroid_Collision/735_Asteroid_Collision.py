class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for ast in asteroids:
            stack.append(ast)
            while len(stack) > 1 and stack[-1] < 0 and stack[-2] > 0:
                if stack[-1] + stack[-2] < 0: stack.pop(-2)
                elif stack[-1] + stack[-2] > 0: stack.pop()
                else:
                    stack.pop(); stack.pop()
                    break
        
        return stack

#Third fastest
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        
        for e in asteroids:
            if not stack or stack[-1] < 0 or e > 0:
                stack.append(e)
            
            else:
                flag = True
                while stack and stack[-1] > 0 and stack[-1] <= -e:
                    tmp = stack.pop()
                    if tmp == -e:
                        flag = False
                        break
                if (not stack or stack[-1] < 0) and flag:
                    stack.append(e)
        return stack

#Second fastest
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        '''
        Use a stack to track right-going asteroids, when seeing a left-going asteroid, start popping elements from the stack until the left-going one either explod or has "eaten" the whole stack (in which case we add it to the ans).
        Time O(N)
        Space O(N)
        '''
        stack = []
        ans = []
        for x in asteroids:
            if x > 0:
                stack.append(x)
            else:
                if not stack:
                    ans.append(x)
                else:
                    while stack and stack[-1] < abs(x):
                        stack.pop()
                    if stack and stack[-1] == abs(x):
                        stack.pop()
                    elif not stack:
                        ans.append(x)
        ans.extend(stack)
        return ans


#Fastest
from queue import deque
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        
        stackleft=deque()
        stackright=deque()
        
        for asteroid in asteroids:
            if asteroid>0: 
                stackright.append(asteroid)
            else:
                while stackright and stackright[-1]<=abs(asteroid):
                    temp=stackright[-1]
                    stackright.pop()
                    if temp==abs(asteroid):break
            
        for asteroid in reversed(asteroids):
            if asteroid <0:
                stackleft.appendleft(asteroid)
            else:
                while stackleft and abs(stackleft[0])<=asteroid:
                    temp=stackleft[0]
                    stackleft.popleft()
                    if abs(temp)==asteroid:break
        return stackleft+stackright