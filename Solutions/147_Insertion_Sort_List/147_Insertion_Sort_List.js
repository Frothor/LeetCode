var insertionSortList = function(head) {
    let newHead = new ListNode(0)
    while(head){
        const t = head
        head = head.next
        let cur = newHead
        while(cur){
            if(!cur.next || t.val <= cur.next.val){
                [cur.next, t.next] = [t, cur.next]
                break
            }
            cur = cur.next
        }
    }
    return newHead.next
};

//Third fastest
var insertionSortList = function(head) {
    if (head === null) return head;
    let dummy = {};
    dummy.next = head;
    let tail = head;
    while (tail.next != null) {
        if (tail.next.val >= tail.val) {
            tail = tail.next;
        } else {
            let target = tail.next;
            let prev = dummy;
            while (prev.next.val < target.val) {
                prev = prev.next;
            }
            tail.next = target.next;
            target.next = prev.next;
            prev.next = target;
        }
    }
    return dummy.next;
};

//Second fastest
var insertionSortList = function(head) {
    const dummy = new ListNode(0);
    dummy.next = head;
    let head0 = dummy.next;
    
    while(head0 && head0.next){
        if(head0.next.val >= head0.val){
            head0 = head0.next;
            continue;
        }
        let pre = dummy;
        while(pre.next.val < head0.next.val){
            pre = pre.next;
        }
        let next = head0.next;
        head0.next = next.next;
        next.next = pre.next;
        pre.next = next;
    }
    return dummy.next;
};

//Fastest
function  insertionSortList(head) {
    if (head === null || head.next === null)  return head 
    
    
    let prev= head 
    let cur=head.next 
    while(cur!==null) {
        if (cur.val<prev.val) {
            prev.next = cur.next
            head= insert(cur, head)
            cur=prev.next
        }else {
            prev=cur
            cur=cur.next 
        }
    }
    
    return head 
}

function insert(node, head) {

    if (node.val<head.val) {
         node.next = head 
         return  node
    }
    
    let prev = head
    let cur=head.next
    while(node.val>=cur.val) {
        prev=cur
        cur=cur.next
    }
    
    prev.next = node 
    node.next = cur
    
    return head 
}