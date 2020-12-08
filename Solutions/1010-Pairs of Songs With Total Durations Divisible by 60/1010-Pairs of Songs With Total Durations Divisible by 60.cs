
public class Solution {
    public int NumPairsDivisibleBy60(int[] time) {
        int cnt = 0;
        if(time.Length == 1)
            return cnt;
        var map = new int[60];
        map[time[0]%60]++;

        for(int i = 1; i<time.Length; i++){
            var mod = time[i]%60;
            var r = 60-mod == 60 ? 0 : 60-mod;
            if(map[r] != 0)
                cnt += map[r];
            
            map[mod]++;
        }
        
        return cnt;
    }
}

//Fourth fastest
public class Solution {
    public int NumPairsDivisibleBy60(int[] time) {
        
            //initialize an array of zeros whose length is equal to the sum
            //this array will be used to track how many times what answer comes up for t mod 60
            //so if time[]=[1, 59, 2, 58, 5, 120] then t mod 60 will result in [1, 59, 2, 58, 5, 0]
            //so 1th element, 59th element, 2nd element etc will be incremented
            //int[] remainders = new int[60];

            //we need the count of pairs
            //obviosly, if t mod 60 is zero, then it will end up in remainders[0]. So, we will add its count
            //else, we will add the count only if its complement is found...its complement will be in rem[60-t] position
            //so, when we are iterating, we need to see if its complement has already occured. If yes, then thats a candidate pair
            //so, we just add it to the count...if its not occured, that value will be zero..if its occured, that value will be the frequence..so eithers ways its ok
            //notice to find the complement, we dont just to rem[60-t]...rather we do rem[6--t%60]..this is to account for numbers which are greater than 60

        int[] remainders = new int[60];
        int count = 0;
            foreach (int t in time)
            {
                if (t % 60 == 0)
                    count = count + remainders[0];
                else
                    count = count + remainders[60 - t % 60];

                remainders[t % 60] = remainders[t % 60] + 1;
            }
            return count;
    }
}

//Tihrd fastest
public class Solution {
    public int NumPairsDivisibleBy60(int[] time) {
        int[] count = new int[60];
        
        foreach (var t in time)
        {
            count[t % 60] += 1;
        }
        
        var sum = 0;
        for (int i = 1; i < 30; i++)
        {
            var temp = count[60 - i];
            sum += count[i] * temp;
        }
        
        sum += count[0] * (count[0] - 1) / 2;
        sum += count[30] * (count[30] - 1) / 2;
        return sum;
    }
}

//Second fastest
public class Solution {
    public int NumPairsDivisibleBy60(int[] time) {
        int[] c = new int[60]; 
        int mod=0;int counts=0;
        for (int i = 0; i < time.Length; i++)
        {
           mod=time[i]%60;
           counts+=c[(mod==0)?0:60-mod];
           c[mod]++;
        }
        return counts;
    }
}

//Fastest
public class Solution {
    public int NumPairsDivisibleBy60(int[] time) {
        if (time == null || time.Length == 0)
            return 0;
        
        int res = 0;
        int[] mod = new int[60];
        
        foreach (var t in time)
        {
            int cur = t % 60;
            
            if (cur == 0)
                res += mod[cur];
            else
                res += mod[60 - cur];
                
            mod[cur]++;
        }
        
        return res;
    }
}