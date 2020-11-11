//Third fastest
using System.Drawing;

public class Solution {
    public bool ValidSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        const float epsilon = 0.000000001f;
        var vectors = new PointF[6];
        vectors[0] = new PointF() { X = p1[0] - p2[0], Y = p1[1] - p2[1] };
        vectors[1] = new PointF() { X = p1[0] - p3[0], Y = p1[1] - p3[1] };
        vectors[2] = new PointF() { X = p1[0] - p4[0], Y = p1[1] - p4[1] };
        vectors[3] = new PointF() { X = p2[0] - p3[0], Y = p2[1] - p3[1] };
        vectors[4] = new PointF() { X = p2[0] - p4[0], Y = p2[1] - p4[1] };
        vectors[5] = new PointF() { X = p3[0] - p4[0], Y = p3[1] - p4[1] };
        var lens = vectors.Select(x => x.X*x.X + x.Y*x.Y).OrderBy(x => x).ToArray();
        
        if (lens.Any(x => Math.Abs(x - 0.0f) < epsilon)) {
            return false;
        }
        
        for (var i = 1; i < 4; ++i) {
            if (Math.Abs(lens[0] - lens[i]) > epsilon) {
                return false;
            }
        }        
        
        return Math.Abs(lens[4] - lens[5]) < epsilon;
    }
}

//Second fastest
public class Solution {
    public bool ValidSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
         int[] p12 = new int[] { p2[0] - p1[0], p2[1] - p1[1]};
            int[] p13 = new int[] { p3[0] - p1[0], p3[1] - p1[1] };
            int[] p14 = new int[] { p4[0] - p1[0], p4[1] - p1[1] };

            int p23prod = p12[0] * p13[0] + p12[1] * p13[1];
            int p24prod = p12[0] * p14[0] + p12[1] * p14[1];
            int p34prod = p13[0] * p14[0] + p13[1] * p14[1];

            int p12dist = p12[0] * p12[0] + p12[1] * p12[1];
            int p13dist = p13[0] * p13[0] + p13[1] * p13[1];
            int p14dist = p14[0] * p14[0] + p14[1] * p14[1];

            //  fix1: corner case, zero
            bool result = false;
            if (p23prod.Equals(0) && p12dist.Equals(p13dist) && p12dist > 0 && (p12[0] + p13[0]).Equals(p14[0]) && (p12[1] + p13[1]).Equals(p14[1]))
                result = true;
            else if (p24prod.Equals(0) && p12dist.Equals(p14dist) && p12dist > 0 && (p12[0] + p14[0]).Equals(p13[0]) && (p12[1] + p14[1]).Equals(p13[1]))
                result = true;
            else if (p34prod.Equals(0) && p13dist.Equals(p14dist) && p13dist > 0 && (p13[0] + p14[0]).Equals(p12[0]) && (p13[1] + p14[1]).Equals(p12[1]))
                result = true;

            return result;
    }
}

//Fastest
public class Solution
{
	public bool ValidSquare(int[] p1, int[] p2, int[] p3, int[] p4)
	{
		HashSet<int> distinct = new HashSet<int>();
		distinct.Add(Dist(p1, p2));
		distinct.Add(Dist(p1, p3));
		distinct.Add(Dist(p1, p4));
		distinct.Add(Dist(p2, p3));
		distinct.Add(Dist(p2, p4));
		distinct.Add(Dist(p3, p4));

		return distinct.Count == 2 && !distinct.Contains(0);
	}

	//not using Math.Pow to avoid double cast
	private int Dist(int[] p1, int[] p2) => (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
}

//Another
public class Solution {
    public bool ValidSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        
        HashSet<int> set = new HashSet<int>();
        
        if(same(p1,p2) || same(p1,p3) || same(p1,p4)
          || same(p2,p3) || same(p2,p4) || same(p3,p4)){
            return false;
        }
        
        set.Add(dis(p1,p2));
        set.Add(dis(p1,p3));
        set.Add(dis(p1,p4));
        set.Add(dis(p2,p3));
        set.Add(dis(p2,p4));
        set.Add(dis(p3,p4));
        
        return set.Count == 2;
        
    }
    
    private int dis(int[] p1, int[] p2){
        double effort = Math.Floor(Math.Pow((p1[0] - p2[0]), 2) + Math.Pow((p1[1] - p2[1]), 2));
        return (int)effort;
    }
    
    private bool same(int[] p1, int[] p2){
        return p1[0] == p2[0] && p1[1] == p2[1];
    }
    
}