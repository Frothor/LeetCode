//Intuitive
public class Solution {
    private int CountRotations(int target, int[] A, int[] B) {
        int count = 0;
        for(int i = 0; i < A.Length; i++) {
            if(A[i] != target) {
                if(B[i] == target)
                    count++;
                else
                    return Int32.MaxValue;
            }
        }
        return count;
    }
    public int MinDominoRotations(int[] A, int[] B) {
        int resA = Math.Min(CountRotations(A[0], A, B), CountRotations(A[0], B, A));
        int resB = Math.Min(CountRotations(B[0], A, B), CountRotations(B[0], B, A));
        int result = Math.Min(resA, resB);
        return result == Int32.MaxValue ? -1: result;
    }
}

//Third fastest
public class Solution {
    public int MinDominoRotations(int[] A, int[] B) {
  
        int num1 = A[0];
        int num2 = B[0];
        
        var res = Math.Min(MinD(A,B,1,num1,num2),MinD(A,B,0,num2,num1) );
          
        return res ==A.Length+1?-1:res;
    }
    
    private int MinD(int[] A, int[] B,int i, int num1, int num2){
        bool n1 = true;
        bool n2 = true;
        
        int cnt1=0;
        int cnt2 =0;
        
         for(; i<A.Length; i++){
            
            if(n1){
                if(num1 != A[i] && num1!=B[i]){
                    n1 = false;
                }
                else if(num1!= A[i] && num1 == B[i]){
                    cnt1++;
                   // Console.WriteLine(num1+" "+i);
                }
            }
            
            if(n2){
                if(num2 != A[i] && num2!=B[i]){
                    n2 = false;
                }
                else if(num2!=B[i] && num2 == A[i]){
                    cnt2++;
                   // Console.WriteLine(i);
                }
            }
        }       
        return Math.Min(n1?cnt1:A.Length+1,n2?cnt2:A.Length+1);
    }
}

//Second fastest
public class Solution {
    public int MinDominoRotations(int[] A, int[] B) {
        int n = A.Length;
        for (int i=0, a=0, b=0; i<n && (A[i] == A[0] || B[i] == A[0]); ++i) {
            if (A[i] == A[0]) a++;
            if (B[i] == A[0]) b++;
            if (i == n-1) return Math.Min(n-a, n-b);
        }
        for (int i=0, a=0, b=0; i<n && (A[i] == B[0] || B[i] == B[0]); ++i) {
            if (A[i] == B[0]) a++;
            if (B[i] == B[0]) b++;
            if (i == n-1) return Math.Min(n-a, n-b);
        }
        return -1;
    }
}

//Fastest
public class Solution {
    public int MinDominoRotations(int[] A, int[] B) {
        
        int numRotationsA0 = Check(A[0], A, B);
        int numRotationsB0 = Check(B[0], A, B);
        
        if(numRotationsA0 != -1 && numRotationsB0 != -1){
            return Math.Min(numRotationsA0, numRotationsB0);
        }
        
        if(numRotationsA0 != -1)
            return numRotationsA0;
        
        return numRotationsB0;
    }
    
    public int Check(int num, int []A, int []B){
        var aRots = 0;
        var bRots = 0;
        
        for(var i=0; i < A.Length; ++i){
            
            if(A[i] != num && B[i] != num)
                return -1;
            
            if(A[i] != num){
                aRots++;
            }
            
            if(B[i] != num){
                bRots++;
            }
        }
        
        return Math.Min(aRots, bRots);
    }
}