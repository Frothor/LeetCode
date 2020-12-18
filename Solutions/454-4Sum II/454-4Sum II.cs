public class Solution {
    public int FourSumCount(int[] A, int[] B, int[] C, int[] D) {
        var map = new Dictionary<int, int>();
        int ans = 0;
        
        foreach(var a in A)
            foreach(var b in B)
                if(map.ContainsKey(a+b))
                    map[a+b]++;
                else
                    map.Add(a+b, 1);
        
        foreach(var c in C)
            foreach(var d in D)
                if(map.ContainsKey(-(c+d)))
                    ans += map[-(c+d)];
        
        return ans;
    }
}

//Third fastest
public class Solution {
    public int FourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Dictionary<int, int> ab = new Dictionary<int, int>();
        int ans = 0;
        for(int i=0;i<A.Length;i++){
            for(int j=0;j<B.Length;j++){
                int t = A[i]+B[j];
                if(ab.ContainsKey(t)){
                    ab[t]++;
                }
                else{
                    ab.Add(t, 1);
                }
            }
        }
        
        for(int i=0;i<C.Length;i++){
            for(int j=0;j<D.Length;j++){
                int t = C[i]+D[j];
                if(ab.ContainsKey(-t)){
                    ans += ab[-t];
                }
            }
        }      
        
        return ans;
        
        
    }
}

//Second fastest
public class Solution {
    public int FourSumCount(int[] A, int[] B, int[] C, int[] D) {
        var AB = new Dictionary<int,int>();
        foreach (int a in A) {
            foreach (int b in B) {
                if (AB.ContainsKey(-(a+b))) AB[-(a+b)]++;
                else AB.Add(-(a+b), 1);
            }
        }
        int res = 0;
        foreach (int c in C) {
            foreach (int d in D) {
                if (AB.TryGetValue(c+d, out var cnt)) {
                    res += cnt;
                }
            }
        }
        return res;
    }
}

//Fastest
public class Solution {
    public int FourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int res=0;
        Dictionary<int, int> subSums = new Dictionary<int, int>();
        for (int a=0; a<A.Length; a++)
            for(int b=0;b<B.Length;b++) {
                int x = A[a]+B[b];
                if(subSums.ContainsKey(x)) subSums[x]++;
                else subSums[x] = 1;
            }
                for(int c=0;c<C.Length;c++)
                    for (int d=0;d<D.Length;d++) {
                        int x = -C[c] - D[d];
                        if (subSums.ContainsKey(x)) res+=subSums[x];
                    }
                
        return res;
    }
}