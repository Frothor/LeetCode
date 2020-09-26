public class Solution
{
    public int FindPoisonedDuration(int[] timeSeries, int duration)
    {
        if(timeSeries.Length is 0 || duration is 0) return 0;
        int prevEnd = timeSeries[0] , end = prevEnd + duration, res = duration;
        for(int i = 1; i < timeSeries.Length; i++)
        {
            prevEnd = end;
            int start = timeSeries[i];
            end = start + duration;
            res += end - Math.Max(prevEnd, start);
        }
        return res;
    }
}

//Most common
public class Solution
        {
            public int FindPoisonedDuration(int[] timeSeries, int duration)
            {
                if (duration == 0 || timeSeries.Length == 0)
                    return 0;

                var sum = 0;

                for (var i = 0; i < timeSeries.Length; i++)
                {
                    var finalAttack = (timeSeries[i] - 1) + duration;

                    if (i == timeSeries.Length - 1)
                    {
                        sum += duration;
                    }
                    else
                    {
                        var nextPoint = timeSeries[i + 1];

                        if (finalAttack >= nextPoint)
                        {
                            sum += duration - (finalAttack - (nextPoint - 1));
                        }
                        else
                        {
                            sum += duration;
                        }
                    }
                }

                return sum;
            }
        }

//Fastest
public class Solution {
    public int FindPoisonedDuration(int[] timeSeries, int duration) {
        
        int totalDuration = duration*timeSeries.Length;
        for (int i = 1; i < timeSeries.Length; i++) {
            if (timeSeries[i]-timeSeries[i-1] < duration) totalDuration -= duration-(timeSeries[i]-timeSeries[i-1]);
        }
        
        return totalDuration;
    }
}