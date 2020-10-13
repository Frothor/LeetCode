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
var sortList = function(head) {
    if (!head) return null;
    var node = head;
    var count = 0;
    while (node) {
        node = node.next;
        count++;
    }
    var merge = function(node, n) {
        if (!n) return null;
        if (n === 1) return node;
        var leftCount = Math.floor(n / 2);
        var rightCount = n - leftCount;
        var rightNode = node;
        for (var i = 0; i < leftCount; i++) rightNode = rightNode.next;
        var leftNode = merge(node, leftCount);
        rightNode = merge(rightNode, rightCount);
        var resultFather = new ListNode();
        var cur = resultFather;
        while (leftCount && rightCount) {
            if (leftNode.val < rightNode.val) {
                cur.next = leftNode;
                leftNode = leftNode.next;
                leftCount--;
            } else {
                cur.next = rightNode;
                rightNode = rightNode.next;
                rightCount--;
            }
            cur = cur.next;
        }
        while (leftCount) {
            cur.next = leftNode;
            leftNode = leftNode.next;
            leftCount--;
            cur = cur.next;
        }
        while (rightCount){
            cur.next = rightNode;
            rightNode = rightNode.next;
            rightCount--;
            cur = cur.next;
        }
        cur.next = null;
        return resultFather.next;
    }
    return merge(head, count);
};

//Second fastest
const splitListAndGetMid = (head) => {
    let slow = head;
    let fast = head;
    
    while(fast && fast.next && fast.next.next) {
      fast = fast.next.next;
      slow = slow.next;
    }
    
    const mid = slow.next;
    slow.next = null;
    
    return mid;
  };
  
  const mergeList = (left, right) => {
    const temp = new ListNode();
    let result = temp;
    
    while(left || right) {
      if (!left) {
        result.next = right;
        right = right.next;
      } else if (!right) {
        result.next = left;
        left = left.next;
      } else if (left.val > right.val) {
        result.next = right;
        right = right.next;
      } else {
        result.next = left;
        left = left.next;
      }
      result = result.next;
    }
    
    
    return temp.next;
  };
  
  var sortList = function(head) {
    if (!head || !head.next) {
      return head;
    }
    
    const mid = splitListAndGetMid(head);
    
    const left = sortList(head);
    const right = sortList(mid);
    
    return mergeList(left, right);
  };

//Fastest
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
function sortList(h) {
    if (h === null || h.next === null) return h
    const [l, r] = split(h)
    return merge(new ListNode, sortList(l), sortList(r))
  }
  
  function split(node) {
    let l = node, r = node
    while (r.next && r.next.next) {
      l = l.next
      r = r.next.next
    }
    const left = node, right = l.next
    l.next = null
    return [left, right]
  }
  
  function merge(root, l, r) {
    let node = root
    while (l !== null || r !== null) {
      if (l === null) {
        node.next = r
        r = r.next
      } else if (r === null) {
        node.next = l
        l = l.next
      } else {
        if (l.val < r.val) {
          node.next = l
          l = l.next
        } else {
          node.next = r
          r = r.next
        }
      }
      node = node.next
    }
    return root.next
  }