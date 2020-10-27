public class Solution {
    public double ChampagneTower(int poured, int query_row, int query_glass) {
        double[,] dp = new double[102, 102];
        dp[0, 0] = (double)poured;
        for (int r = 0; r <= query_row; ++r) {
            for (int c = 0; c <= r; ++c) {
                double q = (dp[r, c] - 1.0) / 2.0;
                if (q > 0) {
                    dp[r+1, c] += q;
                    dp[r+1, c+1] += q;
                }
            }
        }

        return Math.Min(1, dp[query_row, query_glass]);
    }
}

//Second fastest
public class Solution {
    public double ChampagneTower(int poured, int query_row, int query_glass) {
        var glasses = new double[query_row + 2, query_row + 2];
        glasses[0, 0] = poured;
        for (var i = 0; i <= query_row; i++) {
            for (var j = 0; j <= i; j++) {
                var excess = glasses[i - j, j] - 1;
                if (excess > 0) {
                    glasses[i - j, j] = 1;
                    glasses[i - j + 1, j] += excess / 2;
                    glasses[i - j, j + 1] += excess / 2;
                }
                
                if (query_row == i && query_glass == j) {
                   return glasses[i - j, j];
                }
            }
        }
        
        return 0;
    }
}

/*

 0 0 0 0
 0 0 0 0
 0 0 0 0
 0 0 0 0

*/

//Fastest
public class Solution {
    // 1
    // 1 (1, 1)
    // 1 (1, 1) (0.5, 1, 0.5)
    // 1 (1, 1) (1, 1, 1) (0, 0.5, 0.5, 0)
    // 1 (1, 1) (1, 1, 1) (1/6, 1, 1, 1/6)
    // 1 (1, 1) (1, 1, 1) (1/2, 1, 1, 1/2) (0, 0.5, 1, 0.5, 0) 
    
    // 1
    // 0.5 0.5
    // 0.25  0.5  0.25
    // 0.125 0.375 0.375 0.125
    // 1 4 6 4 1
    public double ChampagneTower(int poured, int query_row, int query_glass) {
        double[] row = new double[query_row+1];
        double p = poured * 1.0;
        row[0] = p;
        for (int i = 1; i <= query_row; i++) {
            double l = row[i-1]>1?(row[i-1]-1)/2.0:0;
            double r = 0;
            row[i] = l;
            for (int j = i-1; j > 0; j--) {
                l = row[j-1]>1?(row[j-1]-1.0)/2.0:0;
                r = row[j]>1?(row[j]-1.0)/2.0:0;
                row[j] = l + r;
            }
            r = row[0]>1?(row[0]-1.0)/2.0:0;
            row[0] = r;
        }
        return Math.Min(row[query_glass], 1.0);
    }
}