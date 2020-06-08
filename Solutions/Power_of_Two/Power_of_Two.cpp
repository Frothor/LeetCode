class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0)  
            return 0;  
        while (n != 1)  
        {  
            if (n%2 != 0)  
                return 0;  
            n = n/2;  
        }  
        return 1;  
    }
};

/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        int setbits=0;
        while(n){
            setbits++;
            n = n & (n-1);
        }
        return setbits==1;
    }
};
*/