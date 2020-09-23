public class Solution {
    public int CanCompleteCircuit(int[] gas, int[] cost) {
        int len = gas.Length;
        int si = 0;
        while (si < len) {
            if (gas[si] < cost[si]) {
                si++;
                continue;
            }
            int g = gas[si], c = cost[si], i = (si+1) % len;
            while (g-c >= 0 && i != si) {
                g = g-c + gas[i];
                c = cost[i];
                i = (i+1) % len;
            }
            if (i > si)
                si = i;
            else
                return (g-c >= 0) ? si : -1;
        }
        return -1;
    }
}

//Fastest
public class Solution {
    public int CanCompleteCircuit(int[] gas, int[] cost) {
            if (gas == null || gas.Length == 0)
                return -1;

            int over = 0, def = 0, index = 0;

            for(int i = 0; i< gas.Length; i++)
            {
                over = over + gas[i] - cost[i];
                if (over < 0)
                {
                    //Deficit 
                    def += over;
                    index = i + 1;
                    over = 0;
                }
            }

            return (over + def >= 0) ? index : -1;
    }
}