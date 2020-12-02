//Third fastest
public class Solution {

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode _head;
    Random rand;
    public Solution(ListNode head) {
        _head = head;
        rand = new Random();
    }
    
    /** Returns a random node's value. */
    public int GetRandom() {
        ListNode node = _head;
        int op = node.val;
        
        int i = 0;
        while(node != null)
        {
            if(rand.Next(i+1) == i)    
            {
                op = node.val; 
            }
            node = node.next;
            i++;
        }
        
        return op;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.GetRandom();
 */

//Second fastest
public class Solution {

    static Random rand = new Random();
    ListNode head;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        this.head = head;
    }
    
    /** Returns a random node's value. */
    public int GetRandom() {
        int i = 1; 
        int valueToReturn = head.val;
        var tempHead = head;
        while(tempHead.next != null)
        {
            i++;
            tempHead = tempHead.next;
            var generatedValue = rand.Next(0,i);
            
            if (generatedValue == 0)
            {
                valueToReturn = tempHead.val;
            }
        }
        
        return valueToReturn;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.GetRandom();
 */

//Fastest
    public class Solution
        {
            private ListNode head;

            private Random rand;

            /** @param head The linked list's head.
                Note that the head is guaranteed to be not null, so it contains at least one node. */
            public Solution(ListNode head)
            {
                this.head = head;
                this.rand = new Random();
            }

                                   public int GetRandom()
            {
                 int selected = this.head.val, count = 1;
                ListNode cur = this.head.next;
                while (cur != null)
                {
                    count++;
                    if (rand.Next(count) % count == 0)
                    {
                        selected = cur.val;
                    }
                    cur = cur.next;
                }
                return selected;;
            }

        }