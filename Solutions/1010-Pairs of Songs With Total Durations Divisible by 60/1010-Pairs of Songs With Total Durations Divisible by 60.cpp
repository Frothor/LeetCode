//https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/964948/C%2B%2B-Two-sum-with-remnant-flavor
class Solution { //two-sum
public: // Time/Space: O(N); O(1)
    int numPairsDivisibleBy60(vector<int>& time, int res = 0) {
        vector<int> m(60);
        for (auto t : time) {
            res += m[(60 - t % 60) % 60]; // current remnant: t%60; the desired partner:  60 -  t%60
            ++m[t % 60];
        }
        return res;
    }
};

//Third fastest
class Solution {
public:
    
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>rem(61,0);
        int cnt=0;
        for(int &t:time){
            int curr_rem=t%60;
            cnt+=0-curr_rem>=0?rem[0-curr_rem]:0;
            cnt+=60-curr_rem>=0?rem[60-curr_rem]:0;
            rem[curr_rem]++;
        }
        return cnt;
    }
};

//int numPairsDivisibleBy60(vector<int>& time) {
//     //Notice that 1<=time[i]<=500. now the max pair sum can be 1000. Now since the pair sum needs to be divisible by 60, there are only a few nos <=1000 that are divisible by 60. So for each time[i], check how many corres partners do we have such that we can attain a one the target sums(something from array options)  
//     unordered_map<int,int>Map;//Can't use unordered_set since we need the freq of occurence as well.
//     vector<int>options({60,120,180,240,300,360,420,480,540,600,660,720,780,840,900,960});//since the pair sum can from 2 to 1000
//     int cnt=0;
//     int n=time.size();
//     for(int &t:time){
//         for(int &opt:options){
//             if(Map.find(opt-t)!=Map.end())
//                 cnt+=Map[opt-t];
//         }
//         Map[t]++;;
//     }
//     return cnt;
// }

//Second fastest
class Solution {
public:
    /*int numPairsDivisibleBy60(vector<int>& time) 
    {
        //20,30,40,100,150
       // std::sort(begin(time), end(time)); // we dont need it
        unordered_map<int,int> countMap;
        int ans =0;
        for(auto t:time)
        {
            int remainder = t%60;
            int nbrNeeded = 0;
            if(remainder != 0)
                nbrNeeded = 60-remainder;                
            if(countMap.count(nbrNeeded))
            {
                ans += countMap[nbrNeeded];
            }
            countMap[remainder]++;
        }
        return ans;
    }
    */
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        //20,30,40,100,150
       // std::sort(begin(time), end(time)); // we dont need it
        int remainderArray[60]{};
        int ans =0;
        for(auto t:time)
        {
            int remainder = t%60;
            int nbrNeeded = 0;
            if(remainder != 0)
                nbrNeeded = 60-remainder;                
            ans += remainderArray[nbrNeeded];
            remainderArray[remainder]++;
        }
        return ans;
    }
};

//Fastest
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> s(60, 0);
        for(int i = 0; i < time.size(); i++)
        {
            int w = time[i] % 60;
            if(w == 0) count += s[w];
            else count += s[60 - w];
            s[w]++;
        }
        return count;
    }
};