//https://leetcode.com/problems/spiral-matrix-ii/discuss/226581/JavaScript
var generateMatrix = function(n) {
  const arr = [];
  for (let i = 0; i < n; i++) {
    arr[i] = [];
    for (let j = 0; j < n; j++) {
      arr[i][j] = 0;
    }
  }
  
  let k = 1;
  const dirs = ['right', 'down', 'left', 'up'];
  const func = (i=0, j=0, dir=0) => {
    if (k > n * n) return;
    if (dirs[dir % 4] === 'right') {
      while (arr[i] && arr[i][j] === 0) {
        arr[i][j++] = k++;
      }
      func(i + 1, j - 1, dir + 1);
    } else if (dirs[dir % 4] === 'down') {
      while (arr[i] && arr[i][j] === 0) {
        arr[i++][j] = k++;
      }
      func(i - 1, j - 1, dir + 1);
    } else if (dirs[dir % 4] === 'left') {
      while (arr[i] && arr[i][j] === 0) {
        arr[i][j--] = k++;
      }
      func(i - 1, j + 1, dir + 1);
    } else {
      while (arr[i] && arr[i][j] === 0) {
        arr[i--][j] = k++;
      }
      func(i + 1, j + 1, dir + 1);
    }
  }
  
  func();
  
  return arr;
};

//Third fastest
/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    if (n === 1) return [[1]];
  
    let colLeft = 0;
    let colRight = n - 1;
    let rowTop = 0;
    let rowBot = n - 1;
    let matrix = Array(n).fill(null).map(() => Array(n).fill(0));
    let count = 1;
    while (colLeft < colRight && rowTop < rowBot) {
      // Top
      for (let i = colLeft; i < colRight; i++) {
        matrix[rowTop][i] = count;
        count++;
      }
      // Right
      for (let i = rowTop; i < rowBot; i++) {
        matrix[i][colRight] = count;
        count++;
      }
      // Bot
      for (let i = colRight; i > colLeft; i--) {
        matrix[rowBot][i] = count;
        count++;
      }
      // Left
      for (let i = rowBot; i > rowTop; i--) {
        matrix[i][colLeft] = count;
        count++;
      }
      colLeft++; colRight--; rowTop++; rowBot--;
    }
    if (n % 2 !== 0) matrix[(n-1)/2][(n-1)/2] = count;
    return matrix
  };

//Second fastest
/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    if(n < 1)return n;
    
    let matrix = [];
    for(let i = 0; i < n; i ++) matrix.push(new Array(n))
    
    let number = 1;
    let top = 0;
    let down = n - 1;
    let left = 0;
    let right = n - 1;
    let direction = 0;
    
    while(number <= n * n){
        if(direction === 0){
            for( i = left; i <= right; i++){
                matrix[top][i] = number  ++;
            }
            top ++;
        } else if(direction === 1){
            for( i = top; i <= down; i++){
                matrix[i][right] = number ++;
            }
             right--;
        } else  if(direction === 2){
            for( i = right; i >= left; i--){
                matrix[down][i] = number ++;
             }
            down --;
        } else if(direction === 3){
            for( i = down; i >= top; i--){
                matrix[i][left] = number  ++;
            }
            left++;
        }
        direction = (direction + 1) % 4
    }
    
    return matrix
};

//Fastset
/**
 * @param {number} n
 * @return {number[][]}
 */

const generateMatrix = (n) => {
    const matrix = Array.from({length: n}, () => Array(n).fill(null));
    const dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    const steps = [n, n - 1];
    
    let num = 1;
    let dir = 0;
    let i = 0;
    let j = -1;
   
    while (steps[dir % 2] > 0) {
        for (let k = 0; k < steps[dir % 2]; k++) {
            i += dirs[dir][0];
            j += dirs[dir][1];
            matrix[i][j] = num++;
        }
        steps[dir % 2]--;
        dir = (dir + 1) % 4;
    }
    return matrix;
};