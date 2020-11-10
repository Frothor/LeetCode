//Third fastest
public class Solution {
    public int[][] FlipAndInvertImage(int[][] A) {
        int m = A.Length;
        int n = A[0].Length;
        
        for(int i=0; i<m; i++){
            Array.Reverse(A[i]);
            for(int j=0; j<n; j++)
                A[i][j] ^= 1;
        }
        
        return A;
    }
}

//Another
public class Solution {
    public int[][] FlipAndInvertImage(int[][] A) {
        int[][] B = new int[A.Length][];
        
        for (int i = 0; i < A.Length; i++)
            B[i] = new int[A[0].Length];
        
        for (int i = 0; i < A.Length; i++){
            for (int j = 0; j < A[0].Length; j++){
                B[j][i] = A[j][A.Length-i-1];
            }
        }
        
        for (int i = 0; i < A.Length; i++)
            for (int j = 0; j < A[0].Length; j++)
                if (B[j][i] == 0)
                    B[j][i] = 1;
                else
                    B[j][i] = 0;
        
        return B;
    }
}

//Second fastest
public class Solution {
    public int[][] FlipAndInvertImage(int[][] A) {
        
        for (var i = 0; i < A.Length; ++i)
        {
            var l = A[i].Length;
            for (var j = 0; j < (l / 2); ++j)
            {
                var temp = A[i][j];
                A[i][j] = (A[i][l - j - 1])^1;
                A[i][l - j - 1] = (temp)^1;
            }
            if (l % 2 == 1)
                A[i][l / 2] = (A[i][l / 2])^1;
        }
        
        return A;
        /*
        for (int i=0; i<A.Count(); i++) {
            int left = 0;
            int right = A[i].Count()-1;
            
            for (int j=0; j<A[i].Count(); j++) {
                A[i][j] = A[i][j]^1;
            }
            Array.Reverse(A[i]);
            
        }
        
        return A;
        */
    }
}

//Fastest
public class Solution
{
    private int Flip(int bit)
    {
        return bit == 0 ? 1 : 0;    
    }
    
    public int[][] FlipAndInvertImage(int[][] A)
    {
        for (var i = 0; i < A.Length; ++i)
        {
            var l = A[i].Length;
            for (var j = 0; j < (l / 2); ++j)
            {
                var temp = A[i][j];
                A[i][j] = Flip(A[i][l - j - 1]);
                A[i][l - j - 1] = Flip(temp);
            }
            if (l % 2 == 1)
                A[i][l / 2] = Flip(A[i][l / 2]);
        }
        
        return A;
    }
}