#Third fastest
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        
        sol = 0
        
        A2 = {}
        B2 = {}
        C2 = {}
        D2 = {}
        
        twoSumX = {}
        twoSumXX = {}
        
        for i in A:
            if A2.get(i) == None:
                A2[i] = 1
            else:
                A2[i] += 1
        for i in B:
            if B2.get(i) == None:
                B2[i] = 1
            else:
                B2[i] += 1
        for i in C:
            if C2.get(i) == None:
                C2[i] = 1
            else:
                C2[i] += 1
        for i in D:
            if D2.get(i) == None:
                D2[i] = 1
            else:
                D2[i] += 1
        
        for i in A2:
            for j in B2:
                if twoSumX.get(i + j) == None:
                    twoSumX[i + j] = A2[i] * B2[j]
                else:
                    twoSumX[i + j] += A2[i] * B2[j]

        for i in C2:
            for j in D2:
                if -(i + j) in twoSumX:
                    sol += twoSumX[-(i + j)] * C2[i] * D2[j]
                
        
        return sol

#Second fastest
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        if len(A) == 0:
            return 0
        
        m1 = {}
        for a in A:
            if a in m1:
                m1[a] += 1
            else:
                m1[a] = 1
        m2 = {}
        for a, v in m1.items():
            for b in B:
                ab = a + b
                if ab in m2:
                    m2[ab] += v
                else:
                    m2[ab] = v
        
        m3 = {}
        for c in C:
            if c in m3:
                m3[c] += 1
            else:
                m3[c] = 1
        
        res = 0
        for c, v in m3.items():
            for d in D:
                cd = - c - d
                if cd in m2:
                    res += m2[cd] * v
                
        return res
#     def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
#         n = len(A)
#         dic =defaultdict(int)
#         res = 0
      
#         dic1 = collections.Counter(A)
#         #print(dic1)
#         dic2 = defaultdict(int)
        
#         for i in range(n):
#             for k,v in dic1.items():
#                 ab = B[i] + k                
#                 dic2[ab] +=v 
#         #print(dic2)
#         dic3 = defaultdict(int)
#         for i in range(n):
#             for k,v in dic2.items():
#                 abc = C[i] + k
#                 dic3[abc] +=v
#         #print(dic3)
        
#         dic4 = collections.Counter(D)
#         for k,v in dic3.items():
#             if -k in D:
#                 res += v * dic4[-k]
                
#         #print(dic2)
#         return res
        
#     def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
#         n = len(A)  
#         res = 0
#         dic1 =defaultdict(int)
#         for i in range(n):
#             dic1[i] = A[i]
        
#         dic2 = defaultdict(int)
#         for i in range(n):
#             for key in dic1.keys():
#                 dic2[str(i)+str(key)] = dic1[key]+B[i]
#         dic1.clear()
        
#         for i in range(n):
#             for key in dic2.keys():
#                 dic1[str(i)+str(key)] =C[i] + dic2[key]
#         dic2.clear()
        
#         for i in range(n):
#             for key in dic1.keys():
#                 dic2[str(i)+str(key)] =D[i]+dic1[key]
#                 if dic2[str(i)+str(key)]== 0:res+=1
        
#         return res
    # def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
    #     count=  Counter( a+b for a in A for b in B  )  
    #     #print(count)
    #     return sum(   count[-c-d] for c in C   for d in D)

#Fastest
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        if len(A) == 0:
            return 0
        
        m1 = {}
        for a in A:
            if a in m1:
                m1[a] += 1
            else:
                m1[a] = 1
        m2 = {}
        for a, v in m1.items():
            for b in B:
                ab = a + b
                if ab in m2:
                    m2[ab] += v
                else:
                    m2[ab] = v
        
        m3 = {}
        for c in C:
            if c in m3:
                m3[c] += 1
            else:
                m3[c] = 1
        
        res = 0
        for c, v in m3.items():
            for d in D:
                cd = - c - d
                if cd in m2:
                    res += m2[cd] * v
                
        return res