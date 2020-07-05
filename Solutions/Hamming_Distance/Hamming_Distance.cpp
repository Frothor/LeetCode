class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = x^y;
        int count = 0;
        while(result > 0){
            count += result & 1;
            result >>= 1;
        }
        return count;
    }
};

/*
another:
class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int distance=0;
        for(int i = 0; i < 32;++i)
        {
            int mask=1<<i;
            if((mask&x)^(mask&y)) distance++;
        }
        
        return distance;
    }
};
*/