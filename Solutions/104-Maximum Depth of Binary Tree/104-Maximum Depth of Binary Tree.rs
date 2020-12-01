//Second most space optimal
use std::cell::RefCell;
use std::cmp;
use std::rc::Rc;
impl Solution {
    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn depth(root: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
            match root {
                Some(node) => 1 + cmp::max(depth(&node.borrow().left), depth(&node.borrow().right)),
                None => 0,
            }
        }

        depth(&root)
    }
}

//Most space optimal
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
    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_level = 0;

        preorder_traserval(&root, 0, &mut max_level);

        max_level
    }
}

fn preorder_traserval(root: &Option<Rc<RefCell<TreeNode>>>, level: i32, max_level: &mut i32) {
    if let Some(tree_node) = root {
        let tree_node = tree_node.borrow();

        if *max_level < level + 1 {
            *max_level = level + 1
        }

        preorder_traserval(&tree_node.left, level + 1, max_level);
        preorder_traserval(&tree_node.right, level + 1, max_level);
    }
}