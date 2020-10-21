//Third fastest
/**
 * @param {number[]} asteroids
 * @return {number[]}
 */
var asteroidCollision = function(asteroids) {
    if(asteroids.length <= 1) {
        return asteroids;
    }
    let sign = Math.sign(asteroids[0]) // flag value for positive
    let result = [];
    let i = 0;
    while(i < asteroids.length) {
        if (Math.sign(asteroids[i]) != sign && sign > 0) {
            if (result.length > 0) {
                let len = result.length -1;
                if (result[len] < Math.abs(asteroids[i])) {
                    result.pop();
                    sign = Math.sign(result[len-1]);
                } else if(result[len] == Math.abs(asteroids[i])){
                    result.pop();
                    sign = Math.sign(result[len-1]);
                    i++;
                } else {
                    i++;
                }    
            } else {
                result.push(asteroids[i]);
                sign = Math.sign(asteroids[i]);
                i++;
            }
        } else {
            result.push(asteroids[i]);
            sign = Math.sign(asteroids[i]);
            i++;
        }

    }

    return result;
    
};

//Second fastest
/**
 * @param {number[]} asteroids
 * @return {number[]}
 */
var asteroidCollision = function(asteroids) {
    let stack = [asteroids[0]]
    for (let i = 1; i < asteroids.length; i++) {
        if ( stack.length === 0 || asteroids[i] > 0 ) {
            stack.push(asteroids[i]);
        } else {
            while (stack.length) {
                let ele = stack.pop();
                
                if (ele < 0) {
                    stack.push(ele);
                    stack.push(asteroids[i]);
                    break;
                } else if (ele === Math.abs(asteroids[i])) {
                    break;
                } else if (ele > Math.abs(asteroids[i])) {
                    stack.push(ele);
                    break;
                } else {
                    if (stack.length === 0) {
                        stack.push(asteroids[i]);
                        break;
                    }
                }
            }
        }
    }
    return stack;
};

// [5, 10, -5]
// [8, -8]
// [10, 2, -5]
// [-2, -1, 1, 2]

//Fastest
var asteroidCollision = function(asteroids) {
  let result = [];
  let i = 0;
  
  while (i < asteroids.length) {
    let lastElem = result[result.length - 1];
    let sum = lastElem + asteroids[i];
    if (result.length === 0 || lastElem < 0) {
      result.push(asteroids[i]);
      i++;
    } else if (lastElem > 0 && asteroids[i] < 0) {
      if (sum === 0) {
        result.pop();
        i++;
      } else if (sum > 0) {
        i++;
      } else if (sum < 0) {
        result.pop();
      }
    } else {
      result.push(asteroids[i]);
      i++;
    }
  }
  return result;
};