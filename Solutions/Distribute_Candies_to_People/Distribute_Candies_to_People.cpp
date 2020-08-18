//Most common and fastest
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans = vector<int>(num_people, 0);
        
        int ctr = 1;
        int person = 0;
        while(candies > 0){
            if(candies - ctr < 0){
                ans[person] += candies;
            } else {
                ans[person] += ctr; 
            }                      
            candies -= ctr++;
            person = (person + 1) % num_people;
        }
        return ans;
    }
};