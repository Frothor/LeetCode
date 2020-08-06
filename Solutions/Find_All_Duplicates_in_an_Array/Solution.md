# Find All Duplicates in an Array Solution

**Note** : This Is A real Interiew Question So Your Ans shuld prepair Like Fallowing sequential
way Starting with **O(N*N)** naive approch To **O(N) & constant Space :)**

**Let's Start :: = >**

## 1. Bruteforce Apprch
Idea - Do Check Double Time For Each element

Time Complexcity - O(N*N) **<=Give You TLE**
Space Complexcity - O(1)
```c++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]!=nums[j])continue;
                else{
                    ans.push_back(nums[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
```

## 2.Using Sort Solution
Idea - Do **sort The array** First Then Track Adjcent Element Is Same Or Not [Can be Done By XOR or Have an count Element]

Time Complexcity - O(N*Log N)
Space Complexcity - O(1)
```c++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        sort(begin(nums),end(nums));
        int s = nums[0];
        for(int i=1;i<nums.size();i++){
            if(!(s^nums[i])){
                ans.push_back(nums[i]),i+=1;
                if(i<nums.size())s=nums[i];
                else break;
            }
                else s = nums[i];
        }
        return ans;
    }
};
```

## 3. Using Unordered map

Idea - Take An unordered_map To store frequency Of each Element And Return those Having Frequency **2**
Time Complexcity - O(N)
Space Complexcity - O(N)
```c++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int no:nums)mp[no]++;
        for(auto it:mp)if(it.second==2)ans.push_back(it.first);
        return ans;
        return ans;
    }
};
```

## 4. Most Efficent Solution
Idea -
If you Look This ->array of integers, 1 ≤ a[i] ≤ n (n = size of array)constrain [ given ]
We Can Easyly Identify That All element's Are greater Then or equal **1** and Less Then or Equall **size of the array**
And **2** . Constrain elements appear twice and others appear once

So try To Use Those Information To Come Up better a solution

What We can Do is That We Can Use That Given Array As an Frequency Array
and Instade of Count The each Element we Can Use **-[minus]** To track Each Element we are traverse Or Not [as They said That any element can occoure max Twice]
While Traverseing if We Get Negetive element again We Know That It's Allredy Visited So It Wolud Be a duplicate num <= Push That Into ANS array

Lastly Return ANS array
```c++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        return ans;
    }
};
```

[Link to original post](https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/775798/c%2B%2B-Four-Solution-or-O-(n*n-)-greater-O(-n-)-with-Constant-Space-or-Explain-All)

[Another helpful explanation](https://medium.com/solvingalgo/solving-algorithmic-problems-find-a-duplicate-in-an-array-3d9edad5ad41)