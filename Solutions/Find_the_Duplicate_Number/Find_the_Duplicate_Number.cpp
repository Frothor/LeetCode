class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0], hare = nums[0];
        while(true){
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            if(tortoise == hare)
                break;
        }
        
        int ptr1 = nums[0];
        int ptr2 = tortoise;
        while(ptr1 != ptr2){
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }
};

/*
Fastest:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=i+1 && nums[nums[i]-1]!=nums[i])
                swap(nums[i],nums[nums[i]-1]);
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)
                return nums[i];
            
        }
        
        return 0;
    }
};

Another:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       if (nums.size() > 1)
	{
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1; 
    }
};
*/