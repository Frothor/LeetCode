//https://leetcode.com/problems/house-robber-iii/discuss/946391/Rust-dfs-solution
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
    pub fn rob(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let ret = Solution::dfs(&root);
        std::cmp::max(ret.0, ret.1)
    }
    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>) -> (i32, i32) {
        if let Some(n) = node {
            let l = Solution::dfs(&n.borrow().left);
            let r = Solution::dfs(&n.borrow().right);
            (
                n.borrow().val + l.1 + r.1,
                std::cmp::max(l.0, l.1) + std::cmp::max(r.0, r.1),
            )
        } else {
            (0, 0)
        }
    }
}

//Another
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>) -> (i32, i32) {
        if let Some(r_node) = root {
            let n = r_node.borrow();
            let left = Self::dfs(&n.left);
            let right = Self::dfs(&n.right);
            
            // (
            //     n.val + left.1 + right.1,
            //     std::cmp::max(left.0, left.1) + std::cmp::max(right.0, right.1)
            // )
            (
                std::cmp::max(n.val + left.1 + right.1, left.0 + right.0),
                left.0 + right.0
            )
        } else {
            (0, 0)
        }
    }
    
    pub fn rob(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let res = Self::dfs(&root);
        
        // std::cmp::max(res.0, res.1)
        res.0
    }
}