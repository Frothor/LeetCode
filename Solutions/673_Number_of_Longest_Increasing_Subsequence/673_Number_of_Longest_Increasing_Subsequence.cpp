class Solution {
public:
int findNumberOfLIS(vector<int>& nums) {

  int n = nums.size();
  vector <int> len(n, 1), cnt(n, 1);
  int lis = 1;
  for(int i = 1; i < n; i++){
     for(int j = 0; j < i; j++){
        if(nums[i] > nums[j]){
           if(len[j] + 1 > len[i]){
              len[i] = len[j] + 1;
              cnt[i] = cnt[j];
           }
           else if(len[j] + 1 == len[i]){
              cnt[i] += cnt[j];
           }
        }
        lis = max(lis, len[i]);
     }
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
     if(len[i] == lis)ans += cnt[i];
  }
  return ans;
    
}
};

//Third fastest
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        vector<vector<pair<int, int>>> dyn(nums.size() + 1);
        int max_so_far = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // bsearch insertion point
            int l = 0, r = max_so_far;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (dyn[mid].back().first < nums[i]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            
            // bsearch number of options
            int options = 1;
            int row = l - 1;
            if (row >= 0) {
                int l1 = 0, r1 = dyn[row].size();
                while (l1 < r1) {
                    int mid = l1 + (r1 - l1) / 2;
                    if (dyn[row][mid].first < nums[i]) {
                        r1 = mid;
                    } else {
                        l1 = mid + 1;
                    }
                }
                
                options = dyn[row].back().second;
                options -= (l1 == 0) ? 0 : dyn[row][l1 - 1].second;
            }
            
            
            dyn[l].push_back({nums[i], (dyn[l].empty() ? options : dyn[l].back().second + options)});
            if (l == max_so_far) {
                max_so_far++;
            }
        }
        
        return dyn[max_so_far-1].back().second;
        
    }
};

//Second fastest
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        vector<vector<pair<int, int>>> dyn(nums.size() + 1);
        int maxsofar = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int l = 0, r = maxsofar;
            while(l < r)
            {
                int mid = l + (r - l) / 2;
                if(dyn[mid].back().first < nums[i])
                    l = mid + 1;
                else
                    r = mid;
            }
            int options = 1;
            int row = l - 1;
            if(row >= 0)
            {
                int l1 = 0, r1 = dyn[row].size();
                while(l1 < r1)
                {
                    int mid = l1 + (r1 - l1) / 2;
                    if(dyn[row][mid].first < nums[i])
                        r1 = mid;
                    else
                        l1 = mid + 1;
                }
                options = dyn[row].back().second;
                options -= (l1 == 0) ? 0 : dyn[row][l1 - 1].second;
            }
            dyn[l].push_back({nums[i], (dyn[l].empty() ? options : dyn[l].back().second + options)});
            if(l == maxsofar)
                maxsofar++; 
        }
        
        return dyn[maxsofar - 1].back().second;
    }
};

//Fastest
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        vector<vector<pair<int, int>>> dyn(nums.size() + 1);
        int max_so_far = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // bsearch insertion point
            int l = 0, r = max_so_far;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (dyn[mid].back().first < nums[i]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            
            // bsearch number of options
            int options = 1;
            int row = l - 1;
            if (row >= 0) {
                int l1 = 0, r1 = dyn[row].size();
                while (l1 < r1) {
                    int mid = l1 + (r1 - l1) / 2;
                    if (dyn[row][mid].first < nums[i]) {
                        r1 = mid;
                    } else {
                        l1 = mid + 1;
                    }
                }
                
                options = dyn[row].back().second;
                options -= (l1 == 0) ? 0 : dyn[row][l1 - 1].second;
                //cout << nums[i] << ' ' << options << ' ' << l1 << endl;
            }
            
            dyn[l].push_back({nums[i], (dyn[l].empty() ? options : dyn[l].back().second + options)});
            if (l == max_so_far) {
                max_so_far++;
            }
        }

        return dyn[max_so_far-1].back().second;
        
    }
};