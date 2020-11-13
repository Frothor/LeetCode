public class Solution {
    private List<IList<int>> res = new List<IList<int>>();
    
    public IList<IList<int>> Permute(int[] nums) {
        var unused = nums.ToList();
        
        ComputePermutations(new List<int>(), unused);
        return res;
    }
    
    private void ComputePermutations(List<int> cur, List<int> unused){
        if(unused.Count == 0){
            res.Add(new List<int>(cur));
            return; 
        }
        
        for(int i=0; i<unused.Count; i++){
            cur.Add(unused[i]);
            unused.RemoveAt(i);
            ComputePermutations(cur, unused);
            unused.Insert(i, cur[cur.Count-1]);
            cur.RemoveAt(cur.Count-1);
        }
    }
}

//Fourth fastest
using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> Permute(int[] nums) {
        var result=new List<IList<int>>();
        PermuteHelper(nums,pos:0,result);
        return result;
    }

    private void PermuteHelper(int[] nums, int pos, List<IList<int>> result)
    {
        if (pos==nums.Length-1)
        {
            result.Add(new List<int>(nums));
        }
        for (int i = pos; i < nums.Length; i++)
        {
            //swap pos with i
            //drilldown
            //swap pos with i
            Swap(nums,pos,i);
            PermuteHelper(nums,pos+1,result);
            Swap(nums,pos,i);
        }
    }

    private void Swap(int[] nums, int i, int j)
    {
        var tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
}

//Third fastest
public class Solution {
    public IList<IList<int>> Permute(int[] nums) {
        var ans = new List<IList<int>>();
        PermuteHelper(new List<int>(nums), new List<int>(), ans);
        return ans;
    }
    
    private void PermuteHelper(IList<int> nums, IList<int> choose, IList<IList<int>> ans)
    {
        if (nums.Count == 0)
            ans.Add(choose.ToArray());
        else
        {
            for (var i = 0; i < nums.Count; i++)
            {
                var num = nums[i];
                nums.RemoveAt(i);
                choose.Add(num);
                
                PermuteHelper(nums, choose, ans);
                
                choose.Remove(num);
                nums.Insert(i, num);
            }
        }
    }
}

//Second fastest
public class Solution {
   IList<IList<int>> res = new List<IList<int>>();

		public IList<IList<int>> Permute( int [] nums )
		{
			Backtrack( new List<int>(), nums );

			return res;
		}

		public void Backtrack( List<int> list, int [] nums ) 
		{
			if( list.Count == nums.Length )
			{
				res.Add( new List<int>( list ) );
			}
			else 
			{
				for( int i = 0; i < nums.Length; ++i ) 
				{
					if( list.Contains( nums [ i ] ) )
						continue;

					list.Add( nums [ i ] );
					Backtrack( list, nums );
					list.RemoveAt( list.Count - 1 );
				}
			}
		}
}

//Fastest
public class Solution {
   IList<IList<int>> res = new List<IList<int>>();

		public IList<IList<int>> Permute( int [] nums )
		{
			Backtrack( new List<int>(), nums );

			return res;
		}

		public void Backtrack( List<int> list, int [] nums ) 
		{
			if( list.Count == nums.Length )
			{
				res.Add( new List<int>( list ) );
			}
			else 
			{
				for( int i = 0; i < nums.Length; ++i ) 
				{
					if( list.Contains( nums [ i ] ) )
						continue;

					list.Add( nums [ i ] );
					Backtrack( list, nums );
					list.RemoveAt( list.Count - 1 );
				}
			}
		}
}