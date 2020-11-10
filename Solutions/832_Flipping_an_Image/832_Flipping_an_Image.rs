impl Solution {
    pub fn flip_and_invert_image(mut a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        for v in a.iter_mut() {
            v.reverse();
            for l in v.iter_mut() {
                *l ^= 1;
            }
        }
        a
    }
}

//Another
impl Solution {
    pub fn flip_and_invert_image(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = Vec::new();
        
        let m = a.len();
        let n = a[0].len();
        let n_half = n / 2;

        for i in 0..m {
            
            let mut new_row: Vec<i32> = Vec::new();
            for k in 0..n {
                new_row.push(a[i][k].clone());
            }
            
            
            for j in 0..n_half {
                new_row.swap(j, n-j-1);
            }
            
            ans.push(new_row);
        }
        
        for i in 0..m {
            for j in 0..n {
                if ans[i][j] == 0 {
                    ans[i][j] = 1
                } else {
                    ans[i][j] = 0
                }
            }
        }
        
        return ans;
    }
}