//DFS
public class Solution {
    public bool CanReach(int[] arr, int start) {
        return Dfs(arr, start, 0);
    }
    
    private bool Dfs(int[] arr, int start, int count){
        if(start<0 || start>=arr.Length) return false;
        if(count >= arr.Length) return false;
        if(arr[start] == 0) return true;
        
        return Dfs(arr, start+arr[start], count+1) ||
            Dfs(arr, start-arr[start], count+1);
    }
}

//Fourth fastest
public class Solution {
    HashSet<int> is_pass_plus;
    HashSet<int> is_pass_minus;
    public bool CanReach(int[] arr, int start) {
      is_pass_plus = new HashSet<int>();
      is_pass_minus = new HashSet<int>();
      return CanReachHelper(arr: arr, start: start);
    }

    private bool CanReachHelper(int[] arr, int start) {
      if (arr[start] == 0) {
        return true;
      }

      bool pass = false;
      if (start + arr[start] < arr.Length) {
        if (is_pass_plus.Contains(start) == false) {
          is_pass_plus.Add(start);
          pass = CanReachHelper(arr: arr, start: start + arr[start]);
        }
      }

      if (pass == true) {
        return true;
      } else if (start - arr[start] >= 0) {
        if (is_pass_minus.Contains(start) == false) {
          is_pass_minus.Add(start);
          pass = CanReachHelper(arr: arr, start: start - arr[start]);
        } 
      }

      return pass;
    }
}

//Third fastest
public class Solution {
    
    // 使用BFS  [index, value]   {4,3}<--{5,1}-->{6,2} 就像一个二叉树，遍历二叉树，知道找到value是0的情况。
    // "Given an array of non-negative integers arr" 给定一个没有负数的数组，我们可以用负数标记已经访问过的元素
    //  In C#， Dequeue 返回值，Enqueue是void
    public bool CanReach(int[] arr, int start) {
        
        Queue<int> queue = new Queue<int>(); // 存放index
        queue.Enqueue(start);
        
        while(queue.Count>0)
        {   
            // step1： 首先, 列头出列
            int cur = queue.Dequeue();
            
            // step 2： 如果列头对应的元素是 0
            if(arr[cur] == 0)
                return true;
            
            // step 3： 如果列头对应的元素已经被访问,小于0,跳出循环，继续下一轮出栈
            if(arr[cur] < 0)
                continue;
            
            //step 4:  如果列头对应的元素大于0, 找出左右孩子入栈，但是要检查下标
            int left = cur - arr[cur];
            int right = cur + arr[cur];
            if (left >= 0)
                queue.Enqueue(left);
       
            if (right < arr.Length)
                queue.Enqueue(right);
            
            //step 5: cur对应的元素的左右孩子全部被访问了，设置这个元素为负数
            arr[cur] = -arr[cur];              
        }
        
        return false; // 默认返回false
    }

    // 使用 DFS
    public bool CanReach1(int[] arr, int start) {
        if(start >= 0 && start < arr.Length && arr[start] >= 0)
        {
            if (arr[start] == 0)
                return true;
        
            // 访问不过的元素标记为负数
            arr[start] = -arr[start];
        
            return CanReach(arr, start - arr[start]) || CanReach(arr, start + arr[start]);
        }
        
        return false;
    }
      
    // 这个效率似乎更高，我自己写的，但是逻辑似乎有问题(面试时不要使用了为好)  
    public bool CanReach2(int[] arr, int start) {
        
        Queue<int> queue = new Queue<int>();
        queue.Enqueue(start);
        
        while(queue.Count>0)
        {   
            int cur = queue.Dequeue();
            
            if(arr[cur] == 0)
                return true;
            
            int left = cur - arr[cur];
            int right = cur + arr[cur];
            if (left >= 0 && left < arr.Length && arr[left] >= 0)
            {
                queue.Enqueue(left);
                arr[left] = -arr[left];
            }
            if (right < arr.Length && right >= 0 && arr[right] >= 0)
            {
                queue.Enqueue(right);
                arr[right] = -arr[right];
            }                   
        }
        
        return false;
    }

}

//Second fastest
public class Solution {
    public bool CanReach(int[] arr, int start) {
        return traverse(start, arr, new List<int>());
    }
    
    private bool traverse(int currentIndex, int[] arr, List<int> visitedIndexes){
        
        if(arr[currentIndex] == 0){
            return true;
        }else if(visitedIndexes.Contains(currentIndex)){
            return false;
        }
        
        visitedIndexes.Add(currentIndex);
        
        if(arr.Length > (currentIndex + arr[currentIndex])){
            if(traverse(currentIndex + arr[currentIndex], arr, new List<int>(visitedIndexes))){
                return true;
            }
        }

        if((currentIndex - arr[currentIndex]) >= 0){
            if(traverse(currentIndex - arr[currentIndex], arr, new List<int>(visitedIndexes))){
               return true; 
            }
        }
    
        
        return false;
    }
}

//Fastest(BFS)
public class Solution {
    public bool CanReach(int[] arr, int start) {
        int n = arr.Length;
        var queue = new Queue<int>();
        var visited = new HashSet<int>() { start };
        queue.Enqueue(start);
        while (queue.Count > 0) {
            int curr = queue.Dequeue(), v = arr[curr];
            if (v == 0) {
                return true;
            }
            int l = curr - v, r = curr + v;
            if (l >= 0 && visited.Add(l)) {
                queue.Enqueue(l);
            }
            if (r < n && visited.Add(r)) {
                queue.Enqueue(r);
            }
        }
        return false;
    }
}