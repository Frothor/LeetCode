public class Solution
    {
        public int RemoveCoveredIntervals(int[][] intervals)
        {
            Array.Sort(intervals, (a, b) =>
            {
                var c1 = a[0].CompareTo(b[0]);
                if (c1 != 0)
                {
                    return c1;
                }

                return b[1].CompareTo(a[1]);
            });
            int res = intervals.Length;


            int left = 0;
            int right = 0;

            while (left < intervals.Length)
            {
                var currInterval = intervals[left];
                right = left + 1;

                while (right < intervals.Length && intervals[right][0] >= currInterval[0] && intervals[right][1] <= currInterval[1])
                {
                    right++;
                    res--;
                }

                left = right;
            }

            return res;
        }
    }

//Second fastest
public class Solution
    {
        static readonly IComparer<int[]> _comparer = Comparer<int[]>.Create((x, y) => x[0] == y[0] ? y[1].CompareTo(x[1]) : x[0].CompareTo(y[0]));

        public int RemoveCoveredIntervals(int[][] intervals)
        {
            if (intervals.Length == 1) return 1;

            Array.Sort(intervals, _comparer);
            var l = intervals[0][0];
            var r = intervals[0][1];
            var count = 0;
            foreach (var interval in intervals[1..])
            {
                var a = interval[0];
                var b = interval[1];
                // covered
                if (l <= a && b <= r) count += 1;
                // to merge
                if (a <= r && r <= b) r = b;
                // disjoint
                if (r < a)
                {
                    l = a;
                    r = b;
                }
            }
            return intervals.Length - count;
        }
    }

//Fastest
public class Solution {
    private class Node
    {
        public Node next;
        public int start, end;
        
        public Node(int start, int end)
        {
            this.start = start;
            this.end = end;
        }
    }
    public int RemoveCoveredIntervals(int[][] intervals) {
        var start = new Node(int.MinValue, int.MinValue);
        int count = 0;
        foreach(var interval in intervals)
        {
            Node node;
            for(node = start; node.next != null && node.next.start < interval[0]; node = node.next);
            if(node.end >= interval[1])
            {
                continue;
            }
            if(node.start == interval[0])
            {
                node.end = interval[1];
            }
            else
            {
                node.next = new Node(interval[0], interval[1]) {next = node.next};
                node = node.next;
                count++;
            }
            Node temp; 
            for(temp = node; temp.next != null && temp.next.end <= node.end; count--, temp = temp.next);
            if(node!= temp)
            {
                node.next = temp.next;
            }
        }
        return count;
    }
}