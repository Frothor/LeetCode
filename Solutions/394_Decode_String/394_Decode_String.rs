//https://leetcode.com/problems/decode-string/discuss/941553/Rust-stack-solution
impl Solution {
    pub fn decode_string(s: String) -> String {
        let mut stack: Vec<(usize, String)> = Vec::new();
        let (mut n, mut str) = (0, String::new());
        for c in s.chars() {
            match c {
                '[' => {
                    stack.push((n, str.clone()));
                    n = 0;
                    str.clear();
                }
                ']' => {
                    if let Some(last) = stack.pop() {
                        str = last.1 + str.repeat(last.0).as_str();
                    }
                }
                '0'..='9' => n = n * 10 + (c as u8 - b'0') as usize,
                c => str.push(c),
            }
        }
        str
    }
}

//Another
impl Solution {
    pub fn decode_string(s: String) -> String {
        let mut c_ary: Vec<char> = s.chars().collect();
        let (output_string, end) = Self::decode_substring(&c_ary, 0, 0);
        output_string
    }
    
    pub fn decode_substring(ary: &Vec<char>, rep: u32, start: usize) -> (String, usize) {
        let mut outer_stack: Vec<char> = Vec::new();
        let mut ind = start;
        
        while ind < ary.len() {
            let mut num: u32 = 0;
            while ary[ind].is_digit(10) {
                num = num *10 + ary[ind].to_digit(10).unwrap();
                ind += 1;
            }
            
            if ary[ind] == '[' {
                ind += 1;
                let (new_string, end) = Self::decode_substring(&ary, num, ind);
                for st in new_string.chars() {
                    outer_stack.push(st);
                }
                ind = end;
                continue;
            }
            
            if ary[ind] == ']' {
                break;
            }
            outer_stack.push(ary[ind]);
            ind += 1;
        }

        let final_string:String = outer_stack.iter().collect::<String>();    
        if rep == 0 {
            return (final_string, ind + 1);
        }
        
        let mut output: String = "".to_string();
        for i in 0..rep {
            output.push_str(&final_string);
        }
        (output, ind + 1)
    }
}