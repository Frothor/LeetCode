public class Solution {
    public int FindPairs(int[] nums, int k) {
        if (k == 0) {
            Dictionary<int,int> dict = new Dictionary<int,int>();
            foreach (int i in nums ) {
                if (dict.ContainsKey(i))
                    dict[i] += 1;
                else
                    dict[i] = 1;
            }
            return dict.Values.Where(c => c >= 2).Count();
        }

        int result = 0;
        HashSet<int> hset = new HashSet<int>();
        foreach (int i in nums) {
            if (!hset.Contains(i)) {
                if (hset.Contains(i+k))
                    result++;
                if (hset.Contains(i-k))
                    result++;
            }
            hset.Add(i);
        }
        return result;
    }
}

//Most common
public class Solution {
    public int FindPairs(int[] nums, int k) {
        
            int ans = 0;
            Dictionary<int, int> mm = new Dictionary<int, int>();

            for (int i = 0; i < nums.Length; i++)
            {
                if (mm.ContainsKey(nums[i]))
                {
                    mm[nums[i]]++;
                }
                else 
                {
                    mm.Add(nums[i], 1);
                }
            }

            for (int i = 0; i < nums.Length; i++)
            {
                if (k > 0 && mm.ContainsKey(nums[i] + k) && mm[nums[i]] > 0)
                {
                    mm[nums[i]] = -1;
                    ans++;
                }

                if (k == 0 && mm.ContainsKey(nums[i]) && mm[nums[i]] > 1)
                {
                    ans++;
                    mm[nums[i]] = -1;
                }
            }

            return ans;
    }
}

//Fastest
public class Solution {
    public int FindPairs(int[] nums, int k) {
            if (k < 0)
            {
                return 0;
            }

            int answer = 0;
            Dictionary<int, int> dic = new Dictionary<int, int>();
            foreach (int n in nums)
            {

                if (dic.ContainsKey(n))
                {
                    if (dic[n] <= 1 &&  k==0) 
                    {
                        answer++;
                        dic[n]++;
                    }
                    
                    continue;
                }

                if (dic.ContainsKey(n - k)) 
                {
                    answer++;
                    dic[n - k]++;
                }
                if (dic.ContainsKey(n + k))
                {
                    answer++;
                    dic[n + k]++;
                }

                dic.Add(n, 1);
        
            }

            return answer;        
    }
}