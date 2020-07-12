//Simple solution
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0; 
      
        for (int i =0; i < 32; i++) 
        { 
        
            res <<= 1; 
            if (n & 1) 
                res++; 
            n >>= 1; 
        } 
      
        return res; 
    }
};

/*
Fastest:
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // start packing from left to right
        uint32_t result = 0x0;
        uint32_t mask = 0x0001;
        
        int number = n;
        int i =31;
        while(i >= 0){
            result |= (mask & number) << i;
            number = number >> 1;
            i--;
        }
        
        return   result;
        
    }
};

*/