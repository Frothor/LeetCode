//Fastest
var poorPigs = function(buckets, minutesToDie, minutesToTest) {
  let answer = 1;
  let n = minutesToTest / minutesToDie >> 0;
  n += 1;
  
  // calculation with loop
  // while(n ** answer <= buckets) {
  //   answer++;
  // }
  
  return Math.ceil(Math.log(buckets) / Math.log(n));
};


//Another
var poorPigs = function(buckets, minutesToDie, minutesToTest) {
  /*
  I: number of buckets, minutes to kill pig, minutes to test
  O: minimum number of pigs needed to figure out poisonous bucket
  C: pig can drink unlimited buckets simultaneously and takes no time, after drinking there is a cool down of m time
     buckets can be sampled unlimited number of times
  E: minutes to die is same as or greater than minutes to test?
  Q: are other pigs allowed to drink during cool down period? can pigs drink at same time?
  
  ex.:  100 buckets, 15 min to die, 60 minutes to test
  let's consider some options... could use a binary search type approach as long as we have enough time:
     1 pig does 50 buckets, another does the other 50... 15 min later we've eliminated half the buckets
     surviving pig now does half of the half and another does the other half of half... 15 min later its down to 25
     100 => 50 => 25 => ~12 => 6 => 3 => 1, 2, 3  => 8 pigs, not enough TIME
     
     for this specific problem... we get 4 tests before we are out of time
     
     split 100 into 4? So 4 pigs drink first round 25 25 25 25 (15 min) => 25 => 6 7 6 6 (30 min) => 6 => 2 2 1 1 (45 min) => 2/1
     
     number of pigs needed will roughly equal possibilities left at the end of time alotted / time to die
       this depends on your approach
       
     the most buckets that can be eliminated with the fewest pigs is by binary search
       do this up until the last alotted test and then use as many pigs as necessary to find bucket (1 pig per bucket)
       
     minutes to test / minutes to die gives number of tests that can be performed (t)
       t - 1 (b) is number of times can perform binary search elimination of buckets
       b *  buckets  log10     2^x = 10
     
     1
     2
     3
     4
     5   
     6   6
     7   7
     8   8   
     9   9   9
     10  10  10    10 => 5 > 2.5 > 1.25   10... 5... 2.5... 1.25... ..0     n2   0 1 4 9 16 25
                                                                                 0 1 2 3  4  5
                                                                                 
                                                                                 
                                                                                 
    10 buckets... 
    
    1 2 3 4 5
    6 7 8 9 0
    
     1 2 3 4 5 6 7 8 9 10
  p1 x d x d
  p2 x x d d
  
  for 2 pigs the total buckets that can be tested in 1 test is 4 (2 ^ 2)
  
     1 2 3 4 5 6 7 8 9 10
  p1 x d x x d d x d
  p2 x x d x d d d x
  p3 x x x d d x d d
  
  for 3 pigs the total buckets that can be tested in 1 test is 8 (2 ^ 3)
  
     1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
  p1 x d x x x d d x x d  d  x  d  x  d  d
  p2 x x d x x d d d x x  x  d  d  d  x  d
  p3 x x x d x d x d d d  x  x  d  d  d  x
  p4 x x x x d d x x d x  d  d  x  d  d  d
  
  for 4 pigs the total buckets that can be tested in 1 test is 16 (2 ^ 4)
  
  so total buckets that can be tested in ONE test in respect to k pigs is: b = (2 ^k) (T/td + 1)
  
  2^k = (T/td + 1) / b  ====>  2^k = 5 / 1000  ===> 2^k = 200
  
  solve for k if input is 1000 buckets:  1000 = 2^k ... log2(1000) = k ... 2*2*...ktimes = 1000 
  
  so now, given number of pigs, how many buckets can be tested given l tests?
  
  1 test: (4)
     1 2 3 4 5 6 7 8 9 10
  p1 x d x d
  p2 x x d d

  2 tests: (7)
     1 2 3 4 5 6 7
  p1 d x d
  p2 x d d
  p1       d x d
  p2       x d d
  
  3 tests: (10)  
     1 2 3 4 5 6 7 8 9 10
  p1 d x d
  p2 x d d
  p1       d x d
  p2       x d d
  p1             d x d
  p2             x d d
  
  different approach:
  
  given number of tests t (T/td) this is the possibilities for each pig:
  
  p1: t + 1  (can die after any of the tests or be alive at the end, hence + 1)
  p2: "   "    "        "
  
  ex.: T/td = 4:
    p1: 1 2 3 4 (5 - survived)
    p2: 6 7 8 9 (10 - survived)
    p3: 11 12 13 14 (15 - survived)
    
  if they each do 4 unique buckets plus 1 at end for case no one dies then total buckets are:
    4 * p + 1 ==> 4 * 3 + 1 ==> 13 buckets total if there are 3 pigs and 4 steps (each do a diff bucket at each step, if none die then it must be the last bucket)
  
  BUT this is not smart because they are only eliminating cases where ONE pig dies, not utilizing other combos:
    if instead of each doing a unique bucket each step they did diff combos:
      each step there can be these possibilities: (for 3 pigs)
        pig1 dies           x :) :)
        pig1 + pig2 dies    x  x :)
        pig1 + pig3 dies    x :) x
        pig2 dies           :) x :)
        pig2 + pig3 dies    :) x x
        pig3 dies           :) :)x
        pig3 + pig1 + pig2 dies
        no pigs die (must be bucket not tested)
        There are 8 possibilities each step given 3 pigs (2^3)
          each possibility corresponds to a bucket that can be identified
        For k steps, the buckets (possibilities - b) are:
          b = (k+1)^p
  */
  
  let k = Math.ceil(minutesToTest / minutesToDie); // 4
  let total = 1;
  let res = 0;
  while (total < buckets) {
    total = total * (k + 1);       
    res++;
  }
  
  return res;
};