/*
(Ordered) Map extension O(1) and easy to understand. (LinkedHashMap/Queue)
LRU cache is basically an ordered HashMap with a capacity limit.

For JavaScript, the Map datastructure keeps the insertion order, similar to Java's LinkedHashMap. So, that's all we need. We can handle it like a Queue, we insert to the end and remove from the begining of the list. Also, we need to move elements to the end of the list when they are read or overwritten.

Algorithm:

PUT: Every time we put a value, it will naturally go to the end of the list.
PUT: If the value already exits we need to delete it from wherever it was and put it to the end.
PUT: When doing a put, we check the capacity. If are over the limit, we delete the first element.
GET: When we read a value, we have to move it from wherever it was an put it to the end.
GET: If the value doesn't exists, return -1;
Implementation:
*/

class LRUCache extends Map<number, any> {
  capacity: number;
  constructor(capacity: number) {
    super();
    this.capacity = capacity;
  }

  get(key: number): number {
    if (super.has(key)) {
      const value = super.get(key);
      super.delete(key);
      super.set(key, value);
      return value;
    }
    return -1;
  }

  put(key: number, value: number): void {
    if (super.has(key)) super.delete(key); // move it to the end if it exits
    super.set(key, value);
    if (super.size > this.capacity) super.delete(super.keys().next().value); // delete first
  }
}

//Another
function Node(key, value) {
  this.value = value || 0;
  this.key = key || 0;
  this.prev = null;
  this.next = null;
}

/**
 * @param {number} capacity
 */
var LRUCache = function (capacity) {
  this.capacity = capacity;
  this.headDummy = new Node();
  this.tailDummy = new Node();
  this.count = 0;
  this.map = new Map();
  this.headDummy.next = this.tailDummy;
  this.tailDummy.prev = this.headDummy;
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function (key) {
  var node = this.map.get(key);
  if (node) {
    var prev = node.prev;
    var next = node.next;
    prev.next = next;
    next.prev = prev;
    prev = this.headDummy;
    next = this.headDummy.next;
    prev.next = node;
    node.next = next;
    next.prev = node;
    node.prev = prev;
    return node.value;
  }
  return -1;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function (key, value) {
  var node = this.map.get(key);
  if (node) {
    this.count--;
    var prev = node.prev;
    var next = node.next;
    prev.next = next;
    next.prev = prev;
    this.map.delete(key);
  } else if (this.count === this.capacity) {
    node = this.tailDummy.prev;
    var prev = node.prev;
    var next = node.next;
    prev.next = next;
    next.prev = prev;
    this.count--;
    this.map.delete(node.key);
  }
  node = new Node(key, value);
  this.map.set(key, node);
  var prev = this.headDummy;
  var next = this.headDummy.next;
  prev.next = node;
  node.next = next;
  next.prev = node;
  node.prev = prev;
  this.count++;
};

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
