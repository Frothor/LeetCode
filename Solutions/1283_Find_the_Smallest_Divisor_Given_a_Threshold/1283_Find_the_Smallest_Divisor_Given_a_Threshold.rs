impl Solution {
    pub fn smallest_divisor(nums: Vec<i32>, threshold: i32) -> i32 {
        let (mut l, mut r) = (1, *nums.iter().max().unwrap());
        while l < r {
            let m = l + (r - l) / 2;
            let sum: i32 = nums
                .iter()
                .map(|&num| num / m + if num % m == 0 { 0 } else { 1 })
                .sum();
            if sum > threshold {
                l = m + 1;
            } else {
                r = m;
            }
        }
        l
    }
}