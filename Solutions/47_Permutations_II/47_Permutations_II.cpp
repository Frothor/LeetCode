class Solution {
	int n;
	vector<vector<int>> res;
	vector<int> cur;
	vector<int> temp;
	vector<int> visited;

public:
	void dfs(int index){
		if(index==n){
			res.push_back(cur);
		}
		for(int i=0;i<n;i++){
			if(visited[i]) continue;
			if(i>0 && temp[i]==temp[i-1] && !visited[i-1]) continue;
			visited[i]=1;
			cur[index]=temp[i];
			dfs(index+1);
			visited[i]=0;
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		n=nums.size();
		cur.assign(n,0);
		temp=nums;
		sort(temp.begin(),temp.end());
		visited.assign(n,0);
		dfs(0);
		return res;

	}
};

//Second fastest
class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};

//Fastest
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        findPU(nums, 0, result);
        return result;
    }
    
    
    void findPU(vector<int>& nums, int start, vector<vector<int>>& result){
        if(start == nums.size()){
            result.push_back(nums);
            return;
        }    
        
        int len = nums.size();
        for(int i=start; i<len; i++){
            int j = i - 1;
            while (j >= start && nums[j] != nums[i]) --j;
            if (j != start - 1) continue;
            
            swap(nums[start], nums[i]);
            findPU(nums, start+1, result);
            swap(nums[start], nums[i]);
        }
        
        return;
    }
};