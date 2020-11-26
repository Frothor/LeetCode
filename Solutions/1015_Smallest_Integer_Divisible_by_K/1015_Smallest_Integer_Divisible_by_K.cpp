//Third fastest
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K%2==0||K%5==0)
            return -1;
        int k = 0,l = 0;
        while(k<K)
        {
            k*=10;
            k+=1;
            l+=1;
        }
        cout<<k<<"\n";
        unordered_set<int> s;
        if(k%K==0)
            return l;
        int ck = k%K;
        cout<<ck<<" "<<l<<"\n";
        while(true)
        {
            ck*=10;
            ck+=1;
            l+=1;
            if(s.find(ck%K)!=s.end())
                return -1;
            if(ck%K == 0)
            {
                return l;
            }
            s.find(ck%K);
            // cout<<ck<<" "<<l<<"\n";
            ck%=K;
        }
        return 4;
    }
};

//Second fastest
class Solution {
public:
    int smallestRepunitDivByK(int K) {

        int N = 0;
        int length = 1;
        while(length <= K) {
            
            N = (N * 10 +1) % K;
            if(N == 0) {
                return length;
            }
            length++;
        }
        return -1;
    }
};

//Fastest
class Solution {
public:
    int smallestRepunitDivByK(int K) {
      int rm=0;
        
      for (int N = 1; N <= K; ++N)
            if ( (rm = (rm * 10 + 1) % K) == 0)
                return N;
        return -1;
        
       
        
    }
};