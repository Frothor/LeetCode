//https://leetcode.com/problems/decoded-string-at-index/discuss/979621/Rust-Stack-Encoding-and-reduction
impl Solution {
    pub fn decode_at_index(s: String, k: i32) -> String {
        let mut stack = vec![(0, String::new())];
        let mut k = k as i64;
        let mut cur_len: i64 = 0;
        for c in s.chars() {
            match c {
                c if c.is_digit(10) => {
                    let d = c.to_digit(10).unwrap();
                    let i = stack.len() - 1;
                    cur_len *= d as i64;
                    if stack[i].1.is_empty() {
                        stack[i].0 *= d as i64;    
                    } else {
                        stack.push((cur_len, String::new()));
                    }
                }
                _ => {
                    let i = stack.len() - 1;
                    stack[i].1.push(c);
                    cur_len += 1;
                }
            }
            if cur_len >= k {
                break;
            }
        }
        while let Some((old_len, s2)) = stack.pop() {
            if k > old_len {
                let index = (k - old_len - 1) as usize;
                return s2.chars().nth(index).unwrap().to_string();
            } else {
                let i = stack.len() - 1;
                let p_len = stack[i].0 + (stack[i].1.len() as i64);
                k = ((k-1) % p_len) + 1;
            }
            
        }
        String::from("Fail")
    }
}