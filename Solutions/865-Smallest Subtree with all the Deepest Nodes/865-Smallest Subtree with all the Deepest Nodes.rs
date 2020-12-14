//https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/discuss/906976/Rust-0ms-100
use std::cell::RefCell;
use std::rc::Rc;

///
/// get "Pointer" of a Tree Node
fn to_rc(root: &Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
    match root {
        Some(ref node) => Some(Rc::clone(node)),
        None => None,
    }
}

struct Result {
    node: Option<Rc<RefCell<TreeNode>>>,
    dist: i32,
}

impl Solution {
    pub fn subtree_with_all_deepest(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        use std::cmp::Ordering;
        fn dfs(root: &Option<Rc<RefCell<TreeNode>>>) -> Result {
            return match root {
                Some(node) => {
                    let n = node.borrow();
                    let left = dfs(&n.left);
                    let right = dfs(&n.right);
                    match left.dist.cmp(&right.dist) {
                        Ordering::Greater => Result {
                            node: left.node,
                            dist: left.dist + 1,
                        },
                        Ordering::Less => Result {
                            node: right.node,
                            dist: right.dist + 1,
                        },
                        _ => Result {
                            node: Some(Rc::clone(node)),
                            dist: left.dist + 1,
                        },
                    }
                }
                None => Result {
                    node: None,
                    dist: 0,
                },
            };
        }
        dfs(&root).node
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_subtree_with_all_deepest() {
        let expected = Some(Rc::new(RefCell::new(TreeNode {
            val: 2,
            left: Some(Rc::new(RefCell::new(TreeNode::new(7)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(4)))),
        })));
        let root = Some(Rc::new(RefCell::new(TreeNode {
            val: 3,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 5,
                left: Some(Rc::new(RefCell::new(TreeNode::new(6)))),
                right: to_rc(&expected),
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: Some(Rc::new(RefCell::new(TreeNode::new(0)))),
                right: Some(Rc::new(RefCell::new(TreeNode::new(8)))),
            }))),
        })));
        assert_eq!(Solution::subtree_with_all_deepest(root), expected);
    }
}

//Another
use std::cell::RefCell;
use std::rc::Rc;

///
/// get "Pointer" of a Tree Node
fn to_rc(root: &Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
    match root {
        Some(ref node) => Some(Rc::clone(node)),
        None => None,
    }
}

struct Result {
    node: Option<Rc<RefCell<TreeNode>>>,
    dist: i32,
}

impl Solution {
    pub fn subtree_with_all_deepest(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        use std::cmp::Ordering;
        fn dfs(root: &Option<Rc<RefCell<TreeNode>>>) -> Result {
            return match root {
                Some(node) => {
                    let n = node.borrow();
                    let left = dfs(&n.left);
                    let right = dfs(&n.right);
                    match left.dist.cmp(&right.dist) {
                        Ordering::Greater => Result {
                            node: left.node,
                            dist: left.dist + 1,
                        },
                        Ordering::Less => Result {
                            node: right.node,
                            dist: right.dist + 1,
                        },
                        _ => Result {
                            node: Some(Rc::clone(node)),
                            dist: left.dist + 1,
                        },
                    }
                }
                None => Result {
                    node: None,
                    dist: 0,
                },
            };
        }
        dfs(&root).node
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_subtree_with_all_deepest() {
        let expected = Some(Rc::new(RefCell::new(TreeNode {
            val: 2,
            left: Some(Rc::new(RefCell::new(TreeNode::new(7)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(4)))),
        })));
        let root = Some(Rc::new(RefCell::new(TreeNode {
            val: 3,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 5,
                left: Some(Rc::new(RefCell::new(TreeNode::new(6)))),
                right: to_rc(&expected),
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: Some(Rc::new(RefCell::new(TreeNode::new(0)))),
                right: Some(Rc::new(RefCell::new(TreeNode::new(8)))),
            }))),
        })));
        assert_eq!(Solution::subtree_with_all_deepest(root), expected);
    }
}