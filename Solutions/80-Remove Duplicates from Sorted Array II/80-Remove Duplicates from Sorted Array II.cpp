//Third fastest
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        if(n == 0)
            return 0;
        int ind = 0; 
        int temp, c = 0;
        for(int i=0; i<n; i++)
        {
            if(c == 2)
            {
                if(a[i] == temp)
                    continue;
                else
                {
                    c = 1;
                    temp = a[i];
                    a[ind] = a[i];
                    ind++;
                }
            }
            else
            {
                a[ind] = a[i];
                ind++;
                if(c == 1 && a[i] == temp)
                    c++;
                else{
                    temp = a[i];
                    c = 1;
                }
            }
        }
        return ind;
        
    }
};

//Second fastest
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool flag = false;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                if(flag == true) {
                    nums.erase(nums.begin()+i);
                    i--;
                } else {
                    flag = true;
                }
            } else flag = false;
        }
        return nums.size();
    }
};

//Fastest
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0) return 0;
        
        int j = 0, c = 1;
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == nums[i+1]) {
                c++;
            } else {
                c = (c >= 2)? 2 : 1;
                while (c--) {
                    nums[j++] = nums[i];
                }
                c = 1;
            }
        }
        
        c = (c >= 2) ? 2 : 1;
        while (c--) {
            nums[j++] = nums[n-1];
        }
        
        return j;
    }
};