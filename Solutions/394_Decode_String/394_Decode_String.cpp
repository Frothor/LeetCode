//https://leetcode.com/problems/decode-string/discuss/941380/C%2B%2B-Amazing-Easy-Iterative-Fully-Explained-Solution-Faster-than-100
class Solution {
public:
    // Helper function to repeat substring a number of times:
    string repeat(string str, int times) {
        string res = "";
        for (int i=0; i<times; i++)
            res += str;
        return res;
    }
    
    string decodeString(string s) {
        int i=0;
        while (i < s.size()) {
            if (s[i] != ']') {
                i++;
                continue;
            }
            
            // When we get to closing parenthesis,
            // we will look back to get the letters to repeat and the number of times
            // then we replace the original part in the string and place i after that to continue.
            int j = i;
            while (s[j] != '[') // Extract letters
                j--;
        
            string letters_to_repeat = s.substr(j+1, i-j-1);
            int k = j;
            j--;
            while ((j > 0) &&(isdigit(s[j]))) // Before opening parethesis we get the number
                j--;
            
            if (j != 0) j++; // Edge case where we are at the beginning of the string
            int times_to_repeat = stoi(s.substr(j, k-j));
            
            s.replace(j, i-j+1, repeat(letters_to_repeat, times_to_repeat));
			
            // Put i in the right place now
            i = j+letters_to_repeat.size()*times_to_repeat;
        }
        return s;
    }
};

//Another
class Solution {
public:
    string decodeString(string s) {
        int i=0;
        return generate(s, i);
    }

private:
    string generate(string& s, int& i) {
        string result;
        while (i<s.size() && s[i] != ']') {
            if (!isdigit(s[i])) {
                result += s[i++];
            } else {
                int num=0;
                while (i<s.size() && isdigit(s[i]))
                    num = num*10 + (s[i++]-'0');
                
                i++;
                string temp = generate(s, i);
                i++;
                
                while (num--)
                    result += temp;
            }
        }
        return result;
    }
};