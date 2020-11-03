int maxPower(string s) {
        int i=0,n=s.length()-1,ans=1,c;
        while(i<n){
            c=1;
            while(s[i]==s[i+1])c++,i++; //count how many are same
            ans=max(ans,c); //max check
            i++;
        }
        return ans;
    }

//Fastest
class Solution {
public:
    int maxPower(string s) {
        int max_pow = 0, pow = 1;
        char prev = ' ';
        
        for (auto c : s){
            if (c==prev)
                pow++;
            else
                pow = 1;
            
            if (pow > max_pow)
                max_pow = pow;
            
            prev = c;
        }
        return max_pow;
    }
};