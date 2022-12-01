use std::cmp;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut max_len: i32 = 0;
        let mut head: i32 = 0;
        let mut index: Vec<i32> = vec![0; 128];
        
        for (j, c) in s.chars().enumerate() {
            let tail = j as i32;
            let i = (c as u32) as usize;
            head = cmp::max(index[i], head);
            max_len = cmp::max(max_len, tail + 1 - head);
            index[i] = (tail + 1) as i32;
        }
        max_len
    }
}

// Another fastest
use std::cmp;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut sequence_start = 0;
        let mut max_sequence_len = 0;
        
        for current_index in 0..s.len() { 
            let sequence = &s[sequence_start..current_index];
            
            match sequence.find(&s[current_index..current_index + 1]) {
                Some(char_match) => sequence_start += char_match + 1,
                None => max_sequence_len = cmp::max(max_sequence_len, sequence.len() + 1),
            }
        }
        
        return max_sequence_len as i32;
    }
}