class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

// Second fastest
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int len = s.length();
        string prevMaxStr = "";
        string currMaxStr = "";
        bool inStr;
        int foundIndex;

        for (int i = 0; i < len; i++)
        {
            inStr = false;
            foundIndex = 0;
            for (int j = 0; j < currMaxStr.length(); j++)
                if (currMaxStr[j] == s[i]) 
                {
                    inStr = true;
                    foundIndex = j;
                    break;
                }

            if (!inStr)
            {
                currMaxStr.push_back(s[i]);
            }
            else
            {
                if (currMaxStr.length() > prevMaxStr.length())
                    prevMaxStr = currMaxStr;
                currMaxStr = currMaxStr.substr(foundIndex+1)+ s[i];
            }		
        }
        if (currMaxStr.length() > prevMaxStr.length())
            return currMaxStr.length();
        return prevMaxStr.length();
    }
};