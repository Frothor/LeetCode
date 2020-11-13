//Third fastest
use std::collections::HashSet;

impl Solution {
    pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums_copy = nums.to_vec();
        nums_copy.sort_unstable();

        let l = nums_copy.len();
        let mut cur: Vec<i32> = Vec::with_capacity(l);
        let mut ans: Vec<Vec<i32>> = Vec::new();
        let mut seen: HashSet<usize> = HashSet::new();

        Self::dfs(&mut cur, &mut ans, &mut seen, l, &nums_copy);
        ans

    }

    fn dfs(cur: &mut Vec<i32>, ans: &mut Vec<Vec<i32>>, seen: &mut HashSet<usize>, l: usize, nums: &[i32]) {
        if cur.len() == l {
            ans.push(cur.to_vec());
            return;
        }
        for (i, num) in nums.iter().enumerate() {
            if seen.contains(&i) { continue; }
            if i > 0 && nums[i] == nums[i-1] && seen.contains(&(i-1)) { continue; }
            seen.insert(i);
            cur.push(*num);
            Self::dfs(cur, ans, seen, l, nums);
            cur.pop();
            seen.remove(&i);
        }
    }
}

//Second fastest
use std::collections::HashMap;

impl Solution {
    pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut hm: HashMap<i32, usize> = HashMap::new();
        nums.iter()
            .for_each(|&num| *hm.entry(num).or_insert(0) += 1);
        let mut answer = Vec::new();
        let mut v = Vec::new();
        Solution::helper(&mut hm, &mut answer, &mut v);
        answer
    }
    fn helper(hm: &mut HashMap<i32, usize>, answer: &mut Vec<Vec<i32>>, v: &mut Vec<i32>) {
        let candidates: Vec<i32> = hm.iter().filter(|(_, &v)| v > 0).map(|(&k, _)| k).collect();
        if candidates.is_empty() {
            answer.push(v.clone());
        } else {
            for candidate in candidates.iter() {
                if let Some(val) = hm.get_mut(candidate) {
                    *val -= 1;
                }
                v.push(*candidate);
                Solution::helper(hm, answer, v);
                v.pop();
                if let Some(val) = hm.get_mut(candidate) {
                    *val += 1;
                }
            }
        }
    }
}

//Another
impl Solution {
    pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
        if nums.is_empty() {
            return vec![vec![]];
        }

        let mut nums = nums;
        nums.sort();

        let mut result: Vec<Vec<i32>> = Vec::new();

        for i in 0..nums.len() {
            if i == 0 || nums[i] != nums[i - 1] {
                let mut xs = nums.clone();
                xs.remove(i);

                let mut backtrack = Solution::permute_unique(xs);

                for vec in &mut backtrack {
                    vec.push(nums[i]);
                }

                result.append(&mut backtrack);
            }
        }

        result
    }
}

//Fastest
impl Solution {
    fn backtrack(
        n: usize,
        nums: &Vec<i32>,
        cur: &mut Vec<i32>,
        ans: &mut Vec<Vec<i32>>,
        start: usize,
        vis: &mut Vec<bool>,
    ) {
        if start == n {
            ans.push(cur.clone());
            return;
        }

        for i in 0..nums.len() {
            if vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) {
                continue;
            }

            cur.push(nums[i]);
            vis[i] = true;
            Self::backtrack(n, nums, cur, ans, start + 1, vis);
            vis[i] = false;
            cur.pop();
        }
    }

    pub fn permute_unique(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ans = vec![];
        let n = nums.len();
        let mut vis = vec![false; n];
        nums.sort();
        Self::backtrack(n, &nums, &mut Vec::new(), &mut ans, 0, &mut vis);
        ans
    }


}