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


//Most commmon
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

//Second Fastest
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

//Fastest
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         if (nums.size() < 3) return ans;
        
//         sort(nums.begin(), nums.end());
//         int start, end, sum = 0;
        
//         for (int i = 0; i != nums.size(); ++i)
//         {   
//             if (i+1 < nums.size() && nums[i] != nums[i+1] && nums[i] >= 0) break;
//             start = i + 1;
//             end = nums.size()-1;
            
//             while (start < end)
//             {
//                 sum = nums[i] + nums[start] + nums[end];
//                 if (sum == 0) 
//                 {
//                     vector<int> temp{nums[i], nums[start], nums[end]};
//                     ans.push_back(temp);
//                     while (start < end && nums[start] == temp[1]) ++start;
//                     while (start < end && nums[end] == temp[2]) --end;
//                 }
                
//                 else if (sum < 0)
//                     ++start;
//                 else 
//                     --end;
//             }
            
//             while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
//                  i++;
//         }
        
//         return ans;
        if (nums.size() < 3) return {};
		vector<vector<int>> res;

		int maxNum = 0, minNum = 0;
		for (int x : nums) {
			maxNum = max(maxNum, x);
			minNum = min(minNum, x);
		}

		const int tb_size = maxNum - minNum + 1;
		vector<int> rec(tb_size, 0);
		for (int x : nums) {
			if (++rec[x - minNum] > 3) {
				rec[x - minNum] = 3;
			}
		}
		if (rec[-minNum] == 2) rec[-minNum] = 1;

		vector<int> v;
		for (int i = 0; i < tb_size; i++) {
			if (rec[i] > 0) v.push_back(i + minNum);
		}
		const int vsz = v.size();
		for (int i = 0; i < vsz; i++) {
			const int vMin = v[i];
			if (vMin > 0) break;
			for (int j = i; j < vsz; j++) {
				const int vMid = v[j];
				const int target = -vMin - vMid;
				if (target < vMid) break;
				if (target > maxNum || (target - minNum < tb_size && rec[target - minNum] == 0)) continue;
				if (vMin < vMid && vMid < target || (vMid - minNum < tb_size && rec[vMid - minNum] > 1))                                    res.push_back({ vMin,vMid,target });
			}
		}
		return res;
    }
};