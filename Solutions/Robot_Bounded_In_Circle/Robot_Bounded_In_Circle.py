class Solution:
    def isRobotBounded(self, instructions):
        dx, dy, x, y = 0, 1, 0, 0
        for l in 4*instructions:
            if l == "G": 
                x, y = x+dx, y+dy
            elif l == "L":
                dx, dy = -dy, dx
            else:
                dx, dy = dy, -dx
                
        return (x,y) == (0,0)

#Fastest
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        go = {'N':(0,1), 'S':(0,-1), 'W':(-1,0), 'E':(1,0)}
        left = {'N':'W', 'W':'S', 'S':'E', 'E':'N'}
        right = {'N':'E', 'E':'S', 'S':'W', 'W':'N'}
        current = [0, 0]
        direction = 'N'
        
        for i in instructions:
            if i == 'G':
                x, y = go[direction]
                current[0] += x
                current[1] += y
            elif i == 'L':
                direction = left[direction]
            else:
                direction = right[direction]
        
        if current == [0,0] or direction != 'N':
            return True
        else:
            return False
