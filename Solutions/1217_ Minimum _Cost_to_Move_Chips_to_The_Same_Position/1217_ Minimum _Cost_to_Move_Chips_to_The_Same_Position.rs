impl Solution {
    pub fn min_cost_to_move_chips(position: Vec<i32>) -> i32 {
        let odd = position.iter().filter(|&p| p % 2 == 1).count();
        std::cmp::min(odd, position.len() - odd) as i32
    }
}