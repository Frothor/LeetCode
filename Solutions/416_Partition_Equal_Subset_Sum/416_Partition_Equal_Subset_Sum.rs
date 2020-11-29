//https://leetcode.com/problems/partition-equal-subset-sum/discuss/950920/Rust-Solution-1D-Array
//Fastset
impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        // 0-1 knapsack
        let t_sum = nums.iter().fold(0, |x,y| x+y);
        if t_sum % 2 == 1 {
            return false;
        }
        let seek = (t_sum / 2) as usize ;
        let mut dp = vec![false; seek + 1];
        dp[0] = true;
        for num in nums.iter() {
            let n2 = *num as usize;
            for i in (n2..=seek).rev() {
                let index = i as usize;
                dp[index] = dp[index] || dp[index-n2];
            }
            if dp[seek] {
                return true;
            }
        }
        false
    }
}

//Second fastest
impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
       let mut sum: i32 = nums.iter().sum();
   
       if sum % 2 == 1 {
           return false;
       }
   
       sum /= 2;
       sum += 1;
   
       let mut comp = vec![false; sum as usize];
   
       comp[0] = true;
   
       for i in nums {
           for j in (i..sum).rev() {
               comp[j as usize] = comp[j as usize] || comp[(j - i) as usize];
           }
   
           if *comp.last().unwrap() {
               return true;
           }
       }
   
       false
   }
   }

//Another
impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
    let sum: i32 = nums.iter().sum();

    if sum % 2 == 1 {
        return false;
    }

    let sum: usize = (sum / 2) as usize + 1;

    let mut comp = vec![false; sum];

    comp[0] = true;

    for i in nums {
        let i = i as usize;

        for j in (i..sum).rev() {
            comp[j] = comp[j] || comp[j - i];
        }

        if *comp.last().unwrap() {
            return true;
        }
    }

    false
}
}