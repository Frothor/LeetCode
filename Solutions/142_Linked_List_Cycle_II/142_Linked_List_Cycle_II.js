var detectCycle = function(head) {
    let visited = new Set();
    let node = head;
    while (node !== null){
        if(visited.has(node)) {
            // found the start point of the cycle
            return node
        }
        visited.add(node)
        node = node.next
    }
    return null
};

//Fourth fastest
var detectCycle = function(head) {
    if (!head) return null
    
    let slow = head
    let fast = head
    
    while (fast && fast.next){
        slow = slow.next
        fast = fast.next.next
        
        if (slow == fast) break
    }
    
    if (!fast || !fast.next) return null
    
    fast = head
    
    while(slow != fast) {
        slow = slow.next
        fast = fast.next
    }
    
    return fast
};

//Third fastest
var detectCycle = function(head) {
    let fast = head
    let slow = head
    while (fast && fast.next) {
      fast = fast.next.next
      slow = slow.next
      if (fast === slow) {
        slow = head
        while (fast !== slow) {
          fast = fast.next
          slow = slow.next
        }
        return slow
      }
    }
  return null
};

//Second fastest
var detectCycle = function(head) {
 
    let fast = head
      let slow = head
      while (fast && fast.next) {
        fast = fast.next.next
        slow = slow.next
        if (fast === slow) {
          slow = head
          while (fast !== slow) {
            fast = fast.next
            slow = slow.next
          }
          return slow
        }
      }
    return null
  };

//Fastest
var detectCycle = function(head) {    
    let slow = head;
    let fast = head;
    
    while(fast && fast.next && fast.next.next) {
        slow = slow.next;
        fast = fast.next.next;
        
        if(slow === fast) {
            slow = head;
            
            while(slow !== fast) {
                slow = slow.next;
                fast = fast.next;
            }
            
            return slow;
        }
    }
    
    
    return null;
};