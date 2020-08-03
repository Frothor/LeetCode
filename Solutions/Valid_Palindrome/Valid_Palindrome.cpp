class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() <= 1)
            return true;
        
        int i = 0, j = s.length() - 1;
        
        while(i < j){
            while(i < j && !isalnum(s[i])) i++;
        
            while(j > i && !isalnum(s[j])) j--;
        
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            
            i++;
            j--;
        }
        return true;        
    }
};

/*
Fastest:
class Solution {
public:
    bool isPalindrome(string s) 
    {
        int l =0;
        int r = s.size()-1;
        while(l<r)
        {
            if(isalnum(s[l]) && isalnum(s[r]))
            {                
                if(tolower(s[l])!=tolower(s[r]))
                    return false;
                else
                {
                    l++;r--;
                    continue;
                }
            }
            else 
            {
                
                if(!isalnum(s[l]))
                    l++;
                if(!isalnum(s[r]))
                    r--;
            }
        }
        return true;
        
    }
};
*/