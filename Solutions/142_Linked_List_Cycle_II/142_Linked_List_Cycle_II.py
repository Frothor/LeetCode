# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        slow = fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if slow == fast: break
        
        if not fast or not fast.next: return None
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        
        return slow

#Fourth fastest
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head:
            return None
        
        seen = set()
        curr = head
        
        while curr is not None:
            if curr in seen:
                return curr
            seen.add(curr)
            curr = curr.next
        
        return None

#Third fastest
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head:
            return None
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break
        if not fast or not fast.next:
            return None
        second_slow = head
        while second_slow != slow:
            second_slow = second_slow.next
            slow = slow.next
        return slow

#Second fastest
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        fast = slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return self.find_cycle(head, slow)
        return None
    
    def find_cycle(self, head, slow):
        while head != slow:
            head = head.next
            slow = slow.next
        else:
            return head

#Fastest
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        visited = set()
        tail = head
        while tail:
            if tail.next in visited:
                return tail.next
            visited.add(tail)
            tail = tail.next
        return None