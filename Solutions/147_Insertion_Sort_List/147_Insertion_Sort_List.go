func insertionSortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    result := &ListNode{Next: head}
    cur := head.Next
    head.Next = nil
    
    for cur != nil {
        pre := result
        target := result.Next
        for target != nil && cur.Val > target.Val {
            target = target.Next
            pre = pre.Next
        }
        temp := cur
        cur = cur.Next
        temp.Next = target
        pre.Next = temp
    }
    
    return result.Next
}

//Fourth fastest
func insertionSortList(head *ListNode) *ListNode {
    if head == nil {
        return head
    }
    var arr []int
    
    for head != nil {
        arr = append(arr, head.Val)
        head = head.Next
    }
    for i := 1; i < len(arr); i++ {
        for j := i; j > 0; j-- {
            if arr[j] > arr[j-1] {
                break
            }
            arr[j-1], arr[j] = arr[j], arr[j-1]
        }
    }
    
    head2 := &ListNode{arr[0], nil}
    prev := head2
    
    for i := 1; i < len(arr); i++ {
        next := &ListNode{arr[i], nil}
        prev.Next = next
        prev = next
    }
    
    return head2
}

//Third fastest
func insertionSortList(head *ListNode) *ListNode {
    
    if(head == nil) {
        return nil
    }
    
    curr:=head.Next
    prev:= head
    
    for (curr!=nil) {
        
        if (curr.Val < prev.Val) {
            prev.Next = curr.Next
            
            var prev2 *ListNode
            curr2 := head
            
            for (curr2!=nil) {
                if (curr2.Val > curr.Val) {
                    curr.Next = curr2
                    if(prev2 != nil) {
                        prev2.Next = curr
                    }else {
                        head = curr
                    }
                    break
                }else {
                    prev2 =curr2
                    curr2=curr2.Next
                }
                
                
            }
            curr = prev.Next
            
        } else {
            prev = curr
            curr = curr.Next
        }
        
    }
    return head
}

//Second fastest
func insertionSortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    
    dummy := &ListNode{Next:head}
    cur := head
    for cur != nil && cur.Next != nil {
        next := cur.Next        
        if cur.Val > next.Val {            
            iter := dummy
            for iter.Next != nil && iter.Next.Val < next.Val {
                iter = iter.Next
            }
            cur.Next = next.Next
            next.Next = iter.Next
            iter.Next = next
        } else {
            cur = next
        }
    }
    return dummy.Next
}

//Fastest
func insertionSortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    
    dummy := &ListNode{Next:head}
    cur := head
    for cur != nil && cur.Next != nil {
        next := cur.Next        
        if cur.Val > next.Val {            
            iter := dummy
            for iter.Next != nil && iter.Next.Val < next.Val {
                iter = iter.Next
            }
            cur.Next = next.Next
            next.Next = iter.Next
            iter.Next = next
        } else {
            cur = next
        }
    }
    return dummy.Next
}