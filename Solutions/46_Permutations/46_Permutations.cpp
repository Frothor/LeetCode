//Third fastest
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>  result;
        permute(nums,0,result);
        return result;
    }
    
    private:
     void permute(vector<int> nums, int i, vector<vector<int>>& result){
         
         if(i == nums.size()){
             result.push_back(nums);
     }
         else{
             for(int j=i;j<nums.size();j++){
                 swap(nums[i],nums[j]);
                 permute(nums,i+1,result);
             }
         }
         
         
     }
};

//Second fastest and most common
class Solution {
    vector<vector<int>>res;
    void rec(int pos, vector<int>&tmp){
        if(pos == (int)tmp.size()){
            res.emplace_back(tmp);
            return;
        }
        
        for(int i = pos; i < tmp.size(); i++){
            swap(tmp[i], tmp[pos]);
            rec(pos+1, tmp);
            swap(tmp[i], tmp[pos]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        res.clear();
        rec(0, nums);
        return res;
        /*
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do{
            res.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return res;
        */
    }
};

//Fastest
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<int> visited(nums.size());
        permutation(nums, ans, cur, visited, 0);
        return ans;
    }
private:
    void permutation(vector<int>& nums, vector<vector<int>> &ans, vector<int> &cur, vector<int> &visited, int s){
        if(s == nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == 1){
                continue;
            }
            visited[i] = 1;
            cur.push_back(nums[i]);
            permutation(nums, ans, cur, visited, s+1);
            cur.pop_back();
            visited[i] = 0;
        }
    }
    
};