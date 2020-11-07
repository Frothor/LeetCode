var addTwoNumbers = function(l1, l2) {
    const len1 = findLen(l1), len2 = findLen(l2);
    const diff = Math.abs(len1 - len2);
    if(len2 > len1) [l2, l1] = [l1, l2]; // l1 will always be the longest
    const result = new ListNode();
    result.val = run(l1, l2, result, diff);
    return result.val ? result : result.next;
    
    function findLen(node) {
        if(!node.next) return 0;
        return findLen(node.next) + 1;
    }
    
    function run(n1, n2, res, diff) {
        if(!n1) return 0;
        res.next = new ListNode();
        let sum = 0;
        if(diff > 0) sum += n1.val + run(n1.next, n2, res.next, diff-1);
        else sum += n1.val + n2.val + run(n1.next, n2.next, res.next, diff-1);
        res.next.val = sum % 10;
        return sum > 9;
    }
};

//Third fastest
var addTwoNumbers = function(l1, l2) {
    function reverse(node) {
        let prev = null;
        let current = node;
        let next;
        
        while (current !== null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    l1 = reverse(l1);
    l2 = reverse(l2);
    
    let carry = 0;
    let preHead = new ListNode(null);
    let current = preHead;
    
    while (l1 || l2) {
        let x = l1 === null ? 0 : l1.val;
        let y = l2 === null ? 0 : l2.val;
        let sum = x + y + carry;
        let value = sum % 10;

        current.next = new ListNode(value);
        carry = Math.floor(sum / 10);
        
        if (l1) {
            l1 = l1.next;
        }
        if (l2) {
            l2 = l2.next;
        }
        current = current.next;
    }
    
    if (carry) {
        current.next = new ListNode(carry);
    }
    
    let head = preHead.next;
    preHead.next = null;
    
    return reverse(head)
};

//Second fastest
var addTwoNumbers = function(l1, l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    
    let head = null;
    let carry = 0;
    let sum = 0;
    
    while(l1 !== null || l2!== null || carry != 0) {
        carry += l1!==null ? l1.val : 0;
        carry += l2!==null ? l2.val : 0;
        sum = carry%10;
        carry = Math.floor(carry/10);
        
        let current = new ListNode(sum);
        current.next = head;
        head = current;
        
        l1 = l1!==null ? l1.next : null;
        l2 = l2!==null ? l2.next : null;
    }
    
     // if (carry != 0) {
     //        let current = new ListNode(carry);
     //        current.next = head;
     //        head = current;
     //    }
    
    return head;
    
};


var reverseList = function(head) {
    let previous = null;
    
    while(head!=null) {
        let next = head.next;
        head.next = previous;
        previous = head;
        head = next;
    }
    return previous;  
};

//Fastest
const addTwoNumbers = function(l1, l2) {
    const getLen = (l) => {
      let res = 0;
      while (l) {
        res++;
        l = l.next;
      }
      return res;
    };
    
    const reverse = (cur) => {
      let prev = null;
      while (cur) {
        const next = cur.next;
        cur.next = prev;
        prev = cur;
        cur = next;
      }
      return prev;
    };
    
    let len1 = getLen(l1);
    let len2 = getLen(l2);
    
    let cur = null;
    while (len1 || len2) {
      let sum = 0;
      if (len1 > len2) {
        sum = l1.val;
        len1--;
        l1 = l1.next;
      } else if (len2 > len1) {
        sum = l2.val;
        len2--;
        l2 = l2.next;
      } else {
        sum = l1.val + l2.val;
        len1--;
        len2--;
        l1 = l1.next;
        l2 = l2.next;
      }
      const node = new ListNode(sum);
      node.next = cur;
      cur = node;
    }
    
    
    const revHead = cur;
    let prev = null;
    let rem = 0;
    while (cur) {
      const sum = cur.val + rem;
      cur.val = sum % 10;
      rem = Math.floor(sum / 10);
      prev = cur;
      cur = cur.next;
    }
    if (rem) prev.next = new ListNode(rem);
    
    return reverse(revHead);
  };