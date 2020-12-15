//Second fastest
//https://leetcode.com/problems/squares-of-a-sorted-array/discuss/330513/Rust-8ms-100
impl Solution {
    pub fn sorted_squares(a: Vec<i32>) -> Vec<i32> {
        let mut left = 0;
        let mut right = a.len() - 1;
        
        let mut ret = vec![];
        while left < right {
            let l = a[left];
            let r = a[right];
            if l.abs() < r.abs() {
                ret.push(r * r);
                right -= 1;
            } else {
                ret.push(l * l);
                left += 1;
            }
        }
        ret.push(a[left] * a[right]); // should point to the same element
        ret.into_iter().rev().collect()
    }
}

//Another
impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let mut res: Vec<i32> = nums.into_iter().map(|a| a.pow(2)).collect();
        res.sort();
        res
    }
}

//Fastest
impl Solution {
    pub fn sorted_squares(a: Vec<i32>) -> Vec<i32> {
        let mut b= Vec::new();
        for n in a{
            b.push(n*n)
        }
        b.sort();
        return b;
    }
}