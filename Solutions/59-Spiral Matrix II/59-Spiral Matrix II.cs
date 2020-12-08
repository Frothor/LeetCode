//Fourth fastest
public class Solution {
    public int[][] GenerateMatrix(int n) {
        int[][] A = new int[n][];
        for(int i=0;i<n;i++)
            A[i] = new int[n];
            
        if(n == 0)
            return A;
        
        int top = 0, left = 0, bottom = n-1, right = n-1;
        
        int count = 1;
        while(count <= n*n)
        {
            for(int j=left; j<=right && count <= n*n; j++)
                A[top][j] = count++;
            top++;
            
            for(int i=top; i<=bottom && count <= n*n; i++)
                A[i][right] = count++;
            right--;
            
            for(int j=right; j>=left && count <= n*n; j--)
                A[bottom][j] = count++;
            bottom--;
            
            for(int i=bottom; i>=top && count <= n*n; i--)
                A[i][left] = count++;
            left++;
        }
        
        return A;
    }
}

//Third fastest
public class Solution {
    public int[][] GenerateMatrix(int n) {
        
        int[][] result= new int[n][];
        for (int i = 0; i < n; i++)
            result[i] = new int[n];

        int left, right, top, bottom, number;
        left = top = number = 0;
        right = bottom = n-1;
        
        while (left <= right && top <= bottom) {
            // top: left to right
            for (int j = left; j <= right; j++) {
                result[top][j] = ++number;
            }
            top++;
            
            // right: top to bottom
            for (int i = top; i <= bottom; i++) {
                result[i][right] = ++number;
            }
            right--;
            
            // bottom: right to left
            for (int j = right; j >= left; j--) {
                result[bottom][j] = ++number;
            }
            bottom--;
            
            // left: bottom to top
            for (int i = bottom; i >= top; i--) {
                result[i][left] = ++number;
            }
            left++;
        }
        return result;        
    }
}

//Second fastest
public class Solution {
    public int[][] GenerateMatrix(int n) 
    {
      int[][] matrix = new int[n][]; 
      for(int i=0; i<n ; i++)
          matrix[i]= new int[n];
      var dir = new List<int[]>{new int[]{0,1},new int[]{1,0},new int[]{0,-1},new int[]{-1,0}};
      var x=0;
      var y=0;
      var d =0;
      var count=1; 
      while(count<= (n*n))
      {
          matrix[x][y]=count;
          var newx= x+dir[d][0];
          var newy= y+dir[d][1];
          if(newx>=0 && newy>=0 && newx<n && newy<n && matrix[newx][newy]==0)
          {
              x=newx;
              y=newy;
          }else
          {
             
             d=(d==3? 0: d+1);
             x= x+dir[d][0];
             y= y+dir[d][1]; 
          }
          count++;
      }
      return matrix;  
    }
}

//Fastest
public class Solution {
    public int[][] GenerateMatrix(int n) {
        var ans = new int[n][];
        for(int i =0; i<n; i++)
            ans[i] = new int[n];
        
        int colStart = 0;
        int colEnd = n-1;
        int rowStart = 0;
        int rowEnd = n-1;
        int counter = 1;
        
        while(colStart <= colEnd && rowStart <= colEnd){
            for(int i = colStart; i<=colEnd; i++)
                ans[rowStart][i] = counter++;
            
            rowStart++;
            
             for(int i = rowStart; i<=rowEnd; i++)
                ans[i][colEnd] = counter++;
            
            colEnd--;
            
            for(int i = colEnd; i>=colStart; i--)
                ans[rowEnd][i] = counter++;
            
            rowEnd--;
            
            for(int i = rowEnd; i>=rowStart; i--)
                ans[i][colStart] = counter++;
            
            colStart++;
        }
        return ans;
    }
}

//Another
public class Solution {
    public int[][] GenerateMatrix(int n)
    {
        // Declaration
        int[][] matrix = new int[n][];
        for (var i = 0; i < n; i++) matrix[i] = new int[n];

        // Edge Case
        if (n == 0)
        {
            return matrix;
        }

        // Normal Case
        var rowStart = 0;
        var rowEnd = n - 1;
        var colStart = 0;
        var colEnd = n - 1;
        var num = 1; //change

        while (rowStart <= rowEnd && colStart <= colEnd)
        {
            for (var i = colStart; i <= colEnd; i++)
                matrix[rowStart][i] = num++; //change


            rowStart++;

            for (var i = rowStart; i <= rowEnd; i++)
                matrix[i][colEnd] = num++; //change


            colEnd--;

            for (var i = colEnd; i >= colStart; i--)
            {
                if (rowStart <= rowEnd)
                    matrix[rowEnd][i] = num++; //change
            }

            rowEnd--;

            for (var i = rowEnd; i >= rowStart; i--)
            {
                if (colStart <= colEnd)
                    matrix[i][colStart] = num++; //change
            }

            colStart++;
        }

        return matrix;
    }
}