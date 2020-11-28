//Rust sliding window solution -> https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/949666/Rust-sliding-window-solution
impl Solution {
    pub fn longest_substring(s: String, k: i32) -> i32 {
        let s = s.as_bytes();
        let mut answer = 0;
        for i in 1..=26 {
            let mut dict = [0; 26];
            let (mut l, mut r) = (0, 0);
            let mut uniq = 0;
            let mut ok = 0;
            while r < s.len() {
                if uniq <= i {
                    let idx = (s[r] - b'a') as usize;
                    if dict[idx] == 0 {
                        uniq += 1;
                    }
                    dict[idx] += 1;
                    if dict[idx] == k {
                        ok += 1;
                    }
                    r += 1;
                } else {
                    let idx = (s[l] - b'a') as usize;
                    if dict[idx] == k {
                        ok -= 1;
                    }
                    dict[idx] -= 1;
                    if dict[idx] == 0 {
                        uniq -= 1;
                    }
                    l += 1;
                }
                if uniq == i && uniq == ok {
                    answer = std::cmp::max(answer, r - l)
                }
            }
        }
        answer as i32
    }
}

//Another
use std::collections::VecDeque;

const FROM_CHAR: usize = 'a' as usize;

impl Solution {
    pub fn longest_substring(s: String, k: i32) -> i32 {
        let k = k as usize;
        if s.len() < k {
            return 0;
        }

        // BFS each substring
        let mut queue = VecDeque::with_capacity(64);
        queue.push_back(s.as_ref());

        // init result
        let mut max = 0;

        // walk each substring
        let mut counter = vec![0; 26];
        while let Some(t) = queue.pop_front() {
            // reset counter (count char occurrence)
            counter.iter_mut().for_each(|v| *v = 0);

            // count char occurrence of t
            Solution::count_char(t, &mut counter);

            let mut from = 0;
            t.chars().enumerate().for_each(|(index, ch)| {
                // should not include this character?
                if counter[ch as usize - FROM_CHAR] < k {
                    if from < index && index - from >= k {
                        queue.push_back(t[from..index].as_ref());
                    }
                    from = index + 1;
                }
            });

            if from == 0 {
                max = max.max(t.len());
            } else if from < t.len() && t.len() - from >= k {
                queue.push_back(t[from..].as_ref())
            }
        }

        max as i32
    }

    pub fn count_char(s: &str, counter: &mut [usize]) {
        s.chars().for_each(|ch| {
            counter[ch as usize - FROM_CHAR] += 1;
        });
    }
}