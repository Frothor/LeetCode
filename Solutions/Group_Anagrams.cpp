/*
LeetCode Group Anagrams

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > map;
        vector<vector<string> > res;
        
        for (int i = 0; i < strs.size(); i++)
	    {
		    string k = strs[i];
		    sort(strs[i].begin(), strs[i].end());
            map[strs[i]].push_back(k);

	    }

	    for (auto& n : map)
	    {
		    res.push_back(n.second);
	    }

	    return res;
    }
};
