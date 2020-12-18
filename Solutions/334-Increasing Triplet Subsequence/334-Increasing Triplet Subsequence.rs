//Fasstest
impl Solution {
    pub fn increasing_triplet(nums: Vec<i32>) -> bool {
        let mut small = i32::max_value();
        let mut large = small;
        
        for i in nums {
            if i <= small {
                small = i;
            } else if i <= large {
                large = i;
            } else {
                return true;
            }
        }
        
        false
    }
}

//Another
impl Solution {
    pub fn increasing_triplet(nums: Vec<i32>) -> bool {
        let mut first = i32::max_value();
        let mut second = i32::max_value();

        for num in nums {
            if num > second {
                return true;
            } else if num > first {
                second = num;
            } else {
                first = num;
            }
        }

        false
    }
}