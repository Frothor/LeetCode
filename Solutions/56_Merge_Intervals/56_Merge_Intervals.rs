//Second fastest
impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (mut starts, mut ends) = intervals.iter().fold((vec![], vec![]), |mut acc, x| {
            acc.0.push(x[0]);
            acc.1.push(x[1]);
            
            return acc
        });

        let mut result = Vec::new();
        starts.sort();
        ends.sort();

        let (mut start_iter, mut end_iter) = (starts.iter(), ends.iter());

        loop {
            match (start_iter.next(), end_iter.next()) {
                (Some(&start), Some(&end)) => {
                    result.temper_push(vec![start, end]);
                },
                (None, None) => break,
                (_, _) => panic!("Error"),
            }
        }

        result
    }
}

enum CompareResult {
    Sub,
    Equal,
    Intersecting,
    Disjoint,
    ProperSub,
}

trait TemperPush {
    fn temper_push(&mut self, temp: Vec<i32>);
    fn temper_compare(&self, l: &Vec<i32>, r: &Vec<i32>) -> CompareResult;
}

impl TemperPush for Vec<Vec<i32>> {
    fn temper_push(&mut self, temp: Vec<i32>) {
       match self.last() {
           Some(last) => {
                match self.temper_compare(last, &temp) {
                    CompareResult::Sub => {}
                    CompareResult::Equal => {}
                    CompareResult::ProperSub => {
                        self.pop();
                        self.push(temp);
                    }
                    CompareResult::Intersecting => { 
                        let last = self.pop().unwrap();
                        self.push(vec![last[0], temp[1]]);
                    }
                    CompareResult::Disjoint => {
                        self.push(temp);
                    }
                }
           }
           None => { self.push(temp); }
       } 
    }

    fn temper_compare(&self, l: &Vec<i32>, r: &Vec<i32>) -> CompareResult {
        if l[0] == r[0] {
            if l[1] == r[1] {
                CompareResult::Equal
            } else if l[1] > r[1] {
                CompareResult::Sub
            } else {
                CompareResult::ProperSub
            }
        } else {
            if l[1] < r[0] {
                CompareResult::Disjoint
            } else if l[1] == r[1] || l[1] > r[1]{
                CompareResult::Sub
            } else {
                CompareResult::Intersecting
            }
        }
    }
    
}



//Fastest - https://leetcode.com/problems/merge-intervals/discuss/598258/0ms-Rust-in-Functional-programming-style
impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut intervals = intervals
            .into_iter()
            .map(|vec| (vec[0], vec[1]))
            .collect::<Vec<(i32, i32)>>();
        intervals.sort();

        let (mut results, last_interval) =
            intervals
                .into_iter()
                .fold(
                    (vec![], None),
                    |(mut results, prev_interval), interval| match prev_interval {
                        None => (results, Some(interval)),
                        Some(prev) if prev.is_overlap(&interval) => {
                            (results, Some(interval.merge(prev)))
                        }
                        Some(prev) => {
                            results.push(prev);
                            (results, Some(interval))
                        }
                    },
                );
        if let Some(interval) = last_interval {
            results.push(interval);
        }
        results
            .into_iter()
            .map(|(start, end)| vec![start, end])
            .collect()
    }
}
trait Interval<T> {
    fn is_overlap(&self, other: &T) -> bool;
    fn is_in(&self, x: i32) -> bool;
    fn merge(self, other: T) -> Self;
}

impl Interval<(i32, i32)> for (i32, i32) {
    fn is_overlap(&self, other: &(i32, i32)) -> bool {
        let (start, end) = *other;
        self.is_in(start) || self.is_in(end)
    }

    fn is_in(&self, x: i32) -> bool {
        self.0 <= x && x <= self.1
    }

    fn merge(self, other: Self) -> Self {
        (self.0.min(other.0), self.1.max(other.1))
    }
}


//Another
impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();

        let mut intervals = intervals;
        intervals.sort_by(|a, b| a[0].cmp(&b[0]));

        let mut i = 0;
        while i < intervals.len() - 1 {
            if intervals[i][1] >= intervals[i + 1][0] {
                intervals[i + 1][0] = intervals[i][0].min(intervals[i + 1][0]);
                intervals[i + 1][1] = intervals[i][1].max(intervals[i + 1][1]);
            } else {
                res.push(intervals[i].clone())
            }
            i += 1;
        }

        res.push(intervals[intervals.len() -1].clone());

        // println!("{:?}", res);

        res
    }
}