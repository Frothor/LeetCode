class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() < 2)
            return true;
        if(isupper(word[0]) && isupper(word[1])){
            for(int i=2; i<word.length(); i++)
                if(islower(word[i]))
                    return false;
        }
        else{
            for(int i=1; i<word.length(); i++)
                if(isupper(word[i]))
                    return false;
        }
            
        return true;
    }
};

/*
Another:
class Solution {
public:
    bool detectCapitalUse(string word) {
     
       
        int flag = 0;
        for(int i = 0 ; i < word.size() ; i++)
        {
            if(word[i] >= 97 && word[i] <= 122 && flag == 1)
                return false;
            if(word[i] >= 65 && word[i] <= 90 && flag == 0)
            {
                if(i==1)
                {
                    if(word[0] >= 65 && word[0] <= 90)
                    {
                        flag = 1;
                    }
                    else
                        return false;
                }
                else if(i > 1)
                {
                    if(flag != 1)
                        return false;
                }
            }
                
        }
        return true;
        
    }
};
*/