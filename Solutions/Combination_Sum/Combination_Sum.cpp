//Most common
class Solution
{
public:
    void combine(vector<vector<int>> &ans, vector<int> &A, int target, vector<int> &temp, int &index)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
        {
            return;
        }
        for (int i = index; i < A.size(); i++)
        {
            temp.push_back(A[i]);
            combine(ans, A, target - A[i], temp, i);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        combine(ans, candidates, target, temp, index);
        return ans;
    }
};

//Fastest
class Solution
{
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }

private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int>> &res, std::vector<int> &combination, int begin)
    {
        if (target == 0)
        {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
        {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};