/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    
    curr := head
    n := 1
    
    for curr.Next != nil {
        curr = curr.Next
        n++;
    }
    
    curr.Next = head
    
    k = k % n
    m := n - k - 1
    
    for m > 0 {
        head = head.Next
        m--
    }
    
    newHead = head.Next
    head.Next = nil
    
    return newHead
    
}

//Another
func rotateRight(head *ListNode, k int) *ListNode {
    if head == nil || head.Next == nil { return head }
    i, p := 1, head
    for ; p.Next != nil; p = p.Next { i++ }
    k %= i
    if k == 0 { return head }
    p.Next = head
    for i -= k + 1; i != 0; i-- { head = head.Next }
    p, head.Next = head.Next, nil
    return p
}