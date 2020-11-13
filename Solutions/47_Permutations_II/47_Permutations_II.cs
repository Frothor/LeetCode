public class Solution {
    private List<IList<int>> res = new List<IList<int>>();
    
    public IList<IList<int>> PermuteUnique(int[] nums) {
        var unused = nums.ToList();
        Array.Sort(nums);
        Backtrack(new List<int>(), nums, new bool[nums.Length]);
        return res;
        
    }
    
    private void Backtrack(IList<int> cur, int[] nums, bool[] used){
        if(cur.Count == nums.Length){
            res.Add(new List<int>(cur));
            return;
        }
        
        for(int i = 0; i<nums.Length; i++){
            if(used[i])
                continue;
            
            if(i>0 && nums[i-1] == nums[i] && !used[i-1])
                continue;
            used[i] = true;
            
            cur.Add(nums[i]);
            Backtrack(cur, nums, used);
            used[i] = false;
            cur.RemoveAt(cur.Count-1);
        }
    }
}

//Fourth fastest
public class Solution {
    public IList<IList<int>> PermuteUnique(int[] nums) 
    {
        IList<IList<int>> res = new List<IList<int>>();
        Helper(0, res, nums);        
        return res;       
    }

    private void Helper(int nextIndex, IList<IList<int>> res, int[] nums)
    {
        if(nextIndex == nums.Length)
        {
            res.Add(nums.ToList());
            return;
        }

        HashSet<int> visited = new HashSet<int>();
        for(int i = nextIndex; i < nums.Length; i++)
        {
            if(visited.Add(nums[i]))
            {
                int t = nums[i];
                nums[i] = nums[nextIndex];
                nums[nextIndex] = t;

                Helper(nextIndex + 1, res, nums);

                t = nums[i];
                nums[i] = nums[nextIndex];
                nums[nextIndex] = t;
            }
        }        
    }
}

//Third fastest
public class Solution {
    public IList<IList<int>> PermuteUnique(int[] nums) {
        List<int> input = new List<int>(nums);
            input.Sort();
            List<int> current = new List<int>();
            IList<IList<int>> ans = new List<IList<int>>();
            GeneratePemutationUnique(nums.Length, current, input, ans);
            return ans;
    }
    private void GeneratePemutationUnique(int targetLength, List<int> current, List<int> input, IList<IList<int>> ans)
        {
            if (current.Count == targetLength)
            {
                ans.Add(current);
                return;
            }
            int? temp = null;
            for (int i = 0; i < input.Count; i++)
            {
                if(temp == null)
                {
                    temp = input[i];
                }
                else if(temp == input[i])
                {
                    continue;
                }
                else
                {
                    temp = input[i];
                }
                List<int> nextRound = new List<int>(input);
                nextRound.RemoveAt(i);
                List<int> nextCurrent = new List<int>(current);
                nextCurrent.Add(input[i]);
                GeneratePemutationUnique(targetLength, nextCurrent, nextRound, ans);
            }
        }
}

//Secondf fastest
public class Solution {
    public IList<IList<int>> PermuteUnique(int[] nums) {
        var lists = new List<IList<int>>();
        Array.Sort(nums);
        Helper(nums, new bool[nums.Length], lists, new List<int>());
            return lists;
    }
    
    public void Helper(int[] nums, bool[] visited, List<IList<int>> lists, List<int> list)
    {
        if(list.Count==nums.Length)
        {
            lists.Add(new List<int>(list));
            return;
        }
        
        for(var i=0; i<nums.Length; i++)
        {
            if(visited[i])
                continue;
            if(i>0 && nums[i]==nums[i-1] && !visited[i-1])
                continue;
            
            list.Add(nums[i]);
            visited[i]=true;
            
            Helper(nums, visited, lists, list);
            
            list.RemoveAt(list.Count-1);
            visited[i]=false;
        }
    }
}

//Fastest
public class Solution {
    public IList<IList<int>> PermuteUnique(int[] nums) {
        var dic = new Dictionary<int,int>();
        foreach(var num in nums){
            if(!dic.ContainsKey(num))
                dic.Add(num, 0);
            dic[num]++;
        }
        
        var vis = new Dictionary<int, bool>();
        Recur(nums, new List<int>(), dic);
        return res;
    }
    
    IList<IList<int>> res = new List<IList<int>>();
    
    void Recur(int[] nums, IList<int> curr, Dictionary<int,int> dic){
        if(curr.Count() == nums.Length){
             var list = new List<int>();
                list.AddRange(curr);
                res.Add(list);
            return;
        }
       
        List<int> keys = new List<int>(dic.Keys);
        foreach(var entry in keys){
            if(dic[entry] == 0)
                continue;
            curr.Add(entry);
            dic[entry]--;
            Recur(nums, curr, dic);
            curr.RemoveAt(curr.Count()-1);
            dic[entry]++;
        }
        
    }
}