public class Solution {
    private void Backtrack(int[] cand, int target, int sum, int i, List<int> comb, List<IList<int>> result) {
        if (sum > target)
            return;
        if (sum == target) {
            result.Add(comb.ToList());
            return;
        }
        while (i < cand.Length) {
            sum += cand[i];
            comb.Add(cand[i]);
            Backtrack(cand, target, sum, i, comb, result);
            sum -= cand[i];
            comb.RemoveAt(comb.Count-1);
            i++;
        }
   }
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        List<IList<int>> result = new List<IList<int>>();
        List<int> comb = new List<int>();
        Backtrack(candidates, target, 0, 0, comb, result);
        return result;
    }
}

//Most common
public class Solution {
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
            var store = new List<IList<int>>();
            CombinationSum(candidates, 0, target, store, new List<int>());
            return store;
        }

        private void CombinationSum(int[] candidates, int index, int target, List<IList<int>> store, List<int> current)
        {
            if (target < 0 || index == candidates.Length)
                return;

            if (target == 0)
            {
                store.Add(new List<int>(current));
                return;
            }

            current.Add(candidates[index]);
            CombinationSum(candidates, index, target - candidates[index], store, current);
            current.RemoveAt(current.Count - 1);
            CombinationSum(candidates, index + 1, target, store, current);
        }

}

//Fastest
public class Solution
    {
        public IList<IList<int>> CombinationSum(int[] candidates, int target)
        {
            var solutions = new List<int[]>();
            Backtrack(solutions, new List<int>(), 0, candidates, 0, target);
            return solutions.ToArray();
        }

        void Backtrack(List<int[]> solutions, List<int> combination, int currentSum, int[] candidates, int ptr, int target)
        {
            if (currentSum == target)
            {
                solutions.Add(combination.ToArray());
                return;
            }
            if (ptr == candidates.Length || currentSum > target) return;

            // Skip the current one directly
            Backtrack(solutions, combination, currentSum, candidates, ptr + 1, target);

            // Use the current one
            var n = candidates[ptr];
            if (currentSum + n <= target)
            {
                combination.Add(n);
                Backtrack(solutions, combination, currentSum + n, candidates, ptr, target);
                combination.RemoveAt(combination.Count - 1);
            }
        }
    }