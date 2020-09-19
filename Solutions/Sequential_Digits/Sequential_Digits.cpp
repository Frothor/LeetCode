class Solution {
public:
    
    
    //Gives the digts for the number.
    int digits(int n)
    {
        int d = 0;
        while(n)
        {
            n /=10;
            d++;
        }
        return d;
    }
    
    
    void recur(vector<int>& result, int& low, int& high, int current, int currentDigit, int& startOfSequence, int digitCount)
    {
        //Number is higher 
        if(current > high)
            return;
        
        int currentDigitCount = digits(current);
        //Is current digit count in range?  and current digit count is the required digit count. 
        if((currentDigitCount >= digits(low) && currentDigitCount <= digits(high)) && currentDigitCount == digitCount)
        {
            //Number is in Range
            if(current >= low)
                result.push_back(current);
            
            
            //Reached the End.
            if(startOfSequence == 9)
                return;
            
            //start then next sequence ( e.g. if current sequence started with 1 ( 12 ), next will start 2 (23..)
            startOfSequence++;
            recur(result, low, high, 0, startOfSequence, startOfSequence, digitCount);
            return;
        }
        
        //Reached the max sequence, next number not possible.
        if(currentDigit > 9)
            return;
        
        //Update the current with the digit.
        current *= 10;
        current += currentDigit;
        
        //Recur for the next number
        recur(result, low, high, current, currentDigit+1, startOfSequence, digitCount);
    }
    
    
    
    vector<int> sequentialDigits(int low, int high) {
    
        vector<int> result;
        //Iterate for digits from low number of digits to high number of digits. 
        for(int digitCount = digits(low); digitCount <= digits(high); digitCount++)
        {
            //Start the sequence for the digit count.
            int startDigit = 1;
            recur(result, low, high, 0, startDigit, startDigit, digitCount);
        }
        
        return result;
    }
};

//backtracking
class Solution {
public:
    void backtrack(vector<int> &v, int low, int high, int num) {
        if (num == 9) return;
        if (num % 10 < 9) {
            num = num * 10 + (num % 10) + 1;
            if (num >= low && num <= high)
                v.push_back(num);
            
            backtrack(v, low, high, num);
        }
        else  { // if the last digit is 9 for example 1234569, then we can proceed to 23456789
            int exp = log10(num), highestDigit = num / pow(10, exp); // if num = 23456 we want the highestDigit i.e 2 
            backtrack(v, low, high, highestDigit + 1);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        backtrack(v, low, high, 1);
        sort(begin(v), end(v));
        return v;
    }
};

//Another fast but more concise
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        
        int lenMin = std::to_string(low).size();
        int lenMax = std::to_string(high).size();
        
        for (int l = lenMin; l <= lenMax; ++l) {
            for (int i = 1; i <= 9; ++i) {
                int num = 0;
                for (int j = i; j < i + l && j < 10; ++j) {
                    num = num * 10 + j;
                    if (j == i + l - 1 && num >= low && num <= high) {
                        res.push_back(num);
                    }
                }
            }
        }
        
        return res;
    }
};