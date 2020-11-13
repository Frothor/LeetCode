impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        if nums.is_empty() {
            return vec![Vec::new()];
        }

        let mut ret = Vec::new();

        for i in 0..nums.len() {
            let mut nums_clone = nums.clone();
            nums_clone.remove(i);

            let mut back_ret = Self::permute(nums_clone);

            for arr in &mut back_ret {
                arr.push(nums[i]);
            }
            ret.append(&mut back_ret);
        }

        ret
    }
}

//Another
impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut res:Vec<Vec<i32>> = Vec::new();
        fn recursive_push (res: &mut Vec<Vec<i32>>, repo: Vec<i32>, items: Vec<i32>) {
            if items.len() == 0 { res.push(repo.clone()); return }

            for (idx, &item) in items.iter().enumerate() {
                let mut new_vec = items.clone();
                new_vec.remove(idx);
                let mut repo2 = repo.clone();
                repo2.push(item);
                recursive_push(res, repo2, new_vec);
            }
        };
        if nums.len() != 0 {recursive_push(&mut res, Vec::new(), nums);}              
        res
    }
}