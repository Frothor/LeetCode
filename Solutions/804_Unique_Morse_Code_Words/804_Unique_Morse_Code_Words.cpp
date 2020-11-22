//Second fastest
class Solution {
private:
    vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> res;
        for (auto word : words) {
            string code;
            for (auto ch : word) {
                code += morse[ch - 'a'];
            }
            res.insert(code);
        }
        return res.size();
    }
};

//Another
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mem = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> seen;
        
        for(auto w: words){
            string code;
            for(auto c: w) code += mem[c-'a'];
            seen.insert(code);
        }
        
        return seen.size();
    }
};

//Fastest
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-."
            ,"---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> codes;
        for(auto word : words) {
            string result = "";
            for(auto ch : word) {
                result = result + morse[ch - 'a'];
            }
            codes.insert(result);
        }
        return codes.size();
    }
};