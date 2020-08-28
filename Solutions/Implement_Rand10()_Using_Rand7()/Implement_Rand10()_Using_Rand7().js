var rand10 = function() {
  let i = 7;
  let j = 6;
  while (i > 6) i = rand7(); // i could be 1, 2, 3, 4, 5, or 6
  while (j > 5) j = rand7(); // j could be 1, 2, 3, 4, or 5
  if (i % 2 === 0) { // if i end up being even (50% the chance because it could be 2, 4, 6)
    return j; // return 1, 2, 3, 4, or 5
  } else { //if i end up being odd (also 50% of the chance because it could be 1, 3, 5)
    return j + 5; // return 6, 7, 8, 9, or 10
  }
};

//Fastest
var rand10 = function() {
    
    let idx = -1;
    
    while (true) {
        
        const row = rand7();
        const col = rand7();
        
        idx = col + (row - 1) * 7;
        
        if (idx <= 40) {
            return 1 + (idx - 1) % 10;
        }
    }
};