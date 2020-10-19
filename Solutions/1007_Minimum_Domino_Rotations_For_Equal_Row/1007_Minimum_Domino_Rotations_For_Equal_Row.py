#Third fastest
class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        possible_sol = {A[0],B[0]}
        
        for i in possible_sol:
            A_swap = 0
            B_swap = 0
            flag = 0
            for j in range(len(A)):
                if A[j] == B[j] == i:
                    pass
                elif A[j] == i:
                    B_swap += 1
                elif B[j] == i:
                    A_swap += 1
                else:
                    flag = 1
                    break
                    
            if flag == 0:
                return min(A_swap,B_swap)
        return -1

#Second fastest
class Solution:        
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        def check(x):
            """
            Return min number of swaps 
            if one could make all elements in A or B equal to x.
            Else return -1.
            """
            # how many rotations should be done
            # to have all elements in A equal to x
            # and to have all elements in B equal to x
            rotations_a = rotations_b = 0
            for i in range(n):
                # rotations coudn't be done
                if A[i] != x and B[i] != x:
                    return -1
                # A[i] != x and B[i] == x
                elif A[i] != x:
                    rotations_a += 1
                # A[i] == x and B[i] != x    
                elif B[i] != x:
                    rotations_b += 1
            # min number of rotations to have all
            # elements equal to x in A or B
            return min(rotations_a, rotations_b)
    
        n = len(A)
        rotations = check(A[0]) 
        # If one could make all elements in A or B equal to A[0]
        if rotations != -1 or A[0] == B[0]:
            return rotations 
        # If one could make all elements in A or B equal to B[0]
        else:
            return check(B[0])

#Fastest
class Solution:        
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        assert(len(A)>=2)
        def check(x):
            """
            Return min number of swaps 
            if one could make all elements in A or B equal to x.
            Else return -1.
            """
            # how many rotations should be done
            # to have all elements in A equal to x
            # and to have all elements in B equal to x
            rotations_a = rotations_b = 0
            for i in range(n):
                # rotations coudn't be done
                if A[i] != x and B[i] != x:
                    return -1
                # A[i] != x and B[i] == x
                elif A[i] != x:
                    rotations_a += 1
                # A[i] == x and B[i] != x    
                elif B[i] != x:
                    rotations_b += 1
            # min number of rotations to have all
            # elements equal to x in A or B
            return min(rotations_a, rotations_b)
    
        n = len(A)
        rotations = check(A[0]) 
        # If one could make all elements in A or B equal to A[0]
        if rotations != -1:
            return rotations 
        # If one could make all elements in A or B equal to B[0]
        else:
            return check(B[0])