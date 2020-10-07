var rotateRight = function (head, k) {
  let len = findLen(head);
  k %= len;
  if (!k) return head;

  function findLen(node) {
    if (!node) return 0;
    return findLen(node.next) + 1;
  }

  function rotate(node, newHead, idx) {
    if (!node.next) {
      node.next = head;
      return newHead;
    }
    if (!idx) {
      const temp = node.next;
      node.next = null;
      return rotate(temp, temp, idx - 1);
    }
    return rotate(node.next, newHead, idx - 1);
  }
  return rotate(head, null, len - k - 1);
};

//Faster
var rotateRight = function (head, k) {
  let count = 0, cur = head;
  while (cur) {
    cur = cur.next;
    count++;
  }

  k %= count;
  if (k === 0) {
    return head;
  }

  let dummy = new ListNode(0, head);
  let tail = dummy;
  cur = dummy;

  for (let i = 0; i < k; i++) {
    tail = tail.next;
  }

  while (tail.next) {
    cur = cur.next;
    tail = tail.next;
  }

  const newHead = cur.next;
  tail.next = head;
  cur.next = null;
  return newHead;
};
