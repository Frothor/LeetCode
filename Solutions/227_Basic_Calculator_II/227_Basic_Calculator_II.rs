//Second fastest
use std::iter::Peekable;

impl Solution {
    fn whitespaces(iter: &mut Peekable<impl Iterator<Item = u8>>) {
        while let Some(b' ') = iter.peek() {
            iter.next();
        }
    }

    fn op(iter: &mut Peekable<impl Iterator<Item = u8>>) -> Option<u8> {
        Self::whitespaces(iter);

        iter.next()
    }

    fn number(iter: &mut Peekable<impl Iterator<Item = u8>>) -> i32 {
        Self::whitespaces(iter);

        let mut num = i32::from(iter.next().unwrap() - b'0');

        while let Some(&c @ b'0'..=b'9') = iter.peek() {
            num *= 10;
            num += i32::from(c - b'0');

            iter.next();
        }

        num
    }

    fn state_2(iter: &mut Peekable<impl Iterator<Item = u8>>, op: fn(i32, i32) -> i32, first: i32, second: i32) -> i32 {
        match Self::op(iter) {
            Some(b'+') => {
                let third = Self::number(iter);

                Self::state_2(iter, |x, y| x + y, op(first, second), third)
            }
            Some(b'-') => {
                let third = Self::number(iter);

                Self::state_2(iter, |x, y| x - y, op(first, second), third)
            }
            Some(b'*') => {
                let third = Self::number(iter);

                Self::state_2(iter, op, first, second * third)
            }
            Some(b'/') => {
                let third = Self::number(iter);

                Self::state_2(iter, op, first, second / third)
            }
            _ => op(first, second),
        }
    }

    fn state_1(iter: &mut Peekable<impl Iterator<Item = u8>>, first: i32) -> i32 {
        match Self::op(iter) {
            Some(b'+') => {
                let second = Self::number(iter);

                Self::state_2(iter, |x, y| x + y, first, second)
            }
            Some(b'-') => {
                let second = Self::number(iter);

                Self::state_2(iter, |x, y| x - y, first, second)
            }
            Some(b'*') => {
                let second = Self::number(iter);

                Self::state_1(iter, first * second)
            }
            Some(b'/') => {
                let second = Self::number(iter);

                Self::state_1(iter, first / second)
            }
            _ => first,
        }
    }

    pub fn calculate(s: String) -> i32 {
        let mut iter = s.bytes().peekable();
        let first = Self::number(&mut iter);

        Self::state_1(&mut iter, first)
    }
}

//Fastest
//https://leetcode.com/problems/basic-calculator-ii/discuss/776866/Rust-Solution
enum Token {
    Int(i32),
    Op(char),
}

fn next_token(s: &[u8], pos: &mut usize) -> Option<Token> {
    while *pos != s.len() && s[*pos] == ' ' as u8 {
        *pos += 1;
    }
    if *pos == s.len() {
        return None;
    }
    let mut ret = None;
    while *pos != s.len() {
        let c = s[*pos] as char;
        match (&mut ret, c.is_digit(10)) {
            (None, true) => {
                ret = Some(Token::Int(c as i32 - '0' as i32));
            },
            (None, false) => {
                ret = Some(Token::Op(c));
                *pos += 1;
                return ret;
            },
            (Some(Token::Int(_)), false) | (Some(Token::Op(_)), true) => {
                return ret;
            },
            (Some(Token::Int(v)), true) => {
                *v = *v * 10 + (c as i32 - '0' as i32);
            },
            _ => {
                unreachable!();
            }
        }
        *pos += 1;
    }
    ret
}

fn step(l: i32, r: i32, o: char) -> i32 {
    match o {
        '+' => l + r,
        '*' => l * r,
        '/' => l / r,
        '-' => l - r,
        _ => unreachable!(),
    }
}

fn get_priority(op: char) -> i32 {
    match op {
        '*' | '/' => 2,
        '+' | '-' => 1,
        _ => unreachable!(),
    }
}


impl Solution {
pub fn calculate(s: String) -> i32 {
    let mut op_st = vec![];
    let mut opnd_st = vec![];
    let mut pos = 0;
    while let Some(token) = next_token(s.as_bytes(), &mut pos) {
        match token {
            Token::Int(v) => {
                opnd_st.push(v);
            },
            Token::Op(o) => {
                while let Some(&top_op) = op_st.last() {
                    if get_priority(top_op) < get_priority(o) {
                        break;
                    }
                    op_st.pop();
                    
                    let r = opnd_st.pop().unwrap();
                    let l = opnd_st.pop().unwrap();
                    opnd_st.push(step(l, r, top_op));
                }
                op_st.push(o);
            },
        }
    }
    while let Some(c) = op_st.pop() {
        let r = opnd_st.pop().unwrap();
        let l = opnd_st.pop().unwrap();
        opnd_st.push(step(l, r, c));
    }
    return opnd_st.pop().unwrap();
}
}

//Another
impl Solution {
    pub fn calculate(s: String) -> i32 {
        let bytes = s.as_bytes();
        let (mut prev, mut cur) = (0, 0);
        let mut res = 0;
        let mut sign = b'+';
        for i in 0..bytes.len() {
            let mut is_digit = false;
            if (bytes[i] as char).is_digit(10) {
                cur = cur * 10 + (bytes[i] - b'0') as i32;
                is_digit = true;
            } 

            if (!is_digit && bytes[i] != b' ') || i + 1 == bytes.len() {
                if sign == b'+' {
                    res += prev;
                    prev = cur;
                } else if sign == b'-' {
                    res += prev;
                    prev = -cur;
                } else if sign == b'*' {
                    prev *= cur;
                } else if sign == b'/' {
                    prev /= cur;
                }
                cur = 0;
                sign = bytes[i];
            }
        }
        res += prev;
        res

    }
}