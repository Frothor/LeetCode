//C# - Divide and Conquer Merge Sort
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
    public ListNode SortList(ListNode head) 
{
	if(head == null || head.next == null)
	{
		return head;
	}

	ListNode slow = head;
	ListNode fast = head;
	ListNode previous = null;

	while(fast != null && fast.next != null)
	{
		previous = slow;
		fast = fast.next.next;
		slow = slow.next;
	}

	previous.next = null;

	var left = SortList(head);
	var right = SortList(slow);

	var sortedHead =  mergeList(left, right);
	return sortedHead;
}

private ListNode mergeList(ListNode head1, ListNode head2)
{        
	ListNode dummy = new ListNode(0);
	ListNode newHead = dummy;

	while(head1 != null && head2 != null)
	{
		if(head1.val < head2.val)
		{
			newHead.next = head1;
			newHead = head1;
			head1 = head1.next;
		}
		else
		{
			newHead.next = head2;
			newHead = head2;
			head2 = head2.next;
		}
	}

	if(head1 != null)
	{
		newHead.next = head1;
	}
	else
	{
		newHead.next = head2;
	}

	return dummy.next;
}
}

//Little faster
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
    public ListNode SortList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode slow = head;
        ListNode fast = head;
        ListNode temp = head;
        
        while(fast != null && fast.next != null){
            temp = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        
        temp.next = null;
        
        ListNode left = SortList(head);
        ListNode right = SortList(slow);
        
        return mergeSortedList(left, right);
        
    }
    
    public ListNode mergeSortedList(ListNode head1, ListNode head2){
        ListNode dummHead = new ListNode(0);
        ListNode curNode = dummHead;
        
        while(head1 != null && head2 != null){
            if(head1.val < head2.val){
                curNode.next = head1;
                curNode = curNode.next;
                head1 = head1.next;
            }
            else{
                curNode.next = head2;
                curNode = curNode.next;
                head2 = head2.next;
            }
        }
        
        if(head1 != null){
            while(head1 != null){
                curNode.next = head1;
                curNode = curNode.next;
                head1 = head1.next;
            }
        }
        
        if(head2 != null){
            while(head2 != null){
                curNode.next = head2;
                curNode = curNode.next;
                head2 = head2.next;
            }
        }
        
        return dummHead.next;
    }
}