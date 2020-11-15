//Fastest
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // min_pig_count determined by equation: buckets =max_sub_job_load ** min_pig_count
		// max_sub_job_load  = minutesToTest / minutesToDie + 1
        // min_pig_count = ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};

//Another
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T=minutesToTest/minutesToDie;
        int i=0;
        while(pow(T+1,i)<buckets){
            i++;
        }
        return i;
    }
};