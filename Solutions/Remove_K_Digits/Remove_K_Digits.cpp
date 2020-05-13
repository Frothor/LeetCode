class Solution {
public:
    string removeKdigits(string num, int k) {
      stack<char> st;
      string ret = "";
      int n = num.size();
      for(int i = 0; i < n; i++){
         while(k && !st.empty() && st.top() > num[i]){
            st.pop();
            k--;
         }
         st.push(num[i]);
      }
      while(k--)st.pop();
      while(!st.empty()){
         ret += st.top();
         st.pop();
      }
      reverse(ret.begin(), ret.end());
      string ans = "";
      int i = 0;
      while(i <ret.size() && ret[i] == '0')i++;
      for(; i < ret.size(); i++)ans += ret[i];
      ret = ans;
      return ret.size() == 0? "0" : ret;
   }
};

/*
Faster and most common:

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(auto i:num){
            while(ans.length() && ans.back()>i && k){
                ans.pop_back();
                --k;
            }
            if(ans.length() || i!='0')
                ans+=i;
        }
        while(k--&&ans.length())
            ans.pop_back();
        return ans.length()?ans:"0";
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);

Fastest:
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() <= k) return "0";
        string ret;
        for (auto d : num) {
            while (k && ret.length() && ret.back() > d) {
                ret.pop_back();
                --k;
            }
            ret.push_back(d);
        }
        ret.resize(ret.length() - k);
        int beg = 0;
        while (beg < ret.length() - 1 && ret[beg] == '0') ++beg;
        return ret.substr(beg, ret.length() - beg + 1);
    }
};

static auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
*/