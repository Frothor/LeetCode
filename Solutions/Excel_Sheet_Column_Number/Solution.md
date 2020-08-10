# LeetCode Excel Sheet Column Number Solution
## Explanation 1
### Idea : -
This Problem Nothing But to Convert Base 26 to Decimal number [Base 10]
So We can Traverse From Right To left Into The String And Convert Into Decimal Form And Sum Up all

Lets See One Example :
```
	Input - "ACBD"
	A            C         B          D
  1*26^3   +  3*26^2  +  2*26^1  +  4*26^0    =   19660
       ^           ^          ^          ^
       |           |          |          |   
       3 <--       2  <--     1<--       0 <-start 
	   
as A=1, B=2 , C=3 ...... Z = 26 Puting Here [ Given ] 
Time Complexcity - O ( Length Of The String )
Space Complexcity - O( 1 )
```

```c++
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0,n = s.length()-1;
        for(int i = n;i>=0;i--)
            ans+=pow(26,n-i)*(s[i]-'A'+1);      
        return ans;
    }
};
```

To avoid Pow Function Use This
```c++
class Solution {
public:
    int titleToNumber(string s) {
        int no = 0;
        for(char c:s)
            no = no * 26 + (c-'A'+1);
        return no;
    }
```

[Link to original post](https://leetcode.com/problems/excel-sheet-column-number/discuss/783369/C-%2B%2B-Easy-Code-oror-Simple-Approch)

## Explanation 2

So, this was a fun one, since the problem was a simple lexicographic one and all we had to think was how to count using **A - Z** instead of **0 - 9**.

To do so, I found more convenient to start from the leftmost "digit" and proceed to the right, storing my result in the **res** variable and, one step at a time, multiplying the previous value of **res** by **26** (that is our base) and adding the value of the current character to it.

To turn a **A - Z** range into a **1 - 26** one, just need to subtract **@**, the first character before A in [the standard ASCII implementation](https://en.wikipedia.org/wiki/ASCII#Printable_characters).

In my recursive calls I am then passing:

* the base string s as a reference;
* the aforementioned accumulator **res**;
* **pos**, initialised to **0**

When I reach the point in which **pos == s.size()**, it means I am done parsing the string, so I returrn **res** :)

Note that you might as well start from the leftmost "digit", but in that case you would have to proceed right multiplying by the matching power of **26**: a needless annoyance, if you ask me.

The code:
```c++
class Solution {
public:
    int titleToNumber(string &s, long res = 0, int pos = -1) {
        return (pos = pos == -1 ? 0 : pos, pos) == s.size() ? res : titleToNumber(s, res * 26 + s[pos] - '@', pos + 1);
    }
};
```

The iterative approach, with exactly the same logic, might be easier to grasp (and less elegant, at least to my eyes, but I concede that is subjective):
```c++
class Solution {
public:
    int titleToNumber(string s) {
        long res = 0;
        int pos = 0;
        while (pos < s.size()) {
            res = res * 26 + s[pos] - '@';
            pos++;
        }
        return res;
    }
};
```

[Link to original post](https://leetcode.com/problems/excel-sheet-column-number/discuss/783498/C%2B%2B-Oneliner-Recursive-Vs.-Iterative-Solutions-Explained-100-Time-~70-Space)