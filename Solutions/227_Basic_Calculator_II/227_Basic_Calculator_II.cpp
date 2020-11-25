//Most common
class Solution {
public:
    int calculate(string s) {
        long num = 0;
        char op = '+';
        int n = s.size();
        stack<int> S;
        
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                num = 10 * num + s[i] - '0';
            }
            if ((s[i] < '0' && s[i] != ' ') || i == n-1) {
                if (op == '+') S.push(num);
                if (op == '-') S.push(-num);
                if (op == '*' || op == '/') {
                    int tmp = 0;
                    if (op == '*') tmp = S.top() * num;
                    if (op == '/') tmp = S.top() / num;
                    S.pop();
                    S.push(tmp);
                }
                num = 0;
                op = s[i];
            }
        }
        
        int res = 0;
        while (!S.empty()) {
            res += S.top();
            S.pop();
        }
        return res;
    }
};

//Third fastest
class Solution {
public:
    int calculate(string s) {
        int length = s.length();
        if (length == 0) return 0;
        int currentNumber = 0, lastNumber = 0, result = 0;
        char sign = '+';
        for (int i = 0; i < length; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1) {
                if (sign == '+' || sign == '-') {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                sign = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;  
    }
};

//Second fastest
class Solution {
public:
    int calculate(string s) {
        int n = s.size(); auto ch = s.c_str();
        int curr = 0, ans = 0, tail = 1; bool is_d = false;
        for(char ch:s){
            if(isdigit(ch)){
                curr *= 10;
                curr += ch-'0';
            } else if(ch=='+'){
                ans += is_d?(tail/curr):(tail*curr);
                curr = 0; tail = 1;is_d = false;
            } else if(ch=='-'){
                ans += is_d?(tail/curr):(tail*curr);
                curr = 0; tail = -1;is_d = false;
            } else if(ch=='*'){
                if(is_d) tail /= curr;
                else tail *= curr;
                curr = 0; is_d =false;
            } else if(ch=='/'){
                if(is_d) tail /= curr;
                else tail *= curr;
                curr = 0; is_d =true;
            }
        }
        ans += is_d?(tail/curr):(tail*curr);
        return ans;
    }
};

//Fastest
class Solution {
public:
    int calculate(string s) {
        int result=0, num=0, curnum=0;
        int op='+';
        for (int i=0; i<s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num*10 + (c-'0');
            }
            if (c=='+'||c=='-'||c=='*'||c=='/'||i==s.size()-1) {
                switch(op) {
                    case '+': curnum = num; break;
                    case '-': curnum = -num; break;
                    case '*': curnum *= num; break;
                    case '/': curnum /= num; break;
                }
                
                if (c=='+'||c=='-'||i==s.size()-1) {
                    result += curnum;
                }
                
                num=0;
                op = c;
            }
        }
        
        return result;
    }
};