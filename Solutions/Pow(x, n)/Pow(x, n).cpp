class Solution {
    double powUtil(double x, long n){
        if(n == 0) return 1.0;
        if(n == 1) return x;
        if(n < 0)
            return powUtil(1/x, -n);
        
        double result = powUtil(x*x, n/2);
        if(n%2) result *= x;
        return result;
    }
public:
    double myPow(double x, int n) {
       return powUtil(x, n);
    }
};

/*
Fastest:
#include <math.h>
#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
        
    }
};

*/