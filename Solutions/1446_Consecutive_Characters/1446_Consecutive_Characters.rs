use std::cmp::max;
impl Solution {
    pub fn max_power(s: String) -> i32 {
       let (mut res, mut cnt) = (0, 0);
       let mut pre = '#' ;
       for c in s.chars() {
           if c == pre {
               cnt += 1; 
               res = max(res, cnt);
           } else {
               pre = c;
               cnt = 1;
           }
       }
       max(res, 1) 
    }
}

//Another
impl Solution {
    pub fn max_power(s: String) -> i32 {
        use std::cmp::max;

        let mut max_count: i32 = 0;
        let mut previous_character: char = '.';
        
        let mut count: i32 = 0;
        for c in s.chars() {
            if previous_character == c {
                count += 1;
            } else {
                count = 1;
                previous_character = c;
            }

            max_count = max(count, max_count);
        }

        max_count
    }
}