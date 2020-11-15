//Second fastest
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, l: i32, r: i32) -> i32 {
        if let Some(root) = root {
            let mut sum = 0;
            if l <= root.borrow().val && root.borrow().val <=r {
                sum += root.borrow().val;
            }
            
            if l < root.borrow().val {
                sum += Self::range_sum_bst(root.borrow().left.clone(), l, r);
            }
            
            if r > root.borrow().val {
                sum += Self::range_sum_bst(root.borrow().right.clone(), l, r);
            }
            return sum;
        }
        return 0;
    }
}

//Another
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {
        match root {
            None => { 0 }
            Some(node) => {
                let node1 = Rc::try_unwrap(node).unwrap().into_inner();
                let left = Solution::range_sum_bst(node1.left, low, high);
                let right = Solution::range_sum_bst(node1.right, low, high);
                let current = if (low <= node1.val) && (node1.val <= high) { node1.val} else {0};
                left + right + current
            }
        }
    }
}

//Fastest
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, l: i32, r: i32) -> i32 {
        if root.is_none() {
            return 0;
        }
        let node_rc = root.unwrap();
        let node = node_rc.borrow();
        if node.val < l {
            return Solution::range_sum_bst(node.right.clone(), l, r);
        } else if node.val > r {
            return Solution::range_sum_bst(node.left.clone(), l, r);
        }
        node.val + Solution::range_sum_bst(node.right.clone(), l, r) +  Solution::range_sum_bst(node.left.clone(), l, r)
    }
}