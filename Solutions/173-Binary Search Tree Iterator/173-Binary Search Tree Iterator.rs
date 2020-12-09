//Third fastest
use std::rc::Rc;
use std::cell::RefCell;
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
struct BSTIterator {
    stack: Vec<Rc<RefCell<TreeNode>>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {

    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut stack = Vec::new();
        let mut head = root;
        
        while let Some(node) = head {
            stack.push(node.clone());
            head = node.borrow().left.clone();
        }
        
        BSTIterator {
            stack
        }
    }
    
    /** @return the next smallest number */
    fn next(&mut self) -> i32 {
        let node = self.stack.pop().unwrap();
        let val = node.borrow().val;
        let mut elem = node.borrow().right.clone();
        
        while let Some(e) = elem {
            self.stack.push(e.clone());
            elem = e.borrow().left.clone();
        }
        
        return val
    }
    
    /** @return whether we have a next smallest number */
    fn has_next(&self) -> bool {
        return self.stack.len() > 0
    }
    
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * let obj = BSTIterator::new(root);
 * let ret_1: i32 = obj.next();
 * let ret_2: bool = obj.has_next();
 */

//Second fastest
use std::rc::Rc;
use std::cell::RefCell;

struct TreeNodeStated {
    tree_node: Rc<RefCell<TreeNode>>,
    left_evalutated: bool    
} 

struct BSTIterator {
    stack: Vec<TreeNodeStated>
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {

    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        if root.is_some() {
            BSTIterator {
                stack: vec![TreeNodeStated { tree_node: Rc::clone(&root.unwrap()), left_evalutated: false }]
            }            
        } else {
            BSTIterator {
                stack: vec![]
            } 
        }             
    }
    
    fn next(&mut self) -> i32 {
        let mut cur_node = self.stack.pop().unwrap();
        if !cur_node.left_evalutated {
            self.stack.push(TreeNodeStated {
                tree_node: Rc::clone(&cur_node.tree_node),
                left_evalutated: true,
            });
            
            let mut cur_tree_node = Rc::clone(&cur_node.tree_node);
            while cur_tree_node.borrow().left.is_some() {        
                let left_node = {
                    let cur_node_ref = cur_tree_node.borrow();
                    let left_node = cur_node_ref.left.as_ref().unwrap();
                    Rc::clone(left_node)
                };
                self.stack.push(TreeNodeStated {
                    tree_node: Rc::clone(&left_node),
                    left_evalutated: true,
                });
                cur_tree_node = left_node;
            } 
            
            cur_node = self.stack.pop().unwrap();
        }              
        
        let result = cur_node.tree_node.borrow().val;
        
        if cur_node.tree_node.borrow().right.is_some() {
            let right_node = {
                let cur_node_ref = cur_node.tree_node.borrow();
                let right_node = cur_node_ref.right.as_ref().unwrap();
                Rc::clone(right_node)
            };
            self.stack.push(TreeNodeStated {
                tree_node: right_node,
                left_evalutated: false,
            });
        }
        
        result        
    }
    
    fn has_next(&self) -> bool {
        self.stack.len() > 0
    }
}

//Fastest
//https://leetcode.com/problems/binary-search-tree-iterator/discuss/653556/rust-'suicide'-traversal
use std::cell::RefCell;
use std::option::Option::Some;
use std::rc::Rc;

type TreeNodeType = Option<Rc<RefCell<TreeNode>>>;

#[derive(Debug)]
pub struct BSTIterator {
    stack: Vec<TreeNodeType>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {
    pub fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut stack = Vec::new();
        let mut cursor = root;

        while let Some(cursor_node) = cursor {
            cursor = cursor_node.borrow_mut().left.take();
            stack.push(Some(cursor_node));
        }

        BSTIterator { stack }
    }

    /** @return the next smallest number */
    #[allow(clippy::should_implement_trait)]
    pub fn next(&mut self) -> i32 {
        let node = self.stack.pop().unwrap().unwrap();
        let result = node.borrow().val;

        if node.borrow().right.is_some() {
            let mut cursor = node.borrow_mut().right.take();

            while let Some(cursor_node) = cursor {
                cursor = cursor_node.borrow_mut().left.take();
                self.stack.push(Some(cursor_node));
            }
        }

        result
    }

    /** @return whether we have a next smallest number */
    pub fn has_next(&self) -> bool {
        !self.stack.is_empty()
    }
}