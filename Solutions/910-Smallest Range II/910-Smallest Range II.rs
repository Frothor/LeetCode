//https://leetcode.com/problems/smallest-range-ii/discuss/486896/Rust
impl Solution {
    pub fn smallest_range_ii(a: Vec<i32>, k: i32) -> i32 {
    let mut a = a;
    a.sort();
    let n = a.len();
    let mut ans = a[n - 1] - a[0];
    for i in 0..n - 1 {
        let (x, y) = (a[i], a[i + 1]);
        let high = std::cmp::max(a[n - 1] - k, x + k);
        let low = std::cmp::min(a[0] + k, y - k);
        ans = std::cmp::min(ans, high - low);
    }
    ans
}
}