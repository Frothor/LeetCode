//Fastest
use rand::prelude::*;

struct Solution {
    len: usize,
    list: Option<Box<ListNode>>,
}

impl Solution {
    fn new(head: Option<Box<ListNode>>) -> Self {
        let mut cur = head.as_ref();
        let mut len = 0;
        while let Some(node) = cur {
            cur = node.next.as_ref();
            len += 1;
        }
        Self { len, list: head }
    }

    /** Returns a random node's value. */
    fn get_random(&self) -> i32 {
        if self.len == 0 {
            return -1;
        }
        if self.len == 1 {
            return self.list.as_ref().unwrap().val;
        }
        let mut rng = rand::thread_rng();
        let target = rng.gen_range(0, self.len);
        let mut cur = 0;
        let mut node = self.list.as_ref().unwrap();
        while cur < target {
            node = node.next.as_ref().unwrap();
            cur += 1;
        }
        node.val
    }
}

//Another
use rand::{thread_rng, Rng};
pub struct Solution {
    values: Vec<i32>,
}

impl Solution {
    /** @param head The linked list's head.
    Note that the head is guaranteed to be not null, so it contains at least one node. */
    fn new(head: Option<Box<ListNode>>) -> Self {
        let mut values = Vec::new();
        let mut node = head;
        while let Some(n) = node {
            values.push(n.val);
            node = n.next;
        }
        Self { values }
    }

    /** Returns a random node's value. */
    fn get_random(&self) -> i32 {
        let mut rng = thread_rng();
        self.values[rng.gen_range(0, self.values.len())]
    }
}