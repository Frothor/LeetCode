//Second fastest
  public class Solution
    {
        public int PoorPigs(int buckets, int minutesToDie, int minutesToTest)
        {
            int a = minutesToTest / minutesToDie + 1;
            int res = 1;
            int pow = a;
            if (buckets <= 1)
                return 0;
            while (pow < buckets)
            {
                res++;
                pow = pow * a;
            }
            return res;
        }
    }

//Fastest
public class Solution {
    public int PoorPigs(int buckets, int minutesToDie, int minutesToTest) {
        var T = minutesToTest/minutesToDie;
        var x = 0;
        while (Math.Pow(T+1, x) < buckets)
            x+=1;
        
        return x;
    }
}

//Another
public class Solution {
    public int PoorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets <= 0)
            {
                return 0;
            }

            //基本思路：在一个维度上，让一头猪吃完该维度上的所有篮子中的食物，等待minutesToDie看看
            //如果在该维度上没有死，说明该维度上所有篮子的食物没有毒.如果该猪死了，表示当前维度上某
            //一个篮子有毒。同理，另外一头猪在另外一个维度也用相同的方法吃，如果另外一头猪在某个维度
            //死了，那么这些猪死去时候相交点的篮子有毒。例如，
            //如果猪需要等待15分钟才知道是否中毒，在一个小时内，猪最多可以试吃5次(0分钟、15分钟、30分钟，
            //45分钟，60分钟)，即(60/15+1)。如果两头猪，可以组成一个5*5的二维矩阵篮子。一头猪每隔15分钟
            //选择一行的篮子全部试吃，另外一头猪每隔15分钟选择一列篮子全部试吃，假设行试吃的猪在第三行试吃
            //时候死掉，表示第三行某个篮子的篮子有毒，列试吃的猪在第二列试吃时候死掉，那么第三行和第二列相交
            //点的篮子有毒。同理如果组成5*5*5的三维矩阵篮子，一头猪每隔15分钟把X轴某一个面上的所有篮子试吃，
            //另外一头猪把Y轴某一个面上的所有篮子试吃，第三头猪把Z轴某一个面上的所有篮子试吃，三头猪死掉时候
            //对应的[x,y,z]点的篮子就是有毒。
            int tryTimes = minutesToTest / minutesToDie + 1;
            int totalPigs = 0;

            while((long)Math.Pow(tryTimes, totalPigs) < buckets)
            {
                totalPigs++;
            }

            return totalPigs;
    }
}