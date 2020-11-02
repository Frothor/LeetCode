class Solution:
    def insertionSortList(self, head):
        dummy = ListNode(-1)
        curr = head
        while curr:
            curr_next = curr.next
            prv, nxt = dummy, dummy.next
            while nxt:
                if nxt.val > curr.val: break
                prv = nxt
                nxt = nxt.next
                
            curr.next = nxt
            prv.next = curr
            curr = curr_next
        
        return dummy.next

#Most common
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        
        dummy = ListNode(0, head)
        tail = head
        
        while tail.next:
            insert_node = tail.next
            
            if tail.val <= insert_node.val:
                tail = tail.next
            else:
                tail.next = insert_node.next

                temp = dummy
                while temp.next.val < insert_node.val:
                    temp = temp.next
            
                insert_node.next = temp.next
                temp.next = insert_node
            
                # tail = tail.next
        return dummy.next

#Third fastest
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        node_list = []
        while head:
            node_list.append(ListNode(head.val))
            head = head.next
        
        def output_val(node):
            return node.val
        node_list.sort(key = output_val)
        
        for i, item in enumerate(node_list):
            item.next = node_list[i+1] if i<len(node_list)-1 else None
        return node_list[0]

#Second fastest
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        nodeDict=[]
        res = pre = ListNode(0)
        while head:
            nodeDict.append([head.val,head])
            head = head.next
        sortedDict = sorted(nodeDict,key=(lambda x:x[0]))
        for key, value in sortedDict:
            pre.next = value
            pre = pre.next
        pre.next = None
        return res.next
        

#Fastest
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        
        li = []
        
        work = head
        while work:
            li.append(work.val)
            work = work.next
            
        li.sort()
        
        work = head
        
        for i in range(len(li)):
            work.val = li[i]
            work = work.next
            
        return head