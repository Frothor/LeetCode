//https://leetcode.com/problems/spiral-matrix-ii/discuss/714840/Rust-Simulation
impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let n = n as usize;
        let mut ret = vec![vec![0; n]; n];

        let mut num = 1;
        for i in 0..((n + 1) / 2) {
            for c in i..(n - 1 - i) {
                ret[i][c] = num;
                num += 1;
            }
            for r in i..(n - 1 - i) {
                ret[r][n - 1 - i] = num;
                num += 1;
            }
            for c in ((i + 1)..(n - i)).rev() {
                ret[n - 1 - i][c] = num;
                num += 1;
            }
            for r in ((i + 1)..(n - i)).rev() {
                ret[r][i] = num;
                num += 1;
            }
        }
        ret[n / 2][(n - 1) / 2] = (n * n) as i32;

        ret
    }
}

//Another
fn switch_direction(direction: [i32; 2]) -> [i32; 2] {
    match direction {
        [0,1] => [1,0],
        [1,0] => [0,-1],
        [0,-1] => [-1,0],
        [-1,0] => [0,1],
        _ => {panic!()},
    }
}

impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        // the plan:
        // given n, we know the number of straight line segments our path will take
        // we also know that the direction turns right at the end of every straight line path
        // eg for n=3, we take straight line segments of length 3,3,3,2,2,1,1.
        // these straight line segments always come in pairs, apart from the first three segments, which are always equal to n
        // and the direction is obvious - it changes in a predictable way at the end of each straight line segment
        
        // n=1 is a special case
        if n == 1 {
            return vec![vec![1 as i32]];
        }
        
        // first make an n by n vector and populate first value
        // (because all the other values will be populated AFTER a step)
        let mut output_vector: Vec<Vec<i32>> = vec![vec![0; n as usize]; n as usize];
        output_vector[0][0] = 1;
        
        // pre-populate first values of steps and directions
        let mut steps: Vec<i32> = vec![n-1];
        let mut directions: Vec<[i32; 2]> = vec![[0,1]];
        
        // set up current direction data structure
        let mut current_direction: [i32; 2] = [0,1];
        current_direction = switch_direction(current_direction);
        
        // go through and assign all the necessary steps and directions values
        for i in (1..n).rev() {
            for j in 0..2 {
                steps.push(i);
                directions.push(current_direction);
                current_direction = switch_direction(current_direction);
            }
        }
        
        println!("{:?}", steps);
        println!("{:?}", directions);
        
        // count just counts up as we go through the spiral
        // m and n are the vertical and horizontal indexes respectively
        let mut count: i32 = 1;
        let mut m: i32 = 0;
        let mut n: i32 = 0;
        
        // loops once for every straight line the path has to take
        for i in 0..(steps.len()) {
            // loops once for every step of the path
            for j in 0..steps[i] {
                // update the indexes
                m += directions[i][0];
                n += directions[i][1];
                
                // add one to the currnet count, add this to the output vector
                count += 1;
                output_vector[m as usize][n as usize] = count;
            }
        }
        
        output_vector
    }
}


//Another
enum Dir {
    N, S, E, W,
}

impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
		let n = n as usize;
		let mut ans = vec![vec![0; n]; n];
		let total = n * n;
        
		let (mut state, mut offset) = (Dir::E, 0);
        let (mut row, mut col, mut cnt) = (0, 0, 1);
        while cnt <= total {
			ans[row][col] = cnt as i32;
			
			// state transition logic
			match state {
			    Dir::N => {
					// need to update offset in this arm
					if row == offset + 1 {
						offset += 1;
						state = Dir::E;
						col += 1;
					} else {
						row -= 1;
					}
				}
			    Dir::S => {
					if row == n - offset - 1 {
						state = Dir::W;
						col -= 1;
					} else {
						row += 1;
					}
				}
			    Dir::E => {
					if col == n - offset - 1 {
						state = Dir::S;
						row += 1;
					} else {
						col += 1;
					}
				}
			    Dir::W => {
					if col == offset {
						state = Dir::N;
						row -= 1;
					} else {
						col -= 1;
					}
				}
			}

			cnt += 1;
        }
        
        ans
    }
}