//https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/948526/Rust-solution
impl Solution {
    pub fn smallest_repunit_div_by_k(k: i32) -> i32 {
        let mut m = 0;
        for i in 1..=k {
            m = (m * 10 + 1) % k;
            if m == 0 {
                return i;
            }
        }
        -1
    }
}