/*
LeetCode LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );
/*
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
*/

public class LRUCache {
    private int capacity;
    private int count;
    Dictionary<int, LRUNode> map;
	LRUDoubleLinkedList doubleLinkedList;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        count = 0;
        map = new Dictionary<int, LRUNode>();
        doubleLinkedList = new LRUDoubleLinkedList();
    }
    
    public int Get(int key) {
        if (!map.ContainsKey(key)) return -1;
		LRUNode node = map[key];
		doubleLinkedList.RemoveNode(node);
		doubleLinkedList.AddToTop(node);
		return node.Value;
    }
    
    public void Put(int key, int value) {
        if (map.ContainsKey(key))
			{
				LRUNode node = map[key];
				doubleLinkedList.RemoveNode(node);
				node.Value = value;
				doubleLinkedList.AddToTop(node);
			}
			else
			{
				if (count==capacity) {
					LRUNode lru = doubleLinkedList.RemoveLRUNode();
					map.Remove(lru.Key);
					count--;
				}

				LRUNode node = new LRUNode(key, value);
				doubleLinkedList.AddToTop(node);
				map[key] = node;
				count++;
			}
    }
}

public class LRUNode
	{
		public int Key { get; set; }
		public int Value { get; set; }
		public LRUNode Previous { get; set; }
		public LRUNode Next { get; set; }
		public LRUNode(){}
		public LRUNode(int k, int v)
		{
			this.Key = k;
			this.Value = v;
		}
	}

public class LRUDoubleLinkedList
	{
		private LRUNode Head;
		private LRUNode Tail;

		public LRUDoubleLinkedList()
		{
			Head = new LRUNode();
			Tail = new LRUNode();
			Head.Next = Tail;
			Tail.Previous = Head;
		}

		public void AddToTop(LRUNode node) {
			node.Next = Head.Next;
			Head.Next.Previous = node;
			node.Previous = Head;
			Head.Next = node;
		}

		public void RemoveNode(LRUNode node) {
			node.Previous.Next = node.Next;
			node.Next.Previous = node.Previous;
			node.Next = null;
			node.Previous = null;
		}

		public LRUNode RemoveLRUNode() {
			LRUNode target = Tail.Previous;
			RemoveNode(target);
			return target;
		}
	}


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */



 /*
 ANOTHER SOLUTION
public class LRUCache {

    public class ListNode {
    
        public int key {get; set;}
        public int val {get; set;}
        public ListNode prev {get; set;}
        public ListNode next {get; set;}
        
        public ListNode(int key, int val) {
            this.key = key;
            this.val = val;
        }
    }
    
    /*
    use linked list with dictionary
    
    *** capacity 2 ***
    
    put (1,1)
    
    <1,1> => null
    
    put (2, 2)
    
    <2,2> => <1,1>
    
    get (1)
    
    <1,1> => <2,2> => null  (add <1,1> to head, tail <1,1> is removed)
    
    put (3, 3)  -- evict key 2
    
    <3,3> => <1,1> => null (add <3,3> to head, tail <2,2> is removed)
    
    get (2) -- not found, return -1
    
    <3,3> => <1,1>
    
    put (4, 4) -- evict key 1
    
    <4,4> => <3,3> => null  (add <4,4> to head, tail <1,1> is removed)
    
    get (1) -- return -1 not found
    
    get (3)
    
    <3,3> => <4,4> => null (add <3,3> to head, tail <3,3> is removed)
    
    get (4)
    
    <4,4> => <3,3> => null (add 3,3 to head, tail <3,3> is removed)
    
    */
    
    private int cap;
    private int currentCap;
    private ListNode head = new ListNode(-1, -1);
    private ListNode tail = new ListNode(-1, -1);
    
    private Dictionary<int, ListNode> dic;
    
    //constructor
    public LRUCache(int capacity) {
        
        currentCap = 0;
        cap = capacity;
        dic = new Dictionary<int, ListNode>();
        
        head.next = tail;
        tail.prev = head;
    }
    
    private void RemoveNode(ListNode node) {
        
        var n1 = node.prev;
        var n2 = node.next;
        n1.next = n2;
        n2.prev = n1;
        
    }
    
    private void AddToHead(ListNode node) {
        
        //add node right after head
        node.prev = head;
        node.next = head.next;
        
        head.next.prev = node;
        head.next = node;
        
    }
    
    private void RemoveFromTail() {
        
        dic.Remove(tail.prev.key);
        
        var node = tail.prev;
        var newTail = node.prev;
        newTail.next = tail;
        tail.prev = newTail;

    }
    
    public int Get(int key) {
        
        if(dic.ContainsKey(key)) {
            
            var node = dic[key];
            
            RemoveNode(node);
            AddToHead(node);
            
            return node.val;
        }
        else {
            return -1; //not found
        }
    }
    
    public void Put(int key, int value) {
        
        
        if(dic.ContainsKey(key)) {
            
            //if already exists, remove from current position and attach to head
            
            var node = dic[key];
            node.val = value; //need update value
            
            RemoveNode(node);
            AddToHead(node);  
        }
        else {
            //new item. Add to dic and node to head
            var newNode = new ListNode(key, value);
            
            AddToHead(newNode);
            dic.Add(key, newNode);
            
            if(currentCap == cap) {
                
                //evict tail
                RemoveFromTail();
                currentCap --;
            }
            
            currentCap ++;
        }
    }
}



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */
 */


 /*
 ANOTHER SOLUTION
public class LRUCache {
    private class Entry {
        public Entry(int k, int v) => (key, value) = (k, v);
        public Entry prev;
        public Entry next;
        public int value;
        public int key;
    }
    
    private int cap, size = 0;
    private Entry head, tail;
    private Dictionary<int, Entry> map = new Dictionary<int, Entry>();
    
    public LRUCache(int capacity) { cap = capacity; }
    
    public int Get(int key) {
        if (map.ContainsKey(key)) {
            var e = map[key];
            MoveToHead(e);
            return e.value;
        }
        return -1;
    }
    
    public void Put(int key, int value) {
        if (map.ContainsKey(key)) {
            var e = map[key];
            e.value = value;
            MoveToHead(e);
        } else {
            var e = new Entry(key, value);
            AddToHead(e);
            map[key] = e;
            size++;
        }

        if (size <= cap) return;
        
        map.Remove(tail.key);
        RemoveFromTail();
        size--;
    }
    
    private void AddToHead(Entry e) {
        if (head == null)  { head = tail = e; return; }
        
        head.next = e;
        e.prev = head;
        head = e;
    }
    
    private void RemoveFromTail() {
        var r = tail;
        tail = tail.next;
        tail.prev = null;
        r.next = null;
    }
    
    private void MoveToHead(Entry e) {
        if (e == head) return;
        if (e == tail) tail = tail.next;
                
        if (e.next != null) e.next.prev = e.prev;
        if (e.prev != null) e.prev.next = e.next;
        
        e.next = null;
        e.prev = head;
        head.next = e;
        head = e;
    }
}
 */