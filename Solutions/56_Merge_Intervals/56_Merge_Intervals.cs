//Quite ellegant
public class Solution {
    public int[][] Merge(int[][] intervals) {
        var res = new Stack<int[]>();
        foreach(var interval in intervals.OrderBy(x => x[0])){
            if(res.TryPeek(out var last) && last[1] >= interval[0])
                last[1] = Math.Max(last[1], interval[1]);
            else
                res.Push(interval);
        }
        
        return res.ToArray();
    }
}

//Third fastest
public class Solution {
    public int[][] Merge(int[][] intervals) {
        Array.Sort(intervals, (x, y) => x[0].CompareTo(y[0]));
        var result = new List<int[]>();
        var temp = intervals[0];                       
        
        for(int i = 1; i < intervals.Length; i++) {
            var c = intervals[i];
            if(temp[1] < c[0]) {
                result.Add(temp);
                temp = c;
                continue;
            }
            temp = new int[] {Math.Min(temp[0], c[0]), Math.Max(temp[1], c[1])};
        }
        result.Add(temp);
        return result.ToArray();
    }
}

//Second fastest
public class Solution {
    public int[][] Merge(int[][] intervals) {
        List<int[]> res = new List<int[]>();
        if (intervals.Length == 0)  return res.ToArray();
        Array.Sort(intervals, (a,b)=>(a[0].CompareTo(b[0])));
        int start = intervals[0][0], end = intervals[0][1];
        foreach(int[] ivl in intervals) {
            if (ivl[1] < end)   continue;
            if (ivl[0] > end) {
                res.Add(new int[2]{start, end});
                start = ivl[0];
                end = ivl[1];
                continue;
            }
            end = ivl[1];
        }
        res.Add(new int[2]{start, end});
        return res.ToArray();
    }
}

//Fastest
public class Solution {
    public int[][] Merge(int[][] intervals) {
        if(intervals?.Length == 0) {
            return intervals;
        }
        
        Array.Sort(intervals, new Comparer());

        List<int[]> result = new List<int[]>();
        int[] interval = intervals[0];
        for(int i = 1; i < intervals.Length; i++) {
            if(intervals[i][0] > interval[1]) {
                result.Add(interval);
                interval = intervals[i];
            }
            else {
                interval[1] = Math.Max(intervals[i][1], interval[1]);
            }
        }
        result.Add(interval);
        return result.ToArray();
    }
    
    public class Comparer : IComparer
    {
        public int Compare(object o1, object o2) {
            int[] arr1 = (int[])o1;
            int[] arr2 = (int[])o2;
            
            return arr1[0] == arr2[0] ? arr1[1].CompareTo(arr2[1]) : arr1[0].CompareTo(arr2[0]);
        }
    }
}