/**
 * @param {number[]} A
 * @return {number}
 */
function longestMountain(a) {
  let longestMountainLength = 0;
  let mountainFrom = a.length;

  for (let i = 1; i < a.length; ++i) {
    const beforePrevious = i >= 2 ? a[i - 2] : Infinity;
    const previous = a[i - 1];
    const current = a[i];

    // update mountainFrom to before when the previous is the foot of a mountain
    if (current > previous && previous <= beforePrevious) {
      mountainFrom = i - 1;
      continue;
    }

    // update mountainFrom to current when there's flat terrain between current and beforePrevious
    if (current === previous || beforePrevious === previous) {
      mountainFrom = i;
      continue;
    }

    // start counting mountain length in down trend
    if (current < previous) {
      longestMountainLength = Math.max(longestMountainLength, i - mountainFrom + 1);
    }
  }

  return longestMountainLength >= 3 ? longestMountainLength : 0;
}

//Third fastest
var longestMountain = function (A) {
    let maxLength = 0;
  
    for (let i = 1; i < A.length - 1; i++) {
      if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
        let left = i;
        while (left - 1 >= 0 && A[left] > A[left - 1]) {
          left--;
        }
  
        let right = i;
        while (right + 1 < A.length && A[right] > A[right + 1]) {
          right++;
        }
  
        maxLength = Math.max(maxLength, right - left + 1);
      }
    }
  
    return maxLength >= 3 ? maxLength : 0;
  };

//Second fastest
var longestMountain = function(A) {
    if (A.length < 3) return 0
  let max = 0;
  let startIdx = -1;

  for (let i = 1; i < A.length; i++) {
      if (A[i] > A[i - 1] && startIdx < 0) {
          startIdx = i - 1;
      }else if (A[i] === A[i - 1] ) { 
          startIdx = -1;
      }
        else if(A[i] === A[i - 1] && A[i] < A[i + 1]) {
          startIdx = i
      }
      else if (A[i] <= A[i - 1] && startIdx >= 0) {
          max = Math.max(max, i - startIdx + 1);
          if (A[i] < A[i + 1]){
              startIdx = i;
          }
      }
  }
  return max;

};

//Fastest
var longestMountain = function(A) {
    
    if(A.length <3) {
        return 0
    }
   
    let max = 0
    let count =0
    let i = 0
    while(i < A.length -1){
        let peak = false
        count = 0
        // start uphill
        if(A[i] < A[i+1]) {
            /// climb until peak
          while(A[i] < A[i+1]) {
            i++
            count++
          } 
            if(i+1 < A.length) {
                peak = true
                count++
            }

            // descend until valley
          while(A[i] > A[i+1]) {
            i++
            count++
          } 
            // count            
            if(count >=3 && peak){
                max = Math.max(max, count)
            }
     
        }else{
            i++
        }
 
    }
    return max
};