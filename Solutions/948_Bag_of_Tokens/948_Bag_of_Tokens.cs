public class Solution {
    public int BagOfTokensScore(int[] tokens, int P) {
        Array.Sort(tokens);
        int beg = 0, end = tokens.Length - 1, s = 0, max_s = 0;
        while(beg <= end) {
            if(tokens[beg] <= P) {
                P -= tokens[beg];
                s += 1;
                max_s = Math.Max(max_s, s);
                beg += 1;
            }
            else if(s >= 1){
                P += tokens[end];
                s -= 1;
                end -= 1;
            }
            else
                break;
        }
        
        return max_s;
    }
}

//Third fastest
public class Solution {
    public int BagOfTokensScore(int[] tokens, int P) {
     
        Array.Sort(tokens);
        var l=0;
        var r=tokens.Length-1;
        var points=0;
        var max=0;
        while(l<=r){
            if(P>=tokens[l]){
                points++;
                P-=tokens[l++];
            }else if(points>0){
                max = Math.Max(max, points--);
                P += tokens[r--];
            }else{
                break;
            }
        }
        max = Math.Max(max, points);
        return max;
    }
    
}

//Second fastest
public class Solution {
    // Approach: Greedy. Sort the array and consider low token power for tokenUp and high for losing the points to gain max ponits.
    public int BagOfTokensScore(int[] tokens, int P) {
        Array.Sort(tokens);
        int l = 0, r = tokens.Length - 1, ans = 0, points = 0;
        while(l <= r && (P >= tokens[l] || points > 0))
        {
            while(l <= r && P >= tokens[l])
            {
                P -= tokens[l++];
                points++;
            }
            ans = Math.Max(ans, points);
            if (l <= r && points > 0)
            {
                P += tokens[r--];
                points--;
            }
        }
        
        return ans;
    }
}

//Fastest
public class Solution {
    public int BagOfTokensScore(int[] tokens, int P) {
        Array.Sort(tokens);
			int lo = 0, hi = tokens.Length - 1;
			int points = 0, ans = 0;
			while (lo <= hi && (P >= tokens[lo] || points > 0))
			{
				while (lo <= hi && P >= tokens[lo])
				{
					P -= tokens[lo++];
					points++;
				}
				ans = Math.Max(ans, points);
				if (lo <= hi && points > 0)
				{
					P += tokens[hi--];
					points--;
				}
			}
			return ans;
    }
}