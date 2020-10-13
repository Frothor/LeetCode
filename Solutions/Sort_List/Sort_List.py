class Solution:
    def sortList(self, head):
        if not head or not head.next: return head
        mid = self.getMid(head)
        left = self.sortList(head)
        right = self.sortList(mid)
        return self.merge(left, right)
    
    def getMid(self, head):
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        mid = slow.next
        slow.next = None
        return mid
    
    def merge(self, head1, head2):
        dummy = tail = ListNode(None)
        while head1 and head2:
            if head1.val < head2.val:
                tail.next, tail, head1 = head1, head1, head1.next
            else:
                tail.next, tail, head2 = head2, head2, head2.next
    
        tail.next = head1 or head2
        return dummy.next

#Third fastest
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        p = head
        node_list = []
        while head:
            node_list.append(head.val)
            head = head.next

        node_list.sort()
        head = p
        for i in node_list:
            head.val = i
            head = head.next

        return p


#Second fastest
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        p = head
        node_list = []
        while head:
            node_list.append(head.val)
            head = head.next

        node_list.sort()
        head = p
        for i in node_list:
            head.val = i
            head = head.next

        return p

#Fastest
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        elems = []
        
        curr = head
        while curr:
            elems.append(curr.val)
            curr = curr.next
        
        elems.sort()
        
        curr = head
        for n in elems:
            curr.val = n
            curr = curr.next
        
        return head