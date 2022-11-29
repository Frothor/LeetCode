// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        add(l1, l2, 0)
    }
}


fn add(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>, carry: i32) -> Option<Box<ListNode>> {
    let mut sum = carry;
    let next1 = if let Some(node1) = l1 {
        sum += node1.val;
        node1.next
    } else {
        None
    };
    let next2 = if let Some(node2) = l2 {
        sum += node2.val;
        node2.next
    } else {
        None
    };
    
    let mut sum_node = ListNode::new(
        sum % 10,
    );
    if next1 != None || next2 != None || sum >= 10 {
        sum_node.next = add(next1, next2, sum / 10);
    }
    Some(Box::new(sum_node))
}

// Third fastest
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut result: Option<Box<ListNode>> = None;
        let mut curr = &mut result;

        let mut p1 = l1;
        let mut p2 = l2;

        let mut carry = 0;
        while p1.is_some() || p2.is_some() || carry != 0 {
            if let Some(node) = p1 {
                carry += node.val;
                p1 = node.next;
            }

            if let Some(node) = p2 {
                carry += node.val;
                p2 = node.next;
            }

            let new_node = Some(Box::new(ListNode {
                val: carry % 10,
                next: None,
            }));

            if let Some(node) = curr {
                node.next = new_node;
                curr = &mut node.next;
            } else {
                result = new_node;
                curr = &mut result;
            }

            carry /= 10;
        }

        result  
    }
}


// Second fastest
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if l1 == None {
            return l2;
        }

        if l2 == None {
            return l1;
        }
    let mut s1 = &l1;
    let mut s2 = &l2;

    let mut result: Option<Box<ListNode>> = None;
    let mut node = None;
    let mut carry = 0;
    let mut sum = 0;
    let mut tail = &mut result;

    while s1.is_some() && s2.is_some() {
         sum = s1.as_ref().unwrap().val + s2.as_ref().unwrap().val + carry;
        carry = sum / 10;
        sum = sum % 10;
 
        node = Some(Box::new(ListNode::new(sum)));

        *tail = node; //tail.as_mut().unwrap().next = node;
        tail = &mut (tail.as_mut().unwrap().next);
 
        s1 = &(s1.as_ref().unwrap().next);
        s2 = &(s2.as_ref().unwrap().next);
    }
        

        let mut s = if s1.is_some() { s1 } else {s2};
        while s.is_some()  {
         sum = s.as_ref().unwrap().val + carry;
        carry = sum / 10;
        sum = sum % 10;
 
        node = Some(Box::new(ListNode::new(sum)));

        *tail = node;
        tail = &mut (tail.as_mut().unwrap().next);


 
        s = &(s.as_ref().unwrap().next);
    }
        
        if carry != 0 {
                    node = Some(Box::new(ListNode::new(carry)));
                   *tail = node;
                     tail = &mut (tail.as_mut().unwrap().next);
        }

     result 

    }
}

// Fastest
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        return Self:: add_lists(&l1, &l2, 0);
    }

    fn add_lists(l1: &Option<Box<ListNode>>, l2: &Option<Box<ListNode>>, carry: i32) -> Option<Box<ListNode>> {
        match (l1, l2, carry) {
            (None, None, 0) => None,
            (None, None, c) => Some(Box::new(ListNode::new(c))),
            (Some(l), None, _) | (None, Some(l), _) => {
                let sum = l.val+carry;
                Some(Box::new(ListNode{val: sum%10, next: Self::add_lists(&l.next,&None,sum/10)}))},
            (Some(l1), Some(l2), _) => {
                let sum = l1.val+l2.val+carry;
                Some(Box::new(ListNode{val: sum%10, next: Self::add_lists(&l1.next,&l2.next,sum/10)}))}
        }
    }

   
}