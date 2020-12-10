//https://leetcode.com/problems/valid-mountain-array/discuss/967038/Rust-onepass
#[derive(PartialEq, Eq)]
enum State {
    Void,
    Up,
    Down,
}

impl Solution {
    pub fn valid_mountain_array(arr: Vec<i32>) -> bool {
        if arr.len() < 3 {
            return false;
        }
        let mut state = State::Void;
        for cur in 0..arr.len() {
            if cur == 0 {
                continue;
            }
            if arr[cur] == arr[cur - 1] {
                return false;
            }
            match state {
                State::Void => {
                    if arr[cur] > arr[cur - 1] {
                        state = State::Up;
                    } else {
                        return false;
                    }
                },
                State::Up => {
                    if arr[cur] < arr[cur - 1] {
                        state = State::Down;
                    }
                }
                State::Down => {
                    if arr[cur] > arr[cur - 1] {
                        return false;
                    }
                }
            }
        }
        state == State::Down
    }
}


//Another
impl Solution {
    pub fn valid_mountain_array(arr: Vec<i32>) -> bool {
        if arr.len() < 3 { return false; }
        if arr[1] < arr[0] { return false; }
        
        let mut is_peak_passed = false;
        
        for i in 1..arr.len() {
            if arr[i] == arr[i-1] { return false; }
            
            if !is_peak_passed {
                if arr[i] < arr[i-1] {
                    is_peak_passed = true;
                }
            } else {
                if arr[i] > arr[i-1] {
                    return false;
                }
            }
        }
        
        is_peak_passed
    }
}