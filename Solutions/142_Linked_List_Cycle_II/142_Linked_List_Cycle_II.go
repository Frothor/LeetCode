//Second fastest
func detectCycle(head *ListNode) *ListNode {
    slow, fast := head, head
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
        if slow == fast {
            break
        }
    }
    
    if fast == nil || fast.Next == nil {
        return nil
    }
    
    slow = head
    for slow != fast {
        slow = slow.Next
        fast = fast.Next
    }
    return fast
}


//Fastest
func detectCycle(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    
    intersectNode:= findIntersect(head)
    
    if intersectNode == nil {
        return nil
    }
    
    ptr1,ptr2:= head, intersectNode
    
    for ptr1!= ptr2 {
        ptr1 = ptr1.Next
        ptr2 = ptr2.Next
    }
    
    return ptr1
}

func findIntersect(head *ListNode) *ListNode {

    slow, fast:= head, head
    for fast!=nil && fast.Next!=nil {
        slow = slow.Next
        fast = fast.Next.Next
        if(slow == fast) {
            return slow
        }
    }
    
    return nil
}