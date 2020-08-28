class Solution {
public:
    int n, m;
    int rand10() {
        // initialising the values
		n = rand7(), m = 7;
        // making sure n is in the right 1-5 range and, if we can, we settle m too
		while (n > 5) {
            m = n - 5;
            n = rand7();
        }
        // if m was not settled, we do it here
		while (m == 7) m = rand7();
        return (m % 2 ? 5 : 0) + n;
    }
};

//Most common
class Solution {
public:
    int rand10() {
        int col, row, idx;
        do{
            col=rand7();
            row=rand7();
            idx=col+(row-1)*7;
        }while(idx<40);
        
        return (idx-40)+1;
            
    }
};

//Fastest
class Solution {
public:
    int rand10() {
        int x = 7;
        while (x >= 7) { x = rand7(); }

        int y = 6;
        while (y >= 6) { y = rand7(); }
        
        int ans = 0;
        if (x > 3) ans = 5;
        ans += y;
        return ans;
    }
};