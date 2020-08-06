//Basic solution
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && ((num & (num-1)) == 0) && (num%3 == 1);
    }
};

//Fastest:
class Solution {
public:
    // power of four = power of two, with the set bit appearing at an odd position
    bool isPowerOfFour(int num) {
        return num > 0 and (num & (num - 1)) == 0 and (num & 0x55555555);
    }
};