//Third fastest
public class Solution {
    public int MirrorReflection(int p, int q) {
        if(p ==  q)
            return 1;
        if(q == 0)
            return 0;
        int r = q;
        int d = 0;
        int k =0;
        while(!(r == 0 || r == p)){
            if(k==0){
                if(r+q > p){
                    r = p-(q-(p-r));
                    k=~k;
                }
                else{
                    r += q;
                    d = ~d;
                }
            }
            else{
                 if(r-q < 0){
                    r = q -r;
                    k=~k;
                }
                else{
                    r -= q;
                    d = ~d;
                }
            }
        }
        return getnum(r,p,d);
    }
    public int getnum(int r,int p,int d){
        //Console.WriteLine("r {0} d {1}",r,d);
        if(r==0)
            return 0;
        else{
            if(d == 0)
                return 1;
            else
                return 2;
        }
    }
}

//Second fastest
public class Solution {
   private int MaxCommon(int a, int b)
    {
        if (a > b) return MaxCommon(b, a);
        b %= a;
        if (0 == b) return a;
        return MaxCommon(b, a);
    }
    public int MirrorReflection(int p, int q) {
        if (0 == q) return 0;
        if (1 == p) return 1;
        int com = MaxCommon(p, q);
        int cross = p / com;
        int step = q / com;
        if (0 == (cross & 1)) return 2;
        return (1 == (step & 1)) ? 1 : 0;
    }
}

//Fastest
public class Solution {
    public int MirrorReflection(int p, int q) {
        int k = 1;
        
        while(k*q%p != 0) k+=1;
        return k%2==0 ? 2 : (k*q/p)%2;
    }
}