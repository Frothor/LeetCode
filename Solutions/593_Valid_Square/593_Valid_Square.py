class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        def dist(p,q):
            return (p[0]-q[0])**2 + (p[1]-q[1])**2
        
        def check(p1,p2,p3,p4):
            if p1[0]+p2[0] != p3[0]+p4[0] or p1[1]+p2[1] != p3[1]+p4[1]: return False
            if dist(p1,p2) != dist(p3,p4) or dist(p1,p4) != dist(p2,p4): return False
            if p1 == p2: return False
            return True
        
        return check(p1,p2,p3,p4) or check(p1,p3,p2,p4) or check(p1,p4,p2,p3)

#Third fastest
import itertools

class Solution:
    
    
    def get_multiplicities(self, points):
        
        distances = {}
        
        for combination in itertools.combinations(points, 2):
            distance = math.sqrt((combination[0][0] - combination[1][0]) ** 2 + (combination[0][1] - combination[1][1]) ** 2)
            if distance not in distances.keys():
                distances[distance] = 0
            if len(distances) > 2:
                return False
            distances[distance] += 1
        
        return len(distances) == 2 and 2 in distances.values() and 4 in distances.values()
    
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        return self.get_multiplicities([p1, p2, p3, p4])

#Second fastest
class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        def dist(P, Q):
            return (P[0] - Q[0])**2 + (P[1] - Q[1])**2

        D = [dist(p1, p2), dist(p1, p3), dist(p1, p4),
             dist(p2, p3), dist(p2, p4), dist(p3, p4)]
        D.sort()
        return 0 < D[0] == D[1] == D[2] == D[3] and 2*D[0] == D[4] == D[5]

#Fastest
class Solution:
    def distance(self,p1,p2):
        x1,y1 = p1
        x2,y2 = p2 
        return math.sqrt(((x2 - x1) ** 2) + ((y2 - y1) ** 2))
        
        
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
          
        # if p1==p2 or p1==p3 or p1==p4 or p2==p3 or p2==p4 or p3==p4:
        #     return False

        points = [[p1,p2],[p1,p3],[p1,p4],[p2,p3],[p2,p4],[p3,p4]]
        res=[]

        for i in points:
            res.append(self.distance(i[0],i[1]))
            
        h={}

        for i in res:
            if i not in h:
                h[i] = 1
            else:
                h[i]+=1
        for i in h.values():
            if (i==2 or i==4) and len(h)==2:
                continue
            else:
                return False
        return True

        # if len(set(res))==2:
        #     return True
        # else:
        #     return False