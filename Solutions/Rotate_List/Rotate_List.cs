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
public class Solution {
    public ListNode RotateRight(ListNode head, int k) {
        if(head == null || k < 0)
            return head;
        var last  = head;
        var n = 1;
        
        while(last.next != null){
            last = last.next;
            n++;
        }
        
        if(k%n == 0)
            return head;
        
        var middle = head;
        for(var i = 0; i < n - k%n - 1; i++)
            middle = middle.next;
        
        var newHead = middle.next;
        last.next = head;
        middle.next = null;
        return newHead;
    }
}

//Third fastest
public class Solution {
    public ListNode RotateRight(ListNode head, int k) {
        if (head==null || head.next==null||k==0){
            return head;
        }
        
        int counter = 0;
        ListNode temp = head;
        ListNode prev=null;
        
        while(temp!=null){
            counter++;
            temp=temp.next;
        }
        
        k=k%counter;
        while(k!=0){
            temp = head;
            while(temp.next!=null){
                prev = temp;
                temp=temp.next;
            }
            
            temp.next= head;
            prev.next=null;
            head=temp;
            k--;
        }
        return head;
    }
}

//Second fastest
public class Solution {
    public ListNode RotateRight(ListNode head, int k) {
        
        if( (head == null) || (head.next == null) || (k == 0)) return head;
        
        int count = 1;
        ListNode last = head;
        while(last.next != null){
            count++;
            last = last.next;
        }
        
        k %= count;
        if(k == 0) return head;
        
        ListNode listBreak = head;
        int breakCount = count - k - 1;
        for(int i = 0; i < breakCount; i++) listBreak = listBreak.next;
        
        last.next = head;
        ListNode newHead = listBreak.next;
        listBreak.next = null;
        
        return newHead;
    }
}

//Fastest
public class Solution {
    private int FindMaxDepth(ListNode head, int depth) {
        if (head.next == null)
            return depth;
        else
            return FindMaxDepth(head.next, depth + 1);
    }
    
    private ListNode NodeAtDepth(ListNode head, int soughtDepth, int depth) {
        if (depth == soughtDepth)
            return head;
        else
            return NodeAtDepth(head.next, soughtDepth, depth + 1);
    }
    
    public ListNode RotateRight(ListNode head, int k) {
        if (head == null)
            return null;
        
        int maxDepth = FindMaxDepth(head, 0);
        if (maxDepth == 0)
            return head;
        
        k = k % (maxDepth + 1);
        if (k == 0)
            return head;
        
        int kthFromEndParentDepth = maxDepth - k;
        ListNode kthFromEndParent = NodeAtDepth(head, kthFromEndParentDepth, 0);
        ListNode last = NodeAtDepth(kthFromEndParent, maxDepth, kthFromEndParentDepth);
        
        ListNode result = kthFromEndParent.next;
        kthFromEndParent.next = null;
        last.next = head;
        return result;
    }
}