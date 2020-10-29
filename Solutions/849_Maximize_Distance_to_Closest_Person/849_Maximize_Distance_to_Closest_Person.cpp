//Third fastest
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // support variables
        int len = seats.size(), i = 0, j, res = 0;
        bool isNotTerminal;
        while (i < len) {
            // positioning i on the next 0 or end of the vector
            while (i < len && seats[i]) i++;
            j = i + 1;
            // positioning i on the next 1 or end of the vector
            while (j < len && !seats[j]) j++;
            // checking if it is a terminal series of empty spots and updating res accordingly
            isNotTerminal = i && j != len;
            res = max(res, (j - i + isNotTerminal) / (1 + isNotTerminal));
            i = j;
        }
        return res;
    }
};

//Another
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int lclose = -seats.size();;
        int rclose = 0;
        int mxv = 0;
        for(int i=0;i<seats.size();i++){
            if(seats[i])    lclose = i;
            else{
                if(rclose <= i){
                    for(int j=i+1;j<seats.size();j++){
                        if(seats[j]){
                            rclose = j;
                            break;
                        }
                    }
                    if(rclose <= i) rclose = INT_MAX;
                }
                mxv = max(mxv, min(i-lclose, rclose-i));
                
            }
        }
        return mxv;
    }
};

//Second fastest
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int left[n], right[n];
        left[0] = (seats[0])?0:INT_MAX;
        right[n-1] = (seats[n-1])?0:INT_MAX;
        for(int i=1; i<n; i++)
        {
            if(seats[i]) left[i] = 0;
            else
            {
                if(left[i-1] == INT_MAX) left[i] = 2;
                else left[i] = left[i-1] + 1;
            }
            if(seats[n-1-i]) right[n-1-i] = 0;
            else
            {
               if(right[n-1-i+1] == INT_MAX) right[n-1-i] = 2;
                else right[n-1-i] = right[n-1-i+1]+1;
            }
        }
        int max_ = 0;
        for(int i=0; i<n; i++)
        {
            max_ = max(max_, min(right[i], left[i]));
        }
        return max_;
    }
};

//Fastest
// The following block might slightly improve the execution time;
// Can be removed;
static const auto __optimize__ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

// Most of headers are already included;
// Can be removed;
#include <cstdint>
#include <vector>
#include <algorithm>


static const struct Solution {
    using ValueType = std::int_fast16_t;
    static const int maxDistToClosest(
        std::vector<int> seats
    ) {
        const ValueType len = std::size(seats);
        ValueType max_distance = 0;
        ValueType distance = -1;

        for (ValueType index = 0; index < len; ++index) {
            if (seats[index] == 1) {
                max_distance = distance < 0 ? index : std::max(max_distance, (index - distance) / 2);
                distance = index;
            }
        }

        max_distance = std::max(max_distance, len - distance - 1);

        return max_distance;
    }

};