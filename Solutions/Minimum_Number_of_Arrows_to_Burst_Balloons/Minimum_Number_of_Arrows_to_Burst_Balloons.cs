public class Solution {
   public int FindMinArrowShots(int[][] points) 
{
	if(points == null || points.Length == 0)
	{
		return 0;
	}

	Array.Sort(points, (x, y) => x[1] == y[1] ? x[0].CompareTo(y[0]) : x[1].CompareTo(y[1]));                
	int arrows = 1;
	int right = points[0][1];

	for(int i = 1; i < points.Length; i++)
	{
		if(points[i][0] > right)
		{
			arrows++;
			right = points[i][1];
		}
	}

	return arrows;
}
}

//Third fastest
public class Solution {
    public int FindMinArrowShots(int[][] points) {
        if (points.Length == 0)
            return 0;
        Array.Sort(points, delegate(int[] p1, int[] p2) {
            return p1[1]>p2[1] ? 1 : p1[1]<p2[1] ? -1 :0;
        });
        int arrows = 1;
        int[] curPoint = points[0];
        for(int i=1;i<points.Length;i++){
            if(points[i][0] > curPoint[1]) {
                curPoint = points[i];
                arrows++;
            }
        }
        return arrows;
    }
}

//Second fastest
public class Solution
{
    public int FindMinArrowShots(int[][] points)
    {
        if (points == null || points.Length == 0) return 0;

        // asc sort by point end
        Array.Sort(points, (x, y) => x[1] - y[1]);

        var result = 1;
        var prev = points[0];
        
        for (var i = 1; i < points.Length; i++)
        {
            var curr = points[i];
         
            if (IsOverlapped(prev, curr)) continue;
            
            result++;
            prev = curr;
        }
        
        return result;
    }
    
    private static bool IsOverlapped(int[] prev, int[] curr)
    {
        var prevEnd = prev[1];
        var currStart = curr[0];
        return prevEnd >= currStart;
    }
}

//Fastest
public class Solution {
    public int FindMinArrowShots(int[][] points) {
        if(points == null || points.Length == 0){
            return 0;
        }
        Array.Sort(points, (x, y) => x[1] == y[1] ? x[0].CompareTo(y[0]) : x[1].CompareTo(y[1]));
        var arrowCount = 1;
	    var position = points[0][1];

	    for(int i = 1; i < points.Length; i++)
	    {
		    if(points[i][0] > position)
		    {
			    position = points[i][1];
                arrowCount++;
		    }
	    }

	    return arrowCount;
    }
}