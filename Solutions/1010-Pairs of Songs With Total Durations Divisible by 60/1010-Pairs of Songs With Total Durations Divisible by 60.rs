//Second fastest
use std::collections::HashMap;

impl Solution {
    pub fn num_pairs_divisible_by60(time: Vec<i32>) -> i32 {
        let mut res = 0;
        let mut dist = HashMap::new();
        for t in time {
            let remainer = t % 60;
            *dist.entry(remainer).or_insert(0) += 1;
        }
        for i in 1..=29 {
            if let Some(l_count) = dist.get(&i) {
                if let Some(r_count) = dist.get(&(60 - i)) {
                    res += l_count * r_count;
                }
            }
        }
        if let Some(c) = dist.get(&0) {
            let c = *c;
            if c > 1 {
                res += c * (c - 1) / 2;
            }
        }
        if let Some(c) = dist.get(&30) {
            let c = *c;
            if c > 1 {
                res += c * (c - 1) / 2;
            }
        }
        res
    }
}


//Fastest
impl Solution {
    pub fn num_pairs_divisible_by60(time: Vec<i32>) -> i32 {
         let mut c: Vec<i32> = vec![0; 60];
    let mut res = 0;
    for item in time.iter() {
        res += c[((540 - item) % 60) as usize];
        c[(item % 60) as usize] += 1;
    }
    res
    }
}