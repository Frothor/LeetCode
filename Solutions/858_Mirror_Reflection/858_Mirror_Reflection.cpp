class Solution {
public:
    int mirrorReflection(int p, int q) {
        int m = 1; // extension count of room
        int n = 1; // reflection count of laser ray
        while(m * p != n * q){
            n++;
            m = n * q / p;
        }
        if (m % 2 == 0 && n % 2 == 1) return 0;
        if (m % 2 == 1 && n % 2 == 1) return 1;
        if (m % 2 == 1 && n % 2 == 0) return 2;
        return -1;
    }
};

class Solution {
public:
    
int mirrorReflection(int p, int q)
{
    int n, m, np, mq;
    
    n = m = 1;
    while (1) {
        np = n * p;
        mq = m * q;
        if (np == mq)
            break;
        else if (np > mq)
            m++;
        else
            n++;
    }
    
    if (m & 1) {
        // 1 ? 0
        if (n & 1) {
            return 1;
        } else {
            return 0;
        }        
    } else {
        return 2;
    }
}
};

class Solution {
 public:
  int mirrorReflection(int p, int q) {
    int m = 1;  // # of room extension + 1
    int n = 1;  // # of reflection + 1

    while (m * p != n * q)
      m = ++n * q / p;

    if (n % 2 == 0) return 2;
    if (m % 2 == 0) return 0;
    if (m % 2 == 1) return 1;
    throw;
  }
};