class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;
        
        int sum = 0;
        
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        
        if(sum % 9 == 0)
            return 9;
        else
            return sum % 9;
    }
};


/*
Another:
class Solution {
public:
    int addDigits(int num) {
        if(num/10==0) return num;
        int res=0;
        while(num){
            res+=num%10;
            num=num/10;
        }
        return addDigits(res);
    }
};
*/