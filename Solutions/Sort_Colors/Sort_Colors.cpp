class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int f=0,r=n-1;
        for(int i=0;i<=r;i++){
            while(nums[i]==2 && i<=r){
                swap(nums[i],nums[r--]);
            }
            if(nums[i]==0){
                swap(nums[i],nums[f++]);
            }
        }
    }
};

/*
First thought:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        vector<int> res(nums.size(),0);
        
        for(int num: nums)
            count[num]++;
        
        for(int i=1; i < count.size(); i++)
            count[i] += count[i-1];
        
        for(int i=0; i<nums.size(); i++){
            res[count[nums[i]]-1] = nums[i];
            count[nums[i]]--;
        }
         
        for(int i=0; i<nums.size(); i++)
            nums[i] = res[i];
    }
};
*/

/*
Better and faster:

class Solution {
public:
    void sortColors(vector<int>& arr) {
    int n=arr.size();
    int j=n-1;
	int start=0;
	int end=n-1;
	while(start<=end){
		if(arr[end]==2){
			int t=arr[end];
			arr[end]=arr[j];
			arr[j]=t;
			end--;
			j--;
		}
		else if(arr[end]==0){
			int t=arr[end];
			arr[end]=arr[start];
			arr[start]=t;
			start++;
		}
		else{
			end--;
		}
	}
    }                               
};