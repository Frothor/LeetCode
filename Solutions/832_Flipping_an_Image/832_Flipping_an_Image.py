class Solution:
    def flipAndInvertImage(self, A):
        return [[1^q for q in row[::-1]] for row in A]


#Third fastest
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        result = []
        for row in A:
            new_row = []
            result.append(new_row)
            for x in reversed(row):
                new_row.append(int(not x))
        return result


#Second fastest
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:

        for i in range(len(A)): 
            A[i].reverse()
            for j in range(len(A[i])): 
                if A[i][j] == 0: 
                    A[i][j] = 1
                else: 
                    A[i][j] = 0
        return A

#Fastest
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        
        B = [[] * len(A)]
        for row in A:
            for j in range((len(row) + 1) // 2):
                row[j], row[~j] = row[~j] ^ 1, row[j] ^ 1
        
        return A