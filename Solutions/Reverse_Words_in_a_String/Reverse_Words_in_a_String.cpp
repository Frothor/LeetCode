class Solution {
public:
    string reverseWords(string s) {
        string result;
        int i = 0;
        int n = s.length();
        
        while(i < n){
            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;
            int j = i + 1;
            while(j < n && s[j] != ' ') j++;
            string sub = s.substr(i, j-i);
            if(result.length() == 0) result = sub;
            else result = sub + " " + result;
            i = j+1;
        }
        
        return result;
    }
};

/*
Most common:
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        stack<string> temp;
        string k;
        while (ss>>k) {
            temp.push(k);
        }
        string ans;
        bool first = true;
        while (!temp.empty()) {
            if (!first) ans += ' ';
            first = false;
            ans += temp.top();
            temp.pop();
        }
        return ans;
    }
};

Fastest:
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string reverseWords(string s) {
        string result;
        
        int index, index2;
        
        index = 0;
               
        if(s == "") return s;
        
        result = "";
        
        index = s.find_last_not_of(' ');
        
        if(index == -1){
            return "";    
        }else{
            s.erase(index + 1);    
        }

        index = 0;
        
        while(index >= 0){
            
            index = s.find_first_not_of(' ', index);
            
            if(index != -1){
                index2 = s.find(' ', index);
                
                if(result != ""){
                    result.insert(0, " "); 
                }
                
                //result.insert(0, s, index, index2 - index);
                  
                result = s.substr(index, index2 - index) + result;
                
                if(index2 >= 0){                                       
                    index = index2;
                }else{
                    return result;                    
                }    
            }
        }
        
        return result;    
    }
};
*/