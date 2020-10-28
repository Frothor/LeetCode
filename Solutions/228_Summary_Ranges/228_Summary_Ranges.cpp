//Fastest
class Solution {
	
	public:
	
	vector<string> summaryRanges(vector<int>& nums) {
    
    vector<string> v;
    
    if(nums.size()==0)
    {
        return v;
    }
    
    int start=nums[0];
    int end=nums[0];
    
    
    for(int i=1;i<nums.size();i++)
    {
        if(end+1==nums[i])
        {
            end=nums[i];
        }
        else
        {
            if(start==end)
            {
                string x=to_string(start);
                v.push_back(x);
            }
            else
            {
                string x=to_string(start);
                x+="->";
                x+=to_string(end);
                v.push_back(x);
            }
            start=nums[i];
            end=nums[i];
        }
    }
    
    if(start==end)
    {
        string x=to_string(start);
        v.push_back(x);
    }
    else
    {
         string x=to_string(start);
         x+="->";
         x+=to_string(end);
         v.push_back(x);
    }
    
    return v;
}
};

//Another
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.empty())
        {
            return {};
        }

        vector<string> v;
        v.reserve(20);
        int beg = nums.front();
        int expect = nums.front();
        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == expect + 1)
            {
                ++expect;
            }
            else
            {
                if (beg == expect)
                {
                    v.push_back(to_string(beg));
                }
                else
                {
                    v.push_back(to_string(beg) + "->" + to_string(expect));
                }
                beg = nums[i];
                expect = nums[i];
            }
        }
        if (beg == expect)
        {
            v.push_back(to_string(beg));
        }
        else
        {
            v.push_back(to_string(beg) + "->" + to_string(expect));
        }
        return v;
    }
};