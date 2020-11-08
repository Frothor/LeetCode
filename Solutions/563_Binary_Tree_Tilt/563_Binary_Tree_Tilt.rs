//Second fastest
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn find_tilt(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        find_tilt_rec(&root).1
    }
}

/*
I return a tuple containing (0) the sum the tree from root down, and
(1) the tilt of the whole tree beneath root.
*/
fn find_tilt_rec(root: &Option<Rc<RefCell<TreeNode>>>) -> (i32, i32) {
    match root {
        None => (0, 0),
        Some(rc_node) => {
            let node = rc_node.borrow();
            let left_ret = find_tilt_rec(&node.left);
            let right_ret = find_tilt_rec(&node.right);

            (left_ret.0 + right_ret.0 + node.val, left_ret.1 + right_ret.1 + (left_ret.0 - right_ret.0).abs())
        }
    }
}

//Fastest
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
    pub fn find_tilt(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut s = 0;
        Self::h(&root, &mut s);
        s
    }

    fn h(n: &Option<Rc<RefCell<TreeNode>>>, s: &mut i32) -> i32 {
        if let Some(n) = n {
            let n = n.borrow();
            let l = Self::h(&n.left, s);
            let r = Self::h(&n.right, s);
            *s += (l - r).abs();
            n.val + l + r
        } else {
            0
        }
    }
}