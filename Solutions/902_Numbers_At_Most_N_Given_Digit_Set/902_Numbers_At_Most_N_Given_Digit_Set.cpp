//https://leetcode.com/problems/numbers-at-most-n-given-digit-set/discuss/943946/C%2B%2B-from-DFS-to-math
class Solution { // Math
public:  // Time/Space: O(log10(N)); O(1)
  int atMostNGivenDigitSet(vector<string>& D, int N) {
    const string s = to_string(N);
    const int n = s.length(), m = D.size();
    int ans = 0;
    for (int i = 1; i < n; ++i)
      ans += pow(m, i);
    
    for (int i = 0; i < n; ++i) {
      bool prefix = false;
      for (const string& d : D) {
        if (d[0] < s[i]) {
          ans += pow(m, n - i - 1);
        } else if (d[0] == s[i]) {
          prefix = true;
          break;
        }
      }
      if (!prefix) return ans;
    }
    
    // plus one for solution N itself, all the digits are from D.
    return ans + 1;
  }
};

//Fastest
class Solution {
public:
    vector<int> num;
    vector<int> dig;
    int sol(int pos,int f){
        if(pos>=num.size()){
            return 1;
        }
        int ans=0;
        int eq=0;
        int cnt=0;
        if(f==0){
            for(int i=0;i<dig.size();++i){
                if(dig[i]<num[pos])
                    cnt++;
                if(dig[i]==num[pos])
                    eq=1;
            }
            if(cnt)
            ans+=cnt*sol(pos+1,1);
            if(eq)
            ans+=sol(pos+1,0);
        }
        else{
            ans=num.size()-1-pos+1;
            ans=(int)pow(dig.size(),ans);
        }
        return ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        dig.clear();
        num.clear();
        while(n>0){
            num.push_back(n%10);
            n/=10;
        }
        for(auto i:digits){
            dig.push_back(stoi(i));
        }
        reverse(num.begin(), num.end());
        int ans=0;
        for(int i=1;i<num.size();++i){
            ans+=(int)pow(dig.size(),i);
        }
        return ans+sol(0,0);
    }
};