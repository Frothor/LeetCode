//Second fastest
use std::iter;

impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        if flowerbed.len() == 0 {
            return n == 0;
        }

        let calc = |i, j| -> usize {
            if j < i + 2 {
                return 0;
            }

            let len = 1 + (j - 1) - (i + 1);
            if len % 2 != 0 {
                len / 2 + 1
            } else {
                len / 2
            }
        };

        let mut c = 0;
        let mut prev = Some(0);
        for (i, &b) in iter::once(&0).chain(flowerbed.iter()).enumerate() {
            match (prev, b as usize) {
                (None, 0) => prev = Some(i),
                (Some(p), 1) => {
                    prev = None;
                    c += calc(p, i - 1);
                }
                _ => {}
            }
        }
        if let Some(p) = prev {
            c += calc(p, flowerbed.len() + 1);
        }

        c as i32 >= n
    }
}

//Fastest
//https://leetcode.com/problems/can-place-flowers/discuss/734233/In-rust
impl Solution {
    
    pub fn can_place_flowers(mut flowerbed: Vec<i32>, n: i32) -> bool {
        let mut count = 0;
        
        if flowerbed.len() == 1 {
            return (flowerbed[0] == 0 && n <= 1) || (flowerbed[0] == 1 && n == 0);
        }
    
        for i in 0..flowerbed.len() {
            if i == 0 {
                if flowerbed[i] == 0 && flowerbed[i + 1] == 0 {
                    flowerbed[i] = 1;
                    count += 1;
                }
            } else if i == flowerbed.len() - 1 {
                if flowerbed[i - 1] == 0 && flowerbed[i] == 0 {
                    flowerbed[i] = 1;
                    count += 1;
                }
            } else {
                if flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0 {
                    flowerbed[i] = 1;
                    count += 1;
                }
            }
        }
        
        count >= n
    }
}

//Another
impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        let mut c = 0;
        let mut prev = 0;
        for (&curr, &next) in flowerbed.iter().zip(flowerbed.iter().skip(1)) {
            match (prev, curr, next) {
                (0, 0, 0) => {
                    c += 1;
                    prev = 1;
                }
                _ => prev = curr,
            }
        }
        if let Some(&last) = flowerbed.last() {
            if last + prev == 0 {
                c += 1;
            }
        }

        c as i32 >= n
    }
}