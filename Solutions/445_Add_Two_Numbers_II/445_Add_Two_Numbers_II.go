func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	l1Stack := sliceFromList(l1)
	l2Stack := sliceFromList(l2)

	l1Len, l2Len := len(l1Stack), len(l2Stack)
	if l1Len < l2Len {
		l1Stack, l2Stack = l2Stack, l1Stack
		l1Len, l2Len = l2Len, l1Len
	}

	carry := 0
	var pre *ListNode
	i := l1Len - 1
	for j := l2Len - 1; j >= 0; i, j = i-1, j-1 {
		carry, pre = sumToList(carry, l1Stack[i], l2Stack[j], pre)
	}

	for ; i >= 0; i-- {
		carry, pre = sumToList(carry, l1Stack[i], 0, pre)
	}

	if carry != 0 {
		cur := &ListNode{}
		cur.Next = pre
		cur.Val = carry
		pre = cur
	}

	return pre
}

func sumToList(carry int, i int, j int, pre *ListNode) (int, *ListNode) {
	cur := &ListNode{}
	cur.Next = pre
	cur.Val = (i + j + carry)
	carry = cur.Val / 10
	cur.Val %= 10
	pre = cur
	return carry, pre
}

func sliceFromList(list *ListNode) []int {
	slice := make([]int, 0)
	for iter := list; iter != nil; iter = iter.Next {
		slice = append(slice, iter.Val)
	}
	return slice
}

//Second fastest
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    return reverse(add(reverse(l1), reverse(l2)))
}

func reverse(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    prev := head
    curr := head.Next
    prev.Next = nil
    for curr != nil {
        next := curr.Next
        curr.Next = prev
        
        prev = curr
        curr = next
    }
    
    return prev
}

func add(l1, l2 *ListNode) *ListNode {
    if l1 == nil { return l2 }
    if l2 == nil { return l1 }
    carry := 0
    head := l1
    for l1 != nil && l2 != nil {
        l1.Val += l2.Val + carry
        if l1.Val > 9 {
            l1.Val -= 10
            carry = 1
        } else {
            carry = 0
        }
        l1, l2 = l1.Next, l2.Next
    }
    if l1 == nil && l2 == nil {
        if carry == 1 {
            p := head
            for p.Next != nil {
                p = p.Next
            }
            p.Next = &ListNode{Val: 1}
        }
    } else if l1 == nil {
        p := head
        for p.Next != nil {
            p = p.Next
        }
        p.Next = l2
        for l2 != nil {
            l2.Val += carry
            if l2.Val > 9 {
                l2.Val -= 10
                carry = 1
            } else {
                carry = 0
            }
            l2 = l2.Next
        }
        if carry == 1 {
            for p.Next != nil {
                p = p.Next
            }
            p.Next = &ListNode{Val: 1}
        }
    } else {
        for l1 != nil {
            l1.Val += carry
            if l1.Val > 9 {
                l1.Val -= 10
                carry = 1
            } else {
                carry = 0
            }
            l1 = l1.Next
        }   
        if carry == 1 {
            p := head
            for p.Next != nil {
                p = p.Next
            }
            p.Next = &ListNode{Val: 1}
        }        
    }
    
    return head
}

//Fastest
type Queue struct {
	Head *ListNode
	Tail *ListNode
}

func (queue *Queue) Enqueue(val int) {
	listNode := &ListNode{
		Val: val,
	}

	if queue.Head == nil {
		queue.Head = listNode
	} else if queue.Tail != nil {
		queue.Tail.Next = listNode
	}

	queue.Tail = listNode
}

func (queue *Queue) Dequeue() (int, error) {
	if queue.Head == nil {
		return 0, errors.New("empty queue")
	}

	resVal := queue.Head.Val
	queue.Head = queue.Head.Next
	return resVal, nil
}

type Stack struct {
	Head *ListNode
	Length int
}

func (stack *Stack) Pop() (int, error) {
	if stack.Head != nil {
		val := stack.Head.Val
		stack.Head = stack.Head.Next
		stack.Length--
		return val, nil
	}
	return 0, errors.New("empty stack")
}

func (stack *Stack) Push(val int) {
	listNode := &ListNode{
		Val:  val,
	}
	if stack.Head != nil {
		listNode.Next = stack.Head
	}

	stack.Head = listNode

	stack.Length++
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	s1 := listToStack(l1)
	s2 := listToStack(l2)
	maxStack := max(s1, s2)

	resultStack := &Stack{}

	carryOver := 0

	for maxStack.Head != nil || carryOver != 0  {
		s2Val, err := s2.Pop()
		if err != nil {
			s2Val = 0
		}

		s1Val, err := s1.Pop()
		if err != nil {
			s1Val = 0
		}

		newVal := s1Val + s2Val + carryOver

		if newVal > 9 {
			carryOver = newVal / 10
			newVal -= carryOver * 10
		} else if carryOver != 0 {
			carryOver = 0
		}

		resultStack.Push(newVal)
	}

	resultQueue := &Queue{}

	for resultStack.Head != nil {
		val, _ := resultStack.Pop()
		resultQueue.Enqueue(val)
	}

	return resultQueue.Head
}

func max(s1 *Stack, s2 *Stack) *Stack {
	if s1.Length < s2.Length {
		return s2
	}
	return s1
}

func listToStack(listNode *ListNode) *Stack {
	result := &Stack{}

	for listNode != nil {
		result.Push(listNode.Val)
		listNode = listNode.Next
	}
	return result
}