//Another
https://leetcode.com/problems/palindrome-partitioning/discuss/241298/Rust-no-recursion-DP-solution-with-O(N2)-time-and-O(N2)-space
/*
 记 n 个字符的回文拆分方式是 f(n) 种, 则:

 f(n) = (0..n).iter().fold(0, |acc, i| {
    if is_palindrome(s[i..n]) { acc + f(i-1) } else { acc }
 })

 按这种方式向上递推即可, 时间复杂度为 O(N^3), 空间复杂度 O(N), 显然, is_palindrome 这一步仍然有重复计算

 is_palindrome(s[i..n]) = s[i] == s[n] && is_palindrome(s[i+1..n-1])

 存储所有 i, n 的 is_palindrome 结果, 则可以优化 is_palindrome 的时间到 O(1)

 最后的复杂度: 时间 O(N^2), 空间 O(N^2)
 */
 impl Solution {
    pub fn partition(s: String) -> Vec<Vec<String>> {
        let s = s.chars().collect::<Vec<_>>();
        if s.is_empty() { return Vec::new() }
        let mut palindrome_cache = vec![vec![None; s.len()]; s.len()];
        let mut res: Vec<Vec<Vec<(usize, usize)>>> = Vec::with_capacity(s.len());
        res.push(vec![vec![(0,1)]]);
        for n in 1..s.len() {
            let mut curr: Vec<Vec<(usize, usize)>> = Vec::new();
            for i in 0..n+1 {
                if Solution::is_palindrome(&mut palindrome_cache, &s, i, n) {
                    if i > 0 {
                        for vec in res[i-1].iter() {
                            let mut new_vec = vec.clone();
                            new_vec.push((i,n+1));
                            curr.push(new_vec);
                        }
                    } else {
                        curr.push(vec![(i, n+1)]);
                    }
                }
            }
            res.push(curr);
        }
        (*res[s.len()-1]).into_iter().map(|vec| {
            vec.iter()
                .map(|&range| {s[range.0..range.1].iter().collect::<String>()})
                .collect::<Vec<_>>()
        }).collect()
    }

    fn is_palindrome(cache: &mut Vec<Vec<Option<bool>>>, s: &Vec<char>, i: usize, j: usize) -> bool {
        if j <= i { return true }
        if let Some(result) = cache[i][j] {
            result
        } else {
            let result = s[i] == s[j] && (i + 1 > s.len() || j < 1 || Solution::is_palindrome(cache, s, i+1, j-1));
            cache[i][j] = Some(result);
            result
        }
    }
}

//Fastest
impl Solution {
    pub fn partition(s: String) -> Vec<Vec<String>> {
        let mut res: Vec<Vec<String>> = vec![];

        backtrace(s, &mut vec![], &mut res);

        res
    }
}

fn backtrace(s: String, cur_res: &mut Vec<String>, res: &mut Vec<Vec<String>>) {
    if s.is_empty() {
        res.push(cur_res.clone())
    }

    for i in 1..s.len() + 1 {
        let s_left = String::from(&s[0..i]);
        let s_right = String::from(&s[i..s.len()]);
        if is_palindrome(&s_left) {
            cur_res.push(s_left);
            backtrace(s_right, cur_res, res);
            cur_res.pop();
        }
    }
}

fn is_palindrome(s: &String) -> bool {
    if s.len() < 2 {
        true
    } else {
        let mut lo = 0;
        let mut hi = s.len() - 1;

        while lo < hi {
            if s.as_bytes()[lo] == s.as_bytes()[hi] {
                lo += 1;
                hi -= 1;
            } else {
                return false;
            }
        }

        true
    }
}