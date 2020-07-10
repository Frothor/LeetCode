class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while (j < k && nums[j] == nums[j-1]) ++j;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        return result;
    }
};

/*
Most commmon:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int l=i+1; int r=n-1;
            int tar=-nums[i];
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum<tar){
                    l++;
                }
                else if(sum>tar){
                    r--;
                }
                else{
                    vector<int>trip(3);
                    trip[0]=nums[i];
                    trip[1]=nums[l];
                    trip[2]=nums[r];
                    ans.push_back(trip);
                    while(l<r && nums[l]==trip[1]){
                        l++;
                    }
                    while(r>l && nums[r]==trip[2]){
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};

Fastets:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;

        int minVal = nums[0], maxVal = nums[0];
        for (int num:nums) {
            if (num > maxVal) maxVal = num;
            if (num < minVal) minVal = num;
        }
//        vector<int> bucket(maxVal - minVal + 1);
        int *bucket = new int[maxVal - minVal + 1]{0};
        
        for (int num:nums) ++bucket[num - minVal];
        if (minVal <= 0 && maxVal >= 0 && bucket[-minVal] == 2) bucket[-minVal] = 1;

        vector<int> list;
        for (int i = 0; i < maxVal - minVal + 1; ++i) if (bucket[i]) list.push_back(i + minVal);
        for (int i = 0; i < list.size(); ++i) {
            int a = list[i];
            for (int j = i + (bucket[a - minVal] <= 1); j < list.size(); ++j) {
                int b = list[j], c = -(a + b);
                if (c < b) break;
                if (c <= maxVal && bucket[c - minVal] > (b == c))
                    ans.push_back({a, b, c});
            }
        }
        delete[] bucket;
        return ans;
    }
};

*/