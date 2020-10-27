class Solution:
    def champagneTower(self, poured, query_row, query_glass):
        l = [poured]
        for _ in range(query_row):
            l_new = [0] * (len(l) + 1)
            for i in range(len(l)):
                pour = (l[i] - 1)/2
                if pour > 0:
                    l_new[i] += pour
                    l_new[i+1] += pour
            
            l = l_new
                    
        return min(1, l[query_glass])

#Third fastest
class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        q = [poured]
        for row in range(query_row):
            q2 = [0] * (len(q) + 1)
            for i, j in enumerate(q):
                if j <= 1:
                    continue
                overflow = j - 1
                q2[i] += overflow * 0.5
                q2[i + 1] += overflow * 0.5
            q = q2
        return min(q[query_glass], 1)

#Second fastest
class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        # corner case: poured == 0
        if poured == 0:
            return 0
        # we could use bfs find result from top to bottom
        row = 0
        # when row = k, level[j]: the volune poured through row at query[k][j]
        level = [poured]
        while row < query_row:
            row += 1
            tmp = [0]
            for p in level:
                if p <= 1:
                    tmp.append(0)
                else:
                    tmp[-1] += (p-1)/2
                    tmp.append((p-1)/2)
            # if the whole row is empty, return 0
            if sum(tmp) == 0:
                return 0
            level = tmp
        return level[query_glass] if level[query_glass] < 1 else 1.0
        

#Fastest
class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        # shrink cache of size query_row ^ 2  to query_row.
        glasses = [poured] + [0] * query_row
        
        # In-place expansion to save memory
        for r in range(query_row):
            #reverse traversal sequence
            for c in range(r, -1, -1):
                overflow = 0
                
                # if the glass above overflows
                if glasses[c] > 1:
                    overflow = (glasses[c] - 1) / 2
                    glasses[c+1] += overflow
                    
                glasses[c] = overflow
                
                
        return min(1, glasses[query_glass])