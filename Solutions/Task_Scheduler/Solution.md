# Task Scheduler Solution
## Solution 1

The most frequent character will be placed at (n+1)th distance from each other, such that the gap between them remains 'n'. So, max_freq will count the maximum occurence of the character. Finally, minimum time idle_time will be (max_freq-1)*(n+1)+1, +1 because at the last occurence of the element we must stop, This minimum required time can be extended if there are same number of maximum frequency elements in the character array,here, denoted by inc, so +1 for all such elements. Now, if the other char does not fit in this time we must consider the complete tasks.size().

```c++
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return (int)tasks.size();
        map<char,int> freq; 
        int max_freq = 0,inc=0;
        for(int x : tasks) {freq[x]++; max_freq = max(max_freq, freq[x]);}
        int idle_time = (max_freq-1)*(n+1)+1;
        for(auto it: freq){
            if(it.second==max_freq) inc++;
        }
        int ans = idle_time+(inc-1); // One of which was already used for the maximum frequency char earlier //
        return max(ans, (int)tasks.size());
    }
};
```

[Link to original post](https://leetcode.com/problems/task-scheduler/discuss/760120/My-C%2B%2B-Solution-easy-to-understand)

## Solution 2
This is a very good problem. It makes me immediately think of a problem in atcoder:
https://atcoder.jp/contests/abc143/tasks/abc143_f
I strongly recommend you trying this problem, it is very good!

For this problem it is simplier but still a bit tricky. Here is my ideas:

Q0. It seems like a greedy problem. How to make the time units being occupied as more as possible?
A0. Choose every **n+1** elements in a round. And choose those with the maximum occurence.

For example: **["A","A","A","A","A","B","B","C"]**, **n = 1**, **A** occurs **5** times, **B** occurs **2**, **C** occurs **1**. Then in the first round we choose **A,B**. Second round choose **A,B**. Third round choose **A,C**. Fourth round we can only choose **A,null**. Fifth rounds we choose **A** only. We use 5 rounds in total, which need 9 units.

Q1. What is the "lower bound" of the answer? That is, what is "forcing" us to use more units?
A1. Obviously, the lower bound is determined by **maxcnt**, the maximum of the occurence of each element. In the above example, **maxncnt = 5**. So, we have to choose ***at least*** **maxcnt** rounds, hence the answer is at least **(maxcnt-1)*(n+1) + e**. Where e is the number of occurences which equals to **maxcnt**. In the above example, there is only one element with occruence equals to **5**, hence **e = 1**.

Q1.5. Wait, why isn't the lower bound equals to **maxcnt * (n+1)**?
A1.5. See the above example, in last round we don't need to wait for anything. But if there are multiple elements having occurence = **maxcnt**, we still need to handle them.

Q2. What is the "upper bound" of the answer? That is, what if we don't have any idle time units, what is the answer then?
A2. Obviously, it is the size of input array **tasks**.

So we are done! The answer is just: **max(tasks.size(), (maxcnt-1)*(n+1) + e)**.

Q3. But how to prove this?
A3. A serious proof is a bit long, but the intuition is that, if we are not bounded by the "lower bound". We can fully use all the time units.
```c++
class Solution {
public:
    int cnt[26], maxcnt = 0, e = 0;
    int leastInterval(vector<char>& tasks, int n) {
        for (char c : tasks) cnt[c-'A']++;
        for (int i = 0; i < 26; i++) maxcnt = max(maxcnt, cnt[i]);
        for (int i = 0; i < 26; i++) 
            if (cnt[i] == maxcnt) e++;
        return max(tasks.size(), (maxcnt-1)*(n+1) + e);
    }
};
```
[Link to original post](https://leetcode.com/problems/task-scheduler/discuss/760569/C%2B%2B-Greedy-O(n)-time-O(1)-space-with-explanation-in-5-lines.)

## Solution 3 -> same as Solution 2 but another explanation

### Intuition of the problem
We have to find least number of intervals to finish all tasks. Given that, each task requires one interval, for tasks of size t, we need at least t intervals to complete it.

Now the problem is reduced to finding the minimum idle time when no task is executing.
Our result would be **idle Time + t (size of task array)**

### How to find the idle time ?
Assume, there 3 A tasks. Tasks = **["A","A","A","B"]** . cooling time n = 2 .
If A Is run at a particular time, we cannot run it for 2 intervals after that.
So we have to try filling up those 2 spaces with some other task.

>What are the maximum number of idle spaces that we could have?

It would be (max Frequency task - 1 * n)
In this example, A has maximum frequency of 3, so there are 2 set of intervals(each of size n=2) that needs to be filled with some other task.
|A| | |A| | |A|

Once we know the maximum number of idle spaces, we have to just reduce the the count of spaces every time we find a task that can fill up that idle space.

### Steps -
1) Create count array to keep track of frequency of each task. Size 26 as given in input.
2) Sort the frequency is ascending order, the task at last position (**arr[25]**) would be the one with maximum frequency.
**Example** -
Tasks **["A","A","A","B","B","C"]**
A has max occurrence = 3, n = 2. Hence we can place A as follows
|A|idle|idle|A|idle|idle|A|

**Max idle spaces = (3-1) * 2 = 4**. We could see there 4 idle spaces above.

3)Now we have to just find that there are sufficient tasks to fill these 4 idle spaces.
We iterate over rest of array in descending order and substract it's count from idle spaces.
Task B has count 2 and C has count 1. Hence 1 space remains idle.

|A|B|C|A|B|idle|A

Answer , **task length + idle time = 6 + 1 = 7**
```java
class Solution {
	public int leastInterval(char[] tasks, int n) {
		if (tasks == null || tasks.length == 0) {
			return 0;
		}
		int m = tasks.length;
		int[] cnt = new int[26];
		/* Build the count array with frequency of each task */
		for (char c: tasks) {
			cnt[c - 'A']++;
		}
		Arrays.sort(cnt);
		/* Get maximum frequency task  and calculate max idle spaces*/
        int max = cnt[25]-1;
		int spaces = max * n;
		
		/* Iterate over rest of the array and reduce the idle space count */
		for (int i = 24; i >= 0; i--) {
			spaces -= Math.min(max, cnt[i]);
		}
		/* Handle cases when spaces become negative */
		spaces = Math.max(0, spaces);
		return tasks.length + spaces;
	}
}
```
[Link to original post](https://leetcode.com/problems/task-scheduler/discuss/760131/Java-Concise-Solution-Intuition-Explained-in-Detail)