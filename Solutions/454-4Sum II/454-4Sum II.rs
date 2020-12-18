//Fourth fastest
use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn four_sum_count(a: Vec<i32>, b: Vec<i32>, c: Vec<i32>, d: Vec<i32>) -> i32 {
        let mut result = 0;
        let mut map: HashMap<i32, i32> = HashMap::new();
        
        for i in a.iter() {
            for j in b.iter() {
                let sum = i + j;
                match map.get(&sum) {
                    Some(n) => map.insert(sum, n + 1),
                    None => map.insert(sum, 1)
                };
            }
        }
        
        for l in c.iter() {
            for k in d.iter() {
                if let Some(v_2) = map.get(&-(l + k)) {
                    result += v_2;
                }
            }
        }
        
        result
    }
}

//Third fastest
use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn four_sum_count(a: Vec<i32>, b: Vec<i32>, c: Vec<i32>, d: Vec<i32>) -> i32 {
        let mut permutations_summing_zero = 0;
        let mut permutation_map_1: HashMap<i32, i32> = HashMap::new();
        
        for i in a.iter() {
            for j in b.iter() {
                match permutation_map_1.get(&(i + j)) {
                    Some(n) => permutation_map_1.insert(i + j, n + 1),
                    None => permutation_map_1.insert(i + j, 1)
                };
            }
        }
        
        for l in c.iter() {
            for k in d.iter() {
                if let Some(v_2) = permutation_map_1.get(&-(l + k)) {
                    permutations_summing_zero += v_2;
                }
            }
        }
        
        permutations_summing_zero
    }
}

//Second fastest
use std::collections::HashMap;

impl Solution {
    pub fn four_sum_count(a: Vec<i32>, b: Vec<i32>, c: Vec<i32>, d: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut map = HashMap::new();
        for num_a in &a {
            for num_b in &b {
                *map.entry(num_a + num_b).or_insert(0) += 1;
            }
        }
        for num_c in &c {
            for num_d in &d {
                ans += map.get(&-(num_c + num_d)).unwrap_or(&0);
            }
        }
        ans
    }
}

//Another
use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn four_sum_count(a: Vec<i32>, b: Vec<i32>, c: Vec<i32>, d: Vec<i32>) -> i32 {
        let mut permutations_summing_zero = 0;
        let mut permutation_map_1: HashMap<i32, i32> = HashMap::new();
        
        for i in a.iter() {
            for j in b.iter() {
                match permutation_map_1.get(&(i + j)) {
                    Some(n) => permutation_map_1.insert(i + j, n + 1),
                    None => permutation_map_1.insert(i + j, 1)
                };
            }
        }
        
        for l in c.iter() {
            for k in d.iter() {
                if let Some(v_2) = permutation_map_1.get(&-(l + k)) {
                    permutations_summing_zero += v_2;
                }
            }
        }
        
        permutations_summing_zero
    }
}

//Fastest
impl Solution {
    pub fn four_sum_count(a: Vec<i32>, b: Vec<i32>, c: Vec<i32>, d: Vec<i32>) -> i32 {
        
        let mut hm = std::collections::HashMap::new();
        
        for i in 0..c.len() {
            for j in 0..d.len() {
                *hm.entry(c[i]+d[j]).or_insert(0) += 1;
            }
        }
        
        let mut ans = 0;
        
        for i in 0..a.len() {
            for j in 0..b.len() {
                let sum = -a[i] - b[j];
                if let Some(val) = hm.get(&sum) {
                    ans += *val;
                }
            }
        }
        ans
    }
}