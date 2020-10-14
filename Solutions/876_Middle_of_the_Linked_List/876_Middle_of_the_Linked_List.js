//Second fastest
var middleNode = function(head) {
    let list = []
    
    while(head!=null){
        list.push(head);
        head = head.next;
    }
    
    let res = Math.floor(list.length/2)
    return list[res]
}

//Fastest
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNode = function(head) {
    var slow = head, fast = head;
    
    while (fast && fast.next) {
        fast = fast.next.next;
        slow = slow.next;
    }
    
    return slow;
};