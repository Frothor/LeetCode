#Third fastest
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow

#Second Fastest
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slow = head
        fast = head
        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next
        return slow 

#Fastest
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        fast_ptr = head
        slow_ptr = head
        while fast_ptr is not None:
            try:
                fast_ptr = fast_ptr.next.next
                slow_ptr = slow_ptr.next
            except:
                return slow_ptr
        return slow_ptr