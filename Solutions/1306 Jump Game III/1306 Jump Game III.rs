//Second fastest
//https://leetcode.com/problems/jump-game-iii/discuss/596408/Rust-BFS-4ms-100-Time-and-Space
use std::collections::LinkedList;

impl Solution {
    pub fn can_reach(arr: Vec<i32>, start: i32) -> bool {
        let mut visited = vec![false; arr.len()];

        let mut queue: LinkedList<usize> = LinkedList::new();
        queue.push_back(start as usize);

        while let Some(idx) = queue.pop_front() {
            if visited[idx] {
                continue;
            }

            visited[idx] = true;

            if idx as i32 - arr[idx] >= 0 {
                queue.push_back(idx - arr[idx] as usize);
            }

            if arr[idx] as usize + idx < arr.len() {
                queue.push_back(idx + arr[idx] as usize);
            }
        }

        arr.into_iter()
            .enumerate()
            .filter(|&(_, num)| num == 0)
            .any(|(index, _)| visited[index])
    }
}

//Fastest
impl Solution {
    pub fn can_reach(arr: Vec<i32>, start: i32) -> bool {
        let mut queue = vec![start];
        let mut seen = vec![false;arr.len()];
        while let Some(i) = queue.pop() {
            if arr[i as usize] == 0 {
                return true
            }
            seen[i as usize] = true;
            let l = i - arr[i as usize];
            let r = i + arr[i as usize];
            if l >= 0 && !seen[l as usize] {

                queue.push(l)

            }


            if r < arr.len() as i32 && !seen[r as usize] {
                queue.push(r)
            }
        }
        false
    }
}