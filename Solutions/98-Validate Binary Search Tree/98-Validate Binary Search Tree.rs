/ Definition for a binary tree node.
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
    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut stack = Vec::new();
        
        let mut previous = None;
        let mut cursor = root;
        
        while cursor.is_some() || !stack.is_empty() {
            while let Some(node) = cursor {
                cursor = node.borrow().left.clone();
                stack.push(node);
            }
            
            cursor = stack.pop();
            let cursor_val = cursor.as_ref().unwrap().borrow().val;
            
            if let Some(prev_val) = previous {
                if prev_val >= cursor_val {
                    return false;
                }
            }
            previous = Some(cursor_val);
            cursor = cursor.and_then(|current| {
                current.borrow().right.clone()
            });
        }
        true
    }
}

//Another
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::valid(root, std::i64::MIN, std::i64::MAX)
    }

    fn valid(node: Option<Rc<RefCell<TreeNode>>>, min: i64, max: i64) -> bool {
        if let Some(node) = node {
            if node.borrow().val as i64 <= min || node.borrow().val as i64 >= max {
                return false;
            }
            return Self::valid(node.borrow().left.clone(), min, node.borrow().val as i64) &&
                Self::valid(node.borrow().right.clone(), node.borrow().val as i64, max);
        }
        true
    }
}