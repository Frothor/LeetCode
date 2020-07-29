//Fastest
public class Solution {
    public int LeastInterval(char[] tasks, int n) {
        var tasksCount = new int[26];
        var totalCount = 0;
        for(var i = 0; i<tasks.Length;i++) {
            tasksCount[tasks[i] - 'A']++;
            totalCount++;
        }
        tasksCount = tasksCount.OrderBy(t => t).ToArray();
        var idleTime = (tasksCount[25] - 1) * n;
        for(var i = 24; i >= 0 && tasksCount[i] > 0; i--) {
            idleTime -= Math.Min(tasksCount[i], tasksCount[25] - 1);
        }
        return idleTime < 0 ? totalCount : totalCount + idleTime;
    }
}

/*
Most common:
public class Solution {
    public int LeastInterval(char[] tasks, int n) {
        if(tasks == null || tasks.Length == 0)
        {
            return 0;
        }
        int[] charMap = new int[26];// frequency map for each character
        for(int i = 0; i < tasks.Length; i++)
        {
            charMap[tasks[i] - 'A']++;
        }
        
        Array.Sort(charMap);//sort the map
        
        int maxVal = charMap[25] - 1;//max frequency -1 , because you don't need any ideal period after the last task
        int idleSlots = maxVal * n;// idle slots is the max frequency val * the cool off period
        
        for(int i = 24; i >= 0; i--)
        {
            idleSlots -= Math.Min(charMap[i], maxVal);//filling up the idle slots with remaining characters
        }//and decrementing the no by the tasks run
        
        return idleSlots > 0 ? idleSlots + tasks.Length : tasks.Length;
    }
}
*/