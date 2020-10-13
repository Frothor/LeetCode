//Second fastest
func sortList(head *ListNode) *ListNode {
    n := count(head)
    if n <= 1 {
        return head
    }
    dummy := &ListNode{0, head}
    for l := 1; l < n; l *= 2 { // 2*l is the size you want to merge into
        tail := dummy
        for i := 0; i < n; i += 2*l {
            leftHead := tail.Next
            rightHead := split(leftHead, l)
            nextHead := split(rightHead, l)
            for leftHead != nil || rightHead != nil {
                if rightHead == nil || (leftHead != nil && leftHead.Val <= rightHead.Val) {
                    tail.Next = leftHead
                    leftHead = leftHead.Next
                } else {
                    tail.Next = rightHead
                    rightHead = rightHead.Next
                }
                tail = tail.Next
            }
            tail.Next = nextHead
        }
    }
    return dummy.Next
}

func count(head *ListNode) int {
    count := 0
    for head != nil {
        count++
        head = head.Next
    }
    return count
}

func split(head *ListNode, l int) *ListNode {
    for i := 1; i < l && head != nil; i++ {
        head = head.Next
    }
    var next *ListNode
    if head != nil {
        next = head.Next
        head.Next = nil
    }
    return next
}


func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

func MarshalJSON(head ListNode) ([]byte, error) {
    output := make([]int, 0)
    for node := &head; node != nil; node = node.Next {
        output = append(output, node.Val)
    }
    return json.Marshal(output)
}

func UnmarshalJSON(head *ListNode, b []byte) error {
    var nums []int
    if err := json.Unmarshal(b, &nums); err != nil {
        return err
    }
    i := 0
    if len(nums) > 0 {
        *head = ListNode{nums[i], nil}
        i++
    }
    prev := head
    for i < len(nums) {
        prev.Next = &ListNode{nums[i], nil}
        i++
        prev = prev.Next
    }
    return nil
}

func String(head *ListNode) string {
    blob, _ := MarshalJSON(*head)
    return string(blob)
}

func Copy(head *ListNode) *ListNode {
    blob, _ := MarshalJSON(*head)
    output := &ListNode{0, nil} // dummy output
    UnmarshalJSON(output, blob)
    return output
}

//Fastest
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func sortList(head *ListNode) *ListNode {
	lessHead := &ListNode{}
	lessTail := lessHead
	equalHead := &ListNode{}
	equalTail := equalHead
	moreHead := &ListNode{}
	moreTail := moreHead
	curNode := head
    
	for curNode != nil {
		if curNode.Val < head.Val {
			lessTail.Next = curNode
			lessTail = curNode
		} else if curNode.Val > head.Val {
			moreTail.Next = curNode
			moreTail = curNode
		} else {
			equalTail.Next = curNode
			equalTail = curNode
		}
        
		curNode = curNode.Next
	}

	lessTail.Next = nil
	equalTail.Next = nil
	moreTail.Next = nil

	if lessHead != lessTail {
		lessHead.Next = sortList(lessHead.Next)
        
		// lessTail probably no longer be real tail
		// we need reassignment it, this is a key point
		for lessTail.Next != nil {
			lessTail = lessTail.Next
		}
	}

	if moreHead != moreTail {
		moreHead.Next = sortList(moreHead.Next)
	}

	lessTail.Next = equalHead.Next
	equalTail.Next = moreHead.Next
	return lessHead.Next
}