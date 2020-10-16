var searchMatrix = function(matrix, target) {
    if(!matrix.length) return false;
    
    let start = 0;
    let end = matrix.length - 1;
    let midRow = Math.floor((start + end)/2);
    
    // Binary search along first col of each row
    while(start <= end) {
        midRow = Math.floor((start + end)/2);
        if(matrix[midRow][0] === target) return true;
        else if(target < matrix[midRow][0]) end = midRow-1;
        else start = midRow+1;
    }
    
    if(matrix[midRow][0] > target) midRow--;
    if(midRow < 0) return false;
    
    start = 0;
    end = matrix[midRow].length - 1;
    
    // Binary search on cols of target row
    while(start <= end) {
        const midCol = Math.floor((start + end)/2);
        if(matrix[midRow][midCol] === target) return true;
        else if(target < matrix[midRow][midCol]) end = midCol-1;
        else start = midCol+1;
    }
    return false;
};

//Fourth fastest
var searchMatrix = function(matrix, target) {
    if(!matrix || matrix.length === 0) {
        return false;
    }
    let totalCells = matrix.length * matrix[0].length - 1;
    let left = 0; 
    let right = totalCells;
    
    while(left <= right) {
        let mid = Math.floor((left+ right)/2);
        let row = Math.floor(mid / matrix[0].length);
        let col = mid % matrix[0].length;
        let pivotElement = matrix[row][col];
        if(pivotElement === target) {
            return true;
        }
        if(pivotElement > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
};

//Third fastest
var searchMatrix = function(matrix, target) {
    if(matrix.length === 0 || matrix[0].length === 0 || target < matrix[0][0]) {
        return false
    }
    
    // Select row
    let row = null
    for(let i = 0; i < matrix.length - 1; ++i) {
        if(target >= matrix[i][0] && target < matrix[i+1][0]) {
            row = i
            break
        }
    }
    if(row === null) {
        row = matrix.length - 1
    }
    
    // Search row
    for(let j = 0; j < matrix[row].length; ++j) {
        if(matrix[row][j] === target) {
            return true
        }
    }
    return false;
};

//Second fastest
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    if(matrix.length === 0) return false;
    if(matrix[0].length === 0) return false;
    
    let row = 0;
    
    let left = 0;
    let right = matrix.length - 1;
    
    while(left <= right) {
        const middle = Math.floor((left + right) / 2);
        if(matrix[middle][0] <= target && matrix[middle][matrix[middle].length - 1] >= target) {
            row = middle;
            break;
        }
        if(matrix[middle][0] < target) left = middle + 1;
        else if(matrix[middle][0] > target) right = middle - 1;
    }

    left = 0;
    right = matrix[row].length - 1;
    
    const foundRow = matrix[row];
    
    while(left <= right) {
        const center = Math.floor((left + right) / 2);
        if(foundRow[center] === target) return true;
        if(foundRow[center] < target) left = center + 1;
        else if(foundRow[center] > target) right = center - 1;
    }
    
    return false
};

//Fastest
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    if (matrix.length === 0) {
        return false;
    } else if (matrix.length === 1) {
        return matrix[0].some(val => val === target);
    } else {
        // loop through matrix, and find the array
        for (let m = 0; m < matrix.length; m++) {
            if (matrix[m][0] > target && m === 0) {
                return matrix[0].some(val => val === target);
            }
            
            if (matrix[m][0] > target) {
                return matrix[m - 1].some(val => val === target);
                
            }
            
            if (matrix[m][0] <= target && m === matrix.length - 1) {
                return matrix[m].some(val => val === target);
            }
        }    
    }
};