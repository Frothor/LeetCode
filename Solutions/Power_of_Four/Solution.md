# LeetCode Power of Four Solution

## 1. Solution Bit Manipulation

The Idea Is :
As we need to Find **The No is Power Of 4 or Not**
We Can Solve It by doing Bit Manipulation
**[if Any No is valid Power_Of_4 then It should Be valid Power_Of_2 as well]** <= **Use This Property**

Let's Suppose if They Are Asking For Finding is The No_is_Power_Of 2 or Not Then What shuld We do :::
We Just Trying To Find Is That No Have **only One Set Bit Or Not**
If there is only One Set Bit exist Then We Can blindly Say That It's A valid Power Of 2
So,The **Same Idea** We Need here also But need check One More Condition

What Is The 2nd Condition Would Be, Let's Find Out By analysing Few Example

**1 2 4 8 16 32 64 128 256 592 1084 ......** -> This All Are Power Of Two [ Mean Having Only One Set Bit ]
**1 4 16 64 256 1084......**-> This All Are Power Of Four , Now We can Greedly Observe
That **Between two power_of_4 there Was One Invaild Power_Of_4 Exist**
So we need To chech that Condition Too

So Conditions Are :

1. No of **Set** Bit **Always** Be **Only** ONE 
2. That SetBit Possition Should Be **always In** odd Place [ **starting from Left** ] 
Let's See Example :
```
     No            Bit_re             SetBitPos       No_of_setBit          Valid_power_of_four
     64         1 0 0 0 0 0 0           7                  1                        True         <= :)
     128        1 0 0 0 0 0 0 0         8                  1                        False        <=2nd Condition fail :(
     18         1 0 0 1 0               5,2                2                        False        <=1st Condition Fail :( 
     32         1 0 0 0 0 0             6                  1                        False        <=2nd Condition fail :(
```
```
Time Complexcity O ( 1 )    =>as we Only Traverse max 32 Bit 
Space Complexcity O ( 1)   => No Extra Space
```
```c++
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<0)return false;
        int no_of_one = 0,pos = 1,ones_pos = 0;
        while(num){
            if(num&1)no_of_one+=1,one_pos = pos;
            num>>=1,pos+=1;
        }
        return no_of_one==1&&one_pos&1;
    }
};
```

## 2. Smart Work
```c++
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<0)return false;
        for(int i=0;i<32;i+=2)if(num==1<<i)return true;
        return false;
    }
};
```

Or Can Do Like Fallowing One
```c++
class Solution {
public:
    bool isPowerOfFour(int num) {
        vector<int>Cup = {1,4,16,64,256,1024,4096,16384,65536,262144,1048576,4194304,16777216,67108864,268435456,1073741824};
        for(int no:Cup)if(num==no)return true;
        return false;
    }
};
```

## 3.Bruteforce Solution
```c++
class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num > 1) {
            if(num % 4)return false;
            num /= 4;
        }
        return num == 1;
    }
};
```

## 4. One Liner
```c++
return num>0&&!(num&(num-1))&&!((num-1)%3);
```

[Link to original post](https://leetcode.com/problems/power-of-four/discuss/772428/C%2B%2B-Four-Solution-or-Explain-or-Naive-or-One-Liner-orBit-Manipulation)