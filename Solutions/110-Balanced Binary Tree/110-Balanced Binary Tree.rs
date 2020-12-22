//Second
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
use std::cmp;
impl Solution {
    fn max_depth(node: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match node {
            None => 0,
            Some(node) => {
                1 + cmp::max(
                    Self::max_depth(&node.borrow().left),
                    Self::max_depth(&node.borrow().right)
                )
            },
        }
    }
    
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        return match root {
            None => true,
            Some(node) => {
                let mut node_borrowed = node.borrow_mut();
                (Self::max_depth(&node_borrowed.left) - 
                    Self::max_depth(&node_borrowed.right)).abs() < 2 &&
                    Self::is_balanced(node_borrowed.left.take()) &&
                    Self::is_balanced(node_borrowed.right.take())
            },
        }
    }
}
//Most space efficient
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
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    #[allow(dead_code)]
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::balanced_height(&root) != -1
    }
    fn balanced_height(root: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root.as_ref() {
            Some(rrr) => {
                let rb = rrr.borrow();
                let hl = Self::balanced_height(&rb.left);
                if hl == -1 {
                    return -1;
                }
                let hr = Self::balanced_height(&rb.right);
                if hr == -1 || hl > hr + 1 || hr > hl + 1 {
                    -1
                } else {
                    if hl > hr {
                        1 + hl
                    } else {
                        1 + hr
                    }
                }
            }
            None => 0,
        }
    }
}