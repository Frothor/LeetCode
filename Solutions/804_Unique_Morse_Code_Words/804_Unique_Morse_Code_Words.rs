//https://leetcode.com/problems/unique-morse-code-words/discuss/214221/Rust-Solution
use std::collections::HashSet;
impl Solution {
    pub fn unique_morse_representations(words: Vec<String>) -> i32 {
        
        let morse_codes = vec![".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
        
        let mut morse_set = HashSet::new();
        for word in &words{
            let mut temp_str : String = "".into();
            let mut chars = word.chars();
            let mut each_char = chars.next();
            loop {
                match each_char {
                    Some(x) => temp_str.push_str(morse_codes[(x as u8 - 97) as usize]),
                    None => break,
                }
             each_char = chars.next();
            }
            morse_set.insert(temp_str);
        }
        return morse_set.len() as i32;
    }
    
}

//More space efficient
use std::collections::HashSet;

impl Solution {
    // Don't get too invested with lifetime.
    pub const morse: [&'static str; 26] = [
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",
        ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
        "...","-","..-","...-",".--","-..-","-.--","--.."
    ];
        
    pub fn unique_morse_representations(words: Vec<String>) -> i32 {
        let mut h: HashSet<String> = HashSet::with_capacity(words.len());
        
        for word in words {
            let code = word
                        .chars()
                        .map(|x| Solution::morse[(x.to_digit(36).expect("") - 10) as usize])
                        .collect::<Vec<&str>>()
                        .join("");
            h.insert(code);
        }
        h.len() as i32
    }
}