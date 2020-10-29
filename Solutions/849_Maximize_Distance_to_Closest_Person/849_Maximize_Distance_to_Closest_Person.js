//Fifth fastest
let maxDistToClosest = (seats) =>{
    let count = 0;
    let maxCount = -Infinity;
	//the max length if zeros are between ones will be count/2
    for(let i=0;i<seats.length;i++){
        if(seats[i] === 0){
            count++;
        }
        else{
            maxCount = Math.max(maxCount,Math.ceil(count/2));
            count = 0;
        }
    }
    //updating maxcount for the end
    maxCount = Math.max(maxCount,Math.ceil(count/2));
    
    //check for the starting 
    for(let i=0;i<seats.length;i++){
        if(seats[i] === 1){
            maxCount = Math.max(maxCount, i);
            break;
        }
    }
    
    //check for the last
	//lCount checks number of zeros from the last
    let lCount = 0;
    for(let i=seats.length-1; i>=0;i--){
        if(seats[i] === 1){
           maxCount =  Math.max(maxCount,lCount);
            break;
        }
        else{
            lCount++;
        }
    }
    return maxCount;
}

//Fourth fastest
/**
 * @param {number[]} seats
 * @return {number}
 */
var maxDistToClosest = function(seats) {  
    let max = -Infinity
    for(let i = 0; i < seats.length; i++) {
        if(seats[i] === 0) {
            let left = i-1
            let right = i + 1
            
            while(left >= 0 && seats[left] === 0 || right < seats.length && seats[right] === 0) {
                if(left >= 0 && seats[left] === 0) {
                    left--
                }
                
                if(right < seats.length && seats[right] === 0) {
                    right++
                }
            }
            
            if(right > seats.length-1 || left < 0) {
                max = Math.max(max, right-left-1)
            } else {
                max = Math.max(max, Math.min(i-left, right-i))
            }
        }
    }
    
    return max
};

//Third fastest
var maxDistToClosest = function(seats) {
    const occupied = [];
    for(let i = 0; i<seats.length; i++){
        if(seats[i] === 1) occupied.push(i);
    }
    let max = occupied[0] - 0;
    for(let i = 1; i<occupied.length; i++){
        const pre = occupied[i-1], curr = occupied[i];
        max = Math.max(max, ~~((curr-pre)/2))
    }
    max = Math.max(seats.length-1 - occupied[occupied.length-1], max)
    
    return max
};

//Second fastest
/**
 * @param {number[]} seats
 * @return {number}
 */
// O(n) ST
var maxDistToClosest = function (seats) {
    // create an array with the values of subsequent zeros
    const aggSeatsArr = [];
    for (const seat of seats) {
        if (aggSeatsArr.length === 0) aggSeatsArr.push([seat, 1]);
        else {
            if (seat === aggSeatsArr[aggSeatsArr.length - 1][0])
                ++aggSeatsArr[aggSeatsArr.length - 1][1];
            else aggSeatsArr.push([seat, 1]);
        }
    }

    let max = -1;
    for (let i = 0; i < aggSeatsArr.length; ++i) {
        let closestDist;
        if (aggSeatsArr[i][0] === 0) {
            if (i - 1 >= 0) closestDist = 1;
            else closestDist = aggSeatsArr[i][1];

            if (i + 1 >= aggSeatsArr.length)
                closestDist = Math.max(closestDist, aggSeatsArr[i][1]);

            if (i - 1 >= 0 && i + 1 < aggSeatsArr.length) {
                closestDist = Math.ceil(aggSeatsArr[i][1] / 2);
            }
            max = Math.max(max, closestDist);
        }
    }
    return max;
};

//Fastest
/**
 * @param {number[]} seats
 * @return {number}
 */
var maxDistToClosest = function (seats) {
  // initialize variable for longest longest distance
  let longestDistance = 0;

  // initialize counter for distance to previous '1' to infinity
  let distPrevSeat = Infinity;

  // iterate through the array
  for (let i = 0; i <= seats.length - 1; i++) {
    // if you encounter a 1 --> reset counter for distance to previous 1 to 0
    if (seats[i] === 1) {
      distPrevSeat = 0;
    } else if (seats[i] === 0) {
      // if you encounter a 0 -->
      //  increment counter of distance to previous 1
      distPrevSeat++;
      // intitalize variable to keep track of distance to next 1
      let distNextSeat = 0;
      // initialize variable to keep track of whether a 1 has been found
      let hasBeenFound = false;
      //  iterate through array from current index through the rest of the array
      for (let j = i + 1; j <= seats.length - 1; j++) {
        // increment counter by 1
        distNextSeat++;
        // if 1 is found --> set hasBeenFound variable to true and break
        if (seats[j] === 1) {
          hasBeenFound = true;
          break;
        }
      }
      // if hasBeenFound is false then set counter to infinitue
      if (!hasBeenFound) distNextSeat = Infinity;
      // take min of counter to previous 1 and counter to next 1
      let finalDist = Math.min(distPrevSeat, distNextSeat);
      // if result is greater than the variable tracking the longest distance, overwrite that variable with the new distance
      if (finalDist > longestDistance) longestDistance = finalDist;
    }
  }
  // return tracker variable for the longest distance
  return longestDistance;
};