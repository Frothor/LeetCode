public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        int m = matrix.Length;
        if(m == 0)
            return false;
        int n = matrix[0].Length;
        if(n == 0)
            return false;
        for(int i = 0; i < m; i++) {
            if(target >= matrix[i][0] && target <= matrix[i][n-1]) {
                int l = 0, h = n-1;
                while(l <= h) {
                    int mid = l + (h-l)/2;
                    if(matrix[i][mid] == target)
                        return true;
                    else if(target > matrix[i][mid])
                        l = mid + 1;
                    else
                        h = mid - 1;
                }
            }
        }
        return false;
    }
}

//Fourth fastest
public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.Length == 0 || matrix[0].Length == 0)
        {
            return false;
        }

        int matrixRow = matrix.Length;
        int matrixCol = matrix[0].Length;

        int start = 0;
        int end = matrixRow * matrixCol - 1;

        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;

            if (GetValueBySequence(matrix, mid) <= target)
            {
                start = mid;
            }
            else
            {
                end = mid - 1;
            }
        }

        if (GetValueBySequence(matrix, start) == target ||
            GetValueBySequence(matrix, end) == target)
        {
            return true;
        }

        return false;
    }    

    private int GetValueBySequence(int[][] matrix, int sequence)
    {
        int colSize = matrix[0].Length;

        int row = sequence / colSize;
        int col = sequence % colSize;

        return matrix[row][col];
    }
}

//Third second
public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        if(matrix == null || matrix.Length == 0) return false;
        
        int length = matrix.Length * matrix[0].Length;
        
        return BinarySearch(0, length-1, target, matrix);
    }
    
    public bool BinarySearch(int left, int right, int target, int[][] matrix)
    {
        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            int row = middle / matrix[0].Length;
            int col = middle % matrix[0].Length;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) left = middle+1;
            else right = middle-1;
        }
        
        return false;
    }
}

//Second fastest
public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        if (matrix.Length == 0 || matrix[0].Length == 0) return false;
            if (matrix.Length == 1) return Array.BinarySearch(matrix[0], target) >= 0;
            int li = 1, hi = matrix.Length - 1;
            while (li <= hi)
            {
                int mid = li + (hi - li) / 2;
                if (matrix[mid][0] == target) return true;
                if (matrix[mid][0] > target)
                    hi = mid - 1;
                else
                    li = mid + 1;
            }
            return Array.BinarySearch(matrix[hi], target) >= 0;
    }
}

//Fastest
public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
      int rowCount = matrix.Length;
        
        int colCount=0;
        if(rowCount>0)
        {
             colCount = matrix[0].Length;
        }
            

            int j = colCount - 1;
            int i = 0;

            while(j>=0 && i<rowCount)
            {
                if(matrix[i][j]==target)
                {
                    return true;
                }
                else if(matrix[i][j]<target)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }

             return false;
    }
}