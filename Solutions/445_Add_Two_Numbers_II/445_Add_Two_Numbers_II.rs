//Second fastest
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
        let mut v1 = Solution::list2vec(&l1);
        let mut v2 = Solution::list2vec(&l2);
        v1.reverse();
        v2.reverse();
        let mut next = None;
        let mut carry = 0;
        for i in 0..=std::cmp::max(v1.len(), v2.len()) {
            let mut val =
                carry + if i < v1.len() { v1[i] } else { 0 } + if i < v2.len() { v2[i] } else { 0 };
            carry = if val > 9 {
                val -= 10;
                1
            } else {
                0
            };
            if i < std::cmp::max(v1.len(), v2.len()) || val != 0 {
                next = Some(Box::new(ListNode { val, next }));
            }
        }
        next
    }
    fn list2vec(list: &Option<Box<ListNode>>) -> Vec<i32> {
        if list.is_none() {
            return vec![0];
        }
        let mut ret = Vec::new();
        let mut node = list;
        while let Some(n) = node {
            ret.push(n.val);
            node = &n.next;
        }
        ret
    }
}

//Another
impl Solution {
    fn get_digits(l: Option<Box<ListNode>>) -> Vec<i32> {
        let mut current_node = l;
        let mut digits = vec![];
        while let Some(node) = current_node {
            digits.push(node.val);
            current_node = node.next;
        }
        digits
    }
    fn get_sum_lsd(v1: Vec<i32>, v2: Vec<i32>) -> Vec<i32> {
        let mut v_1 = v1;
        let mut v_2 = v2;
        let mut digit_1 = v_1.pop();
        let mut digit_2 = v_2.pop();
        let mut sum_digits = vec![];
        let mut carry = false;
        while digit_1.is_some() || digit_2.is_some() {
            let (v1, v2);
            if digit_1.is_some() {
                v1 = digit_1.unwrap();
            } else{
                v1 = 0;
            }
            if digit_2.is_some() {
                v2 = digit_2.unwrap();
            } else{
                v2 = 0;
            }
            let mut sum = v1 + v2;
            if carry {
                sum += 1;
                carry = false;
            }
            if sum > 9 {
                sum = sum % 10;
                carry = true;
            }
            sum_digits.push(sum);
            digit_1 = v_1.pop();
            digit_2 = v_2.pop();
        }
        if carry {
            sum_digits.push(1);
        }
        sum_digits
    }
    fn list_from_vec(mut v: Vec<i32>) -> Box<ListNode> {
        let mut list = Box::new(ListNode::new(v.pop().unwrap()));
        let mut node = &mut list;
        while let Some(value) = v.pop() {
            node.next = Some(Box::new(ListNode::new(value)));
            node = node.next.as_mut().unwrap();
        }
        list
    }
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut digits_1 = Solution::get_digits(l1);
        let mut digits_2 = Solution::get_digits(l2);
        let mut sum = Solution::get_sum_lsd(digits_1, digits_2);
        println!("{:?}", sum);
        Some(Solution::list_from_vec(sum))
        
    }
}

//Fastest
impl Solution {
    fn get_digits(l: Option<Box<ListNode>>) -> Vec<i32> {
        let mut current_node = l;
        let mut digits = vec![];
        while let Some(node) = current_node {
            digits.push(node.val);
            current_node = node.next;
        }
        digits
    }
    fn get_sum_lsd(v1: Vec<i32>, v2: Vec<i32>) -> Vec<i32> {
        let mut v_1 = v1;
        let mut v_2 = v2;
        let mut digit_1 = v_1.pop();
        let mut digit_2 = v_2.pop();
        let mut sum_digits = vec![];
        let mut carry = false;
        while digit_1.is_some() || digit_2.is_some() {
            let (v1, v2);
            if digit_1.is_some() {
                v1 = digit_1.unwrap();
            } else{
                v1 = 0;
            }
            if digit_2.is_some() {
                v2 = digit_2.unwrap();
            } else{
                v2 = 0;
            }
            let mut sum = v1 + v2;
            if carry {
                sum += 1;
                carry = false;
            }
            if sum > 9 {
                sum = sum % 10;
                carry = true;
            }
            sum_digits.push(sum);
            digit_1 = v_1.pop();
            digit_2 = v_2.pop();
        }
        if carry {
            sum_digits.push(1);
        }
        sum_digits
    }
    fn list_from_vec(mut v: Vec<i32>) -> Box<ListNode> {
        let mut list = Box::new(ListNode::new(v.pop().unwrap()));
        let mut node = &mut list;
        while let Some(value) = v.pop() {
            node.next = Some(Box::new(ListNode::new(value)));
            node = node.next.as_mut().unwrap();
        }
        list
    }
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut digits_1 = Solution::get_digits(l1);
        let mut digits_2 = Solution::get_digits(l2);
        let mut sum = Solution::get_sum_lsd(digits_1, digits_2);
        Some(Solution::list_from_vec(sum))
        
    }
}