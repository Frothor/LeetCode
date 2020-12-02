//Third fastest
//https://leetcode.com/problems/linked-list-random-node/discuss/665399/Simple-Go-golang-solution-100
type Solution struct {
    list []int
}


/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
func Constructor(head *ListNode) Solution {
    var res Solution
    for head != nil {
        res.list = append(res.list, head.Val)
        head = head.Next
    }
    return res
}


/** Returns a random node's value. */
func (this *Solution) GetRandom() int {
    if len((*this).list) == 0 {
        return -1
    }
    return (*this).list[rand.Intn(len((*this).list))]
}

//Second fastest
import "math/rand"
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
type Solution struct {
    arr []int
}


/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
func Constructor(head *ListNode) Solution {
        tmp := head
        lisarr := Solution{}
        for tmp != nil {
                lisarr.arr = append(lisarr.arr, tmp.Val)
                tmp = tmp.Next
        }
        return lisarr
}


/** Returns a random node's value. */
func (this *Solution) GetRandom() int {
    val := rand.Intn(len(this.arr))
    return this.arr[val]
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(head);
 * param_1 := obj.GetRandom();
 */

//Fastest
type Solution struct {
    head *ListNode
}


/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
func Constructor(head *ListNode) Solution {
    return Solution{head}
}


/** Returns a random node's value. */
func (this *Solution) GetRandom() int {
    n := 0
    chosen := -1
    for node := this.head; node != nil; node = node.Next {
        n++
        if p := rand.Intn(n); p == 0 {
            chosen = node.Val
        }
    }
    return chosen
}