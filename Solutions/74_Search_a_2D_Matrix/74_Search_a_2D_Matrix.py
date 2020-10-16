class Solution:
    def searchMatrix(self, matrix, target):
        if not matrix or not matrix[0]: return False
        m, n = len(matrix[0]), len(matrix)
        beg, end = 0, m*n - 1
        while beg < end:
            mid = (beg + end)//2
            if matrix[mid//m][mid%m] < target:
                beg = mid + 1
            else:
                end = mid
        return matrix[beg//m][beg%m] == target

#Third fastest
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return 0
        
        m=len(matrix)
        n=len(matrix[0])
        l=0
        r=m*n-1
        
        
        while l<=r:
            mid=(l+r)//2
            nums=matrix[mid//n][mid%n]
            if nums==target:
                return True
            elif nums<target:
                l=mid+1
            else:
                r=mid-1
        return False

#Second fastest
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return 0
        elif not matrix[0]:
            return 0
        firstCol = []
        for row in matrix:
            firstCol.append(row[0])
        rowId = bisect.bisect(firstCol, target) - 1
        if matrix[rowId][0] == target:
            return True
        colId = bisect.bisect(matrix[rowId], target) - 1
        #print(rowId, colId)
        try:
            if matrix[rowId][colId] == target:
                return True
            else:
                return False
        except:
            return False


#Fastest
class Solution:
    def searchMatrix(self, ma: List[List[int]], target: int) -> bool:
        if len(ma)>0:
            n=len(ma)
            m=len(ma[0])

            low=0
            high=n*m-1
            while low<=high:
                mid=low+(high-low)//2
                if ma[mid//m][mid%m]==target:
                    return True
                elif ma[mid//m][mid%m]>target:
                    high=mid-1
                elif ma[mid//m][mid%m]<target:
                    low=mid+1
            else:
                return False
        else:
            return False
