//Third fastest
var Solution = function(head) {
       this.head = head
};
Solution.prototype.getRandom = function() {
       let i = 2;
       let cur = this.head.next;
       let val = this.head.val;
       while(cur) {
              const ratio = 1/i
              if(Math.random() <= ratio ) val = cur.val;
              i++;
              cur = cur.next;
       }
       return val;
};

//Another
class Solution {
    constructor(head) {
        this.head = head;
    }
    
    getRandom() {
        let current = this.head;
        let nodeCount = 0;
        let randomVal = null;
        
        while (current !== null) {
            nodeCount++;
            
            if (Math.floor(Math.random() * nodeCount) === 0) {
                randomVal = current.val;
            }
            
            current = current.next;
        }
        
        return randomVal;
    }
}


//Second fastest
var Solution = function(head) {
    this.root = head;
    var curr = head, count = 0;
    while (curr) {
      curr = curr.next;
      count++;
    }
    this.count = count;
  };
  
  /**
   * Returns a random node's value.
   * @return {number}
   */
  Solution.prototype.getRandom = function() {
    var rand = Math.floor(Math.random() * this.count);
    var res = this.root;
    while (rand) {
      res = res.next;
      rand--;
    }
    return res.val;
  };

//Fastest
var Solution = function(head) {
    this.head = head;
    this.len = 1;
    while (head.next) {
        this.len++;
        head = head.next;
    }
    head.next = this.head;
};

/**
 * Returns a random node's value.
 * @return {number}
 */
Solution.prototype.getRandom = function() {
    let i = (Math.random() * this.len) >> 0;
    while(i--)  this.head = this.head.next;
    return this.head.val;
};