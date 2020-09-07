public class Solution
{
    public int LargestOverlap(int[][] A, int[][] B)
    {
        int res = 0;
        int N = A.Length;
        var count = new int[N * 2, N * 2];
        for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        for (int m = 0; m < N; m++)
        for (int n = 0; n < N; n++)
        {
            if (A[i][j] == 0 || B[m][n] == 0) continue;
            res = Math.Max(res, ++count[N + i - m, N + j - n]);
        }

        return res;
    }
}

//Improved the performance

public class Solution
{
    public int LargestOverlap(int[][] A, int[][] B)
    {
        int res = 0;
        int N = A.Length;
        var count = new int[N * 2, N * 2];
        for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (A[i][j] == 0) continue;
            for (int m = 0; m < N; m++)
            for (int n = 0; n < N; n++)
            {
                if (B[m][n] == 0) continue;
                res = Math.Max(res, ++count[N + i - m, N + j - n]);
            }
        }

        return res;
    }
}