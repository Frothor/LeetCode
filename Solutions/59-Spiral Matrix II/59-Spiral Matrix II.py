#https://leetcode.com/problems/spiral-matrix-ii/discuss/963128/Python-rotate-when-need-explained
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[0] * n for _ in range(n)]
        x, y, dx, dy = 0, 0, 1, 0
        for i in range(n*n):
            matrix[y][x] = i + 1
            if not 0 <= x + dx < n or not 0 <= y + dy < n or matrix[y+dy][x+dx] != 0:
                dx, dy = -dy, dx
            x, y = x + dx, y + dy
        return matrix

#Third fastest
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        
        res = [[0]*n for _ in range(n)]
        
        dr = [0, 1, 0, -1]
        dc = [1, 0, -1, 0]
        
        r = c = di = 0
        
        for i in range(n**2):
            res[r][c] = i + 1
            
            cr, cc = r + dr[di], c + dc[di]
            
            if 0 <= cr < n and 0 <= cc < n and res[cr][cc] == 0:
                r, c = cr, cc
            else:
                di = (di + 1) % 4
                r, c = r + dr[di], c + dc[di]
        
        return res

#Seocnd fastest
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ele = 1
        mat = [[0]*n for _ in range(n)]
        # print(mat)
        sr = sc = 0
        er = ec = n-1
        while sr <= er and sc <= ec:
            for i in range(sc,ec+1):
                mat[sr][i] = ele
                ele += 1
            for i in range(sr+1,er+1):
                mat[i][ec] = ele
                ele += 1
            for i in reversed(range(sc,ec)):
                mat[er][i] = ele
                ele += 1
            for i in reversed(range(sr+1,er)):
                mat[i][sc] = ele
                ele +=1
            sr += 1
            sc += 1
            er -= 1
            ec -= 1
        return mat

#Fastest
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        return self.generateMatrixb(n, 0, 0, 0, [ [0]*n for _ in range(n) ], 1)
    
    def generateMatrixb(self, n, r, c, direc, matrix, num):
        if r < 0 or r == n or c < 0 or c == n or matrix[r][c] != 0:
            return matrix
        
        matrix[r][c] = num
        
        EAST = 0
        SOUTH = 1
        WEST = 2
        NORTH = 3
        
        vR = r
        vC = c
        
        if direc == EAST:
            vC += 1
        elif direc == SOUTH:
            vR += 1
        elif direc == WEST:
            vC -= 1
        else:
            vR -= 1
        
        if vR < 0 or vC < 0 or vR == n or vC == n or matrix[vR][vC] != 0:
            direc = (direc + 1) % 4
            if direc == EAST:
                c += 1
            elif direc == SOUTH:
                r += 1
            elif direc == WEST:
                c -= 1
            else:
                r -= 1
        else:
            r = vR
            c = vC
        
        return self.generateMatrixb(n, r, c, direc, matrix, num + 1)