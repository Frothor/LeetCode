class Solution {
public:
void rotate(vector<int>& nums, int k) {
	k = k % nums.size();
	vector<int> temp(k);
	
	int j = 0;
	// Store the last k elements in the temporary array
	for (int i=nums.size()-k; i<nums.size(); i++) {
		temp[j++] = nums[i];
	}

	j = nums.size() - 1;
	// Right shift all the elements by k steps
	for (int i=nums.size()-k-1; i>=0; i--) {
		nums[j--] = nums[i];
	}
	
	// Populate the first k elements with the temporary array elements
	for (int i=0; i<k; i++) {
		nums[i] = temp[i];
	}
}
};

//Second fastest
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       
        int n=nums.size(),j=0;
         k=k%n;
        vector<int>r;
        for(int i=n-k;i<n;i++)
        {
            r.push_back(nums[i]);
            
        }
          for(int i=0;i<n-k;i++)
        {
            r.push_back(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=r[i];
        }
    
    }
};

//Fastest
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int count = 0;
        for (int start = 0; count < nums.size(); start++) {
          int current = start;
          int prev = nums[start];
          do {
            int next = (current + k) % nums.size();
            int temp = nums[next];
            nums[next] = prev;
            prev = temp;
            current = next;
            count++;
          } while (start != current);
        }
    }
};