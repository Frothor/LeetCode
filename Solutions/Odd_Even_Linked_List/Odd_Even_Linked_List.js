/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var oddEvenList = function(head) {
   const evenHead = new ListNode();
    const oddHead = new ListNode();
    
    let cur = head;
    let evenCur = evenHead;
    let oddCur = oddHead;
    let counter = 1;
    while(cur){
       if(counter % 2 === 0){
           evenCur.next = cur;
           evenCur = cur;
       } else {
           oddCur.next = cur;
           oddCur = cur;
       }
       cur = cur.next; 
       counter++; 
    }
    
    oddCur.next = evenHead.next;
    evenCur.next = null;
    
    return oddHead.next;
};