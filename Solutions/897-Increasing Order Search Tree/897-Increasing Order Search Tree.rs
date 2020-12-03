//Fastest
//https://leetcode.com/problems/increasing-order-search-tree/discuss/556967/rust-(0ms)
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn increasing_bst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(node) = root.clone() {
            let mut vals = Solution::walk(root.clone());
            vals.reverse();
            let fst = vals.pop().unwrap();
            *node.borrow_mut() = TreeNode::new(fst);
            node.borrow_mut().right = Solution::inc_bst(vals)
        }
        root
    }

    fn inc_bst(mut vals: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        if vals.is_empty() {
            return None;
        }
        let v = vals.pop().unwrap();
        let node = Rc::new(RefCell::new(TreeNode::new(v)));
        node.borrow_mut().right = Solution::inc_bst(vals);
        Some(node)
    }

    fn walk(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut vals: Vec<i32> = vec![];
        if let Some(node) = root {
            let node = node.borrow();
            vals.extend(Solution::walk(node.left.clone()));
            vals.push(node.val);
            vals.extend(Solution::walk(node.right.clone()));
        }
        vals
    }
}

//Another
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    // 中序遍历，每次访问的节点作为上一次访问节点的right
    pub fn increasing_bst(
        mut root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let mut new_root = None;
        let mut parent: Option<Rc<RefCell<TreeNode>>> = None;
        let mut stack = Vec::with_capacity(32);
        while !stack.is_empty() || root.is_some() {
            while root.is_some() {
                let node = root.unwrap();
                root = node.borrow_mut().left.take();
                stack.push(node);
            }
            root = stack.pop();
            if new_root.is_none() {
                // 第一次遍历到最左的叶子节点，这个节点的值是最小的，作为根节点。
                new_root = root.clone();
            }
            if let Some(p) = parent {
                p.borrow_mut().right = root.clone();
            }
            parent = root.clone();
            let node = root.unwrap();
            root = node.borrow_mut().right.take();
        }
        new_root
    }
}