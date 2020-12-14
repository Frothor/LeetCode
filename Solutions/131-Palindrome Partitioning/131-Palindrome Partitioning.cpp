//Fourth fastest
class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<int>> p(n,vector<int>(n,0));
        for(int i=0;i<n-1;i++)
        {    p[i][i]=1;
             if(s[i]==s[i+1])
                 p[i][i+1]=1;
        } p[n-1][n-1]=1;
        for(int len=3;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                int j=i+len-1;
                if(s[i]==s[j])
                    if(p[i+1][j-1])
                        p[i][j]=1;
            }
        }
        vector<string> v;
        dfs(0,v,s,p);
        return ans;
        
    }
    void dfs(int i,vector<string> &v,string s,vector<vector<int>> &p)
    {
        if(i==s.length())
        {
            ans.push_back(v);
            return;
        }
        for(int j=i;j<s.length();j++)
        {
            if(p[i][j])
            {
                v.push_back(s.substr(i,j-i+1));
                dfs(j+1,v,s,p);
                v.pop_back();
            }
        }
    }
};

//Third fastest
class Solution 
{
private:
    bool isPalindrome(const std::string& s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        std::vector<std::vector<std::string>> partitions;
        std::vector<std::string> partition;
        this->accumulatePartitions(s, 0, partition, partitions);
        return partitions;
    }
    
    void accumulatePartitions(const std::string& s, int step,
                              std::vector<std::string>& partition, std::vector<std::vector<std::string>>& partitions)
    {
        if (step == s.size())
        {
            partitions.push_back(partition);
            return;
        }
        
        int left = step;
        for (int right = left; right < s.size(); right++)
        {
            if (this->isPalindrome(s, left, right))
            {
                partition.push_back(s.substr(left, right - left + 1));
                this->accumulatePartitions(s, right + 1, partition, partitions);
                partition.pop_back();
            }
        }
        
    }
};

//Second fastest
class Solution {
	vector<vector<string>> ans;
public:
	bool symmetric(string& curr) {
		int l = 0;
		int r = curr.size() - 1;
		while (l < r) {
			if (curr[l++] != curr[r--]) return false;
		}
		return true;
	}

	void helper(string& s, vector<string>& layer, int index) {
		if (index == s.size()) {
			ans.push_back(layer);
			return;
		}

		string curr;
		for (int i = index; i < s.size(); ++i) {
			curr += s[i];
			if (symmetric(curr)) {
				layer.push_back(curr);
				helper(s, layer, i + 1);
				layer.pop_back();
			}
		}
		return;
	}

	vector<vector<string>> partition(string s) {
		if (s.empty()) return ans;

		vector<string> layer;
		helper(s, layer, 0);
		return ans;
	}
};

//Fastest
class Solution {
public:
bool isPalindrome(string s){
    int l = 0;
    int r = s.size() - 1;
    while(l < r){
        if(s[l++] != s[r--]){
            return false;
        }
    }
    return true;
}
void helper(string s, vector<vector<string>> &result, vector<string> temp){
    if(s.size() == 0){
        result.push_back(temp);
    }
    for(int i = 0; i < s.size(); i++){
        string leftPar = s.substr(0, i + 1);
        if(isPalindrome(leftPar)){
            temp.push_back(leftPar);
            helper(s.substr(i + 1), result, temp);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> temp;
    helper(s, result, temp);
    return result;
}
};