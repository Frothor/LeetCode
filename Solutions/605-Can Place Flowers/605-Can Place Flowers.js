//
/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function (flowerbed, n) {
  let left = n, i = 0
  while (i < flowerbed.length) {
    if (flowerbed[i]) {
      i += 2
      continue
    }
    if (flowerbed[i - 1]) continue
    if (flowerbed[i + 1]) {
      i += 3
      continue
    }
    // flowerbed[i] = true
    left--
    i += 2
  }
  return left <= 0
};

//Fourth fastest
const canPlaceFlowers = function (flowerbed, n) {
    if (n === 0) {
        return true;
    }
    //length is 1
    if (flowerbed.length === 1) {
        return n <= 1 && flowerbed[0] === 0;
    }

    for (let i = 0; i < flowerbed.length && n > 0; i++) {
        if (i === 0 && flowerbed[0] === 0 && flowerbed[1] === 0) {
            flowerbed[i] = 1;
            i++;
            n--;
            continue;
        }

        if (i === flowerbed.length - 1 && flowerbed[i] === 0 && flowerbed[i + 1] === 0) {
            flowerbed[i] = 1;
            i++;
            n--;
            continue;
        }

        while (flowerbed[i - 1] === 1 || flowerbed[i] === 1 || flowerbed[i + 1] === 1 && i < flowerbed.length) {
            i++;
            if (i === flowerbed.length - 1) {
                break;
            }
        }

        if (i !== flowerbed.length - 1 &&
            flowerbed[i - 1] === 0 &&
            flowerbed[i] === 0 &&
            flowerbed[i + 1] === 0
        ) {
            flowerbed[i] = 1;
            i++;
            n--;
            continue;
        }

        if (i === flowerbed.length - 1 && flowerbed[i] === 0 && flowerbed[i - 1] === 0) {
            flowerbed[i] = 1;
            i++;
            n--;
            continue;
        }
    }

    return n <= 0;
};

//Third fastest
var canPlaceFlowers = function (flowerbed, n) {
    var canPlantedNum = 0;
    flowerbed.push(0);
    flowerbed.reduce((pre, cur) => {
      if (cur === 0) {
        if (pre === 2) {
          canPlantedNum++;
          return 1;
        }
        return pre + 1;
      }
      if (cur === 1) {
        return 0;
      }
    }, 1);
    return n <= canPlantedNum;
  };

//Second fastest
var canPlaceFlowers = function(flowerbed, n) {
    let count = 0
    for (let i = 0; i < flowerbed.length; i++){
        if (flowerbed[i] === 0 && (flowerbed[i-1] === 0 || i === 0) && (flowerbed[i+1] === 0 ||     i === flowerbed.length-1)){
            flowerbed[i]=1
            count++
        }
    }
    if(count >= n){
        return true
    }
    return false
};

//Fastest
/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
   let result = 0;
      if (flowerbed[0]===0 && flowerbed[1] === 0){ 
            result++;
            flowerbed[0] = 1;
        } 
     if (flowerbed[flowerbed.length-1]===0 && flowerbed[flowerbed.length-2] === 0){ 
            result++;
            flowerbed[flowerbed.length-1] = 1;
        }
   if (flowerbed.length === 1 && flowerbed[0] === 0) return true
   flowerbed.forEach((el, i, arr) => {
        if (el === 0 && arr[i-1] === 0 && arr[i+1] === 0 ) { 
            result++;
            arr[i] = 1;
        } 
   }) 
    return result >= n
};