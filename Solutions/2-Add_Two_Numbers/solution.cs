/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution
{
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
    {
        var headNode = new ListNode(0);
        var currentNode = headNode;
        
        var x = l1;
        var y = l2;
        var carry = 0;
        
        while (x != null || y != null)
        {
            int a = (x != null) ? x.val : 0;
            int b = (y != null) ? y.val : 0;
            
            var sum = carry + a + b;      
            carry = sum / 10;
            currentNode = currentNode.next = new ListNode(sum % 10);
            
            if (x != null) { x = x.next; }
            if (y != null) { y = y.next; }
        }
        
        // Check if there is still a value to carry over after finishing the loop
        if (carry == 1)
        { currentNode.next = new ListNode(1); }
        
        return headNode.next;
    }
}

// Another
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res = new ListNode(-1, null);
        ListNode first = res;
        int helper = 0;
        while(l1 != null || l2 != null){
            int currVal = ((l1?.val ?? 0) + (l2?.val ?? 0) + helper);
            res.val = currVal % 10;
                
            helper = currVal / 10;
            
            if(l1?.next != null || l2?.next != null || helper > 0){
                res.next = new ListNode(helper, null);
                res = res.next;
            }
            
            l1 = l1?.next;
            l2 = l2?.next;
        }
        
        return first;
    }
}

// Fastest
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        var temp = new ListNode(0);
        var dummy = temp;
        var carry=0;
        while(l1 != null || l2 != null || carry > 0)
        {
            var sum = 0;
            if(l1 != null)
            {
                sum += l1.val;
                l1 = l1.next;
            }
            
            if(l2 != null)
            {
                sum += l2.val;
                l2 = l2.next;
            }
            
            sum += carry;
            carry= 0;
            if(sum > 9)
            {
                carry = sum/10;
                sum = sum%10;
            }
            
            dummy.next = new ListNode(sum);
            dummy = dummy.next;
        }
        
        return temp.next;
    }
}