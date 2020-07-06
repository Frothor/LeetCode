class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size()-1;
        while(idx >= 0){
            if(digits[idx] == 9)
                digits[idx] = 0;
            else {
                digits[idx] += 1;
                return digits;
            }
            idx--;
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

/*
Fastest:
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, sum = 0;
        int size = digits.size();
        vector<int> ans(digits);
        if (digits[size - 1] != 9) {
            ans[size - 1] += 1;
            return ans;
        }
        for (int i = size - 1; i >= 0; i--) {
            sum = carry + digits[i];
            carry = sum / 10;
            ans[i] = sum % 10;
        }
        if (ans[0] == 0) {
            ans.push_back(0);
            ans[0] = 1;
        }
        return ans;
    }
};

Most common:
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for (int i = size - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
                if (i == 0) {
                    digits.insert(digits.begin(), 1);
                    break;
                }
            } else {
                digits[i] += 1;
                break;
            }
        }
        return digits;
    }
};
*/