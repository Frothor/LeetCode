#Most common
class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        nrow, ncol = len(grid), len(grid[0])
        self.res = 0
        empty = 1
                
        # Search for start post
        for row in range(nrow):
            for col in range(ncol):
                if grid[row][col] == 1:
                    sx, sy = row, col
                elif grid[row][col] == 0:
                    empty += 1
                    
        self.walk(grid, nrow, ncol, sx, sy, empty)
        
        return self.res
    
    def walk(self, grid, nrow, ncol, x, y, empty):
        if 0 <= x < nrow and 0 <= y < ncol and grid[x][y] != -1:
            if grid[x][y] == 2:
                self.res += empty == 0
                return

            grid[x][y] = -1
            for x_s, y_s in [(-1,0), (0,-1), (1,0), (0,1)]:
                self.walk(grid, nrow, ncol, x+x_s, y+y_s, empty-1)
            grid[x][y] = 0


#Second fastest
class Solution:
    def findSols(self, grid: List[List[int]], py: int, px: int, numEsq: int) -> int:
        sol = 0
        gyx = grid[py][px]
        grid[py][px] = 3
        numEsq -= 1
        if numEsq == 0:
            if px > 0 and grid[py][px - 1] == 2: sol = 1
            elif px < len(grid[0]) - 1 and grid[py][px + 1] == 2: sol = 1
            elif py > 0 and grid[py - 1][px] == 2: sol = 1
            elif py < len(grid) - 1 and grid[py + 1][px] == 2: sol = 1
        elif numEsq > 0:
            if px > 0 and grid[py][px - 1] == 0: sol += self.findSols(grid, py, px-1, numEsq)
            if px < len(grid[0]) - 1 and grid[py][px + 1] == 0: sol += self.findSols(grid, py, px+1, numEsq)
            if py > 0 and grid[py - 1][px] == 0: sol += self.findSols(grid, py-1, px, numEsq)
            if py < len(grid) - 1 and grid[py + 1][px] == 0: sol += self.findSols(grid, py+1, px, numEsq)                 
        grid[py][px] = gyx
        return sol
    
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        numEsq = 0
        sx = -1
        sy = -1
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    numEsq += 1
                elif grid[i][j] == 1:
                    sy = i
                    sx = j
        return self.findSols(grid, sy, sx, numEsq+1)


#Fastest
class Solution:
    
    def search(self, grid, x, y, numSol, cnt, cntTarget):

        # print(x, y)

        if grid[x][y] < 0:
            # print("?6", x, y, grid[x][y])
            return

        if grid[x][y] == 2:
            if cnt == cntTarget:
                numSol[0] += 1


                # print(his)
            return

        grid[x][y] = -2
        # his.append((x, y))

        if (x + 1) < len(grid):
            # grid[x + 1][y] = -2

            self.search(grid, x + 1, y, numSol, cnt + 1, cntTarget)
            # grid[x + 1][y] = 0

        # else:
        #     print("?1", x, y)

        if (x - 1) >= 0:
            # grid[x - 1][y] = -2

            self.search(grid, x - 1, y, numSol, cnt + 1, cntTarget)
            # grid[x - 1][y] = 0

        # else:
        #     print("?2", x, y)

        if (y + 1) < len(grid[0]):
            # grid[x][y + 1] = -2

            self.search(grid, x, y + 1, numSol, cnt + 1, cntTarget)
            # grid[x][y + 1] = 0

        # else:
        #     print("?3", x, y)

        if (y - 1) >= 0:
            # grid[x][y - 1] = -2
            self.search(grid, x, y - 1, numSol, cnt + 1, cntTarget)
            # grid[x][y - 1] = 0
        # else:
        #     print("?4", x, y)

        grid[x][y] = 0
        # his.pop()
        
        

    
#     def search(self, grid, x, y, m, n, p, q, numSol, cnt, cntTarget):
        
#         # print(x, y)
        
#         if x == p and y == q and cnt == cntTarget:
#             numSol[0] += 1
#             # print("?5")
#             # print(his)
#             return
        
        
#         if (x + 1) < m and grid[x + 1][y] >= 0:
#             grid[x + 1][y] = -2

#             self.search(grid, x + 1, y, m, n, p, q, numSol, cnt + 1, cntTarget)
#             grid[x + 1][y] = 0

#         # else:
#             # print("?1", x, y)
            
#         if (x - 1) >= 0 and grid[x - 1][y] >= 0:
#             grid[x - 1][y] = -2

#             self.search(grid, x - 1, y, m, n, p, q, numSol, cnt + 1, cntTarget)
#             grid[x - 1][y] = 0

#         # else:
#             # print("?2", x, y)
        
#         if (y + 1) < n and grid[x][y + 1] >= 0:
#             grid[x][y + 1] = -2

#             self.search(grid, x, y + 1, m, n, p, q, numSol, cnt + 1, cntTarget)
#             grid[x][y + 1] = 0

#         # else:
#             # print("?3", x, y)
            
#         if (y - 1) >= 0 and grid[x][y - 1] >= 0:
#             grid[x][y - 1] = -2
#             self.search(grid, x, y - 1, m, n, p, q, numSol, cnt + 1, cntTarget)
#             grid[x][y - 1] = 0
#         # else:
#             # print("?4", x, y)
        
    
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        
        m = len(grid)
        n = len(grid[0])
        
        cntTarget = 0
        for i in range(m):
            for j in range(n):
                
                if grid[i][j] == 1:
                    xStart = i
                    yStart = j
                
                if grid[i][j] == 2:
                    xEnd = i
                    yEnd = j
                    
                if grid[i][j] == -1:
                    cntTarget += 1
        cntTarget = m * n - cntTarget
                
        numSol = [0]
        cnt = 1
        # grid[xStart][yStart] = -1
        # his = []
        self.search(grid, xStart, yStart, numSol, cnt, cntTarget)
        
        return numSol[0] 
        