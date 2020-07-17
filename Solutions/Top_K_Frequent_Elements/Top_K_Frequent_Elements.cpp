class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> occur;
        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for(auto &val: nums)
            occur[val]++;
        
        for(auto &eachFreq: occur){
            if(minHeap.size() < k){
                minHeap.push({eachFreq.second, eachFreq.first});
            } else {
                int numOccur = minHeap.top().first;
                
                if(eachFreq.second > numOccur){
                    minHeap.pop();
                    minHeap.push({eachFreq.second, eachFreq.first});
                }
            }   
        }
        
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
};

/*
Most common:
class Solution {
public:
    struct comp
    {
        bool operator() (const pair<int, int> struct1, const pair<int, int> struct2)
        {
            return (struct1.second > struct2.second);
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            um1[nums[i]]++;
        }
        vector<pair<int, int> > v;
        for(auto it : um1){
            v.push_back({it.first, it.second});
        }
        sort(v.begin(), v.end(), comp());
        vector<int> ans;
        n = v.size();
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};

Fastest:
class Solution {
public:
    static bool comp(pair<int,int> &a, pair<int,int> &b)
    {
        return a.second > b.second;
            
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
//         vector<pair<int,int>> table(1000, make_pair(0,0));
        
//         vector<int> ans;
//         for(int i=0; i<nums.size(); i++)
//         {
//             // pair<int,int> p;
//             // p=make_pair(i,table[nums[i]].second+1);
//             table[nums[i]]=p;
//         }
        
//         std::sort(table.begin(), table.end(),comp);
//         cout<<table[1].first<<"  "<<table[1].second;
//         return ans;
        
        unordered_map<int, int> table;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            table[nums[i]]++;
        }
        
        vector<pair<int, int>> temp;
        for(auto i: table)
        {
            pair<int, int> p;
            p = make_pair(i.first, i.second);
            temp.push_back(p);
        }
        
        std::sort(temp.begin(), temp.end(), comp);
        for(int i=0; i<k; i++)
        {
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

Second fastest:
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    class ElementCount
    {
    public:
        ElementCount(int element, int count) : element_(element), count_(count)
        {
        }
        
        bool operator<(const ElementCount& other) const { return count_ > other.count_; }
        
        int element_;
        int count_;
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        if (k == nums.size())
        {
            return nums;
        }
        
        unordered_map<int,int> counts;
        
        for (int num : nums)
        {
            ++counts[num];
        }
        
        vector<ElementCount> topK;
        topK.reserve(counts.size());
        for (auto iter = counts.begin(); iter != counts.end(); ++iter)
        {
            topK.emplace_back(iter->first, iter->second);
        }
        nth_element(topK.begin(), topK.begin()+k, topK.end());
        
        vector<int> ret;
        ret.reserve(k);
        
        for (int i = 0; i < k; ++i)
        {
            ret.push_back(topK[i].element_);
        }
        
        return ret;
    }
};

*/