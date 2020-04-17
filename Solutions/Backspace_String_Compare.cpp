/*
LeetCode Backspace String Compare

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".


Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".


Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".


Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.


Follow up:

Can you solve it in O(N) time and O(1) space?
*/

class Solution {
    
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s;
        for(char e : S) {
            if(e != '#') {
                s.push(e);
            } else if(!s.empty()){
                s.pop();
            }
        }
        
        stack<char> t;
       for(char e : T) {
            if(e != '#') {
                t.push(e);
            } else if(!t.empty()){
                t.pop();
            }
        }
        
        if(s.size() != t.size())
            return false;
        
        while(!s.empty()) {
            char tmp = s.top();
            s.pop();
            if(t.top() != tmp) {
                return false;   
            }
            t.pop();
        }
        return true;
        
    }
};