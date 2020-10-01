public class RecentCounter {

    Queue<int> q {get; set;} 
    
    public RecentCounter() {
        q = new Queue<int>();
    }
    
    public int Ping(int t) {
        q.Enqueue(t);
        while(q.Peek() < t - 3000) {
            q.Dequeue();
        }
        return q.Count();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.Ping(t);
 */


//Faster variation
public class RecentCounter {

    Queue<int> queue;
    public RecentCounter() {
        queue = new Queue<int>();
    }
    
    public int Ping(int t) {
        queue.Enqueue(t);
        while(queue.First() < t - 3000)
        {
            queue.Dequeue();
        }
        return queue.Count;
    }
}

//Fastest
public class RecentCounter {
    private readonly Queue<int> pings = new Queue<int>();
    public RecentCounter() {
        
    }
    
    public int Ping(int t) {
        if ( t > 3000)
        {
            var cutOff = t - 3000;
            while(pings.Count > 0 && pings.Peek() < cutOff)
            {
                pings.Dequeue();
            }
        }
        
        pings.Enqueue(t);
        return pings.Count;
    }
}