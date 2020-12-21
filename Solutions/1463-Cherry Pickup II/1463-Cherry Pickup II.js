//
var cherryPickup = function(grid) {
    let cache = new Map()
    function findMax(row, col1, col2) {
        if(row < 0 || row >= grid.length || col1 < 0 || col1 >= grid[0].length || col2 < 0 || col2 >= grid[0].length) {
            return 0
        }
        let stl = `${row}-${col1}-${col2}`
        let c1Val = col1 === col2 ? 0 : grid[row][col1]
        let c2Val = col1 === col2 ? 0 : grid[row][col2]
        if(cache.has(stl)) {
            return c1Val + c2Val + cache.get(stl)
        }
        let maxVal = Math.max(
            findMax(row+1, col1-1, col2-1),
            findMax(row+1, col1-1, col2),
            findMax(row+1, col1-1, col2+1),
            findMax(row+1, col1, col2-1),
            findMax(row+1, col1, col2),
            findMax(row+1, col1, col2+1),
            findMax(row+1, col1+1, col2-1),
            findMax(row+1, col1+1, col2),
            findMax(row+1, col1+1, col2+1),
        )
        cache.set(stl, maxVal)
        return c1Val + c2Val + maxVal
    }
    return findMax(0, 0, grid[0].length-1)
};

//Third fastest
/**
 * @param {number[][]} grid
 * @return {number}
 */
var cherryPickup = function(grid) {
    const _cherryPickup = (row, col1, col2) => {
        if (row === rows) return 0
        
        if (memo[row][col1][col2] !== undefined) {
            return memo[row][col1][col2]
        }
        
        let max = 0
        for (let i = -1; i <= 1; i++) {
            const nextCol1 = i + col1
            if (nextCol1 < 0 || nextCol1 >= cols) continue
            
            for (let j = -1; j <= 1; j++) {
                const nextCol2 = j + col2
                if (nextCol2 < 0 || nextCol2 >= cols) continue
                
                max = Math.max(max, _cherryPickup(row + 1, nextCol1, nextCol2))
            }
        }
        
        max += grid[row][col1]
        if (col1 !== col2) max += grid[row][col2]
        
        memo[row][col2][col1] = max
        memo[row][col1][col2] = max
        return max
    }
    
    const rows = grid.length
    const cols = grid[0].length
    const memo = new Array(rows).fill()
                    .map(a => new Array(cols).fill()
                    .map(a => new Array(cols)))
    
    return _cherryPickup(0, 0, cols - 1)
};

//Second fastest
/**
 * @param {number[][]} grid
 * @return {number}
 */
var cherryPickup = function(g) {
    // f[x][y][z] = max #cherries a robot gets by ending up @x, y coming from z(0 = left, 1=center, 2=right)
    // have f1 for #1 robot, f2 for #2 robot
    // for each value in a row of f1, find max f2
    // analysis:3N^2 
    
    // working solution:
    // f[i][x][y] = max #cherries 2 robots get by ending up at row i, col x and y
    const f = Array(g.length).fill(0).map(x => Array(g[0].length).fill(0).map(x => Array(g[0].length).fill(0)));
    f[0][0][g[0].length-1] = 0 === g[0].length-1 ? g[0][0] : g[0][0] + g[0][g[0].length-1];
    for (let i=1;i<g.length;++i) {
        for (let j=0;j<Math.min(g[0].length, i+1);++j) {
            for (let k=Math.max(0, g[0].length-i-1);k<g[0].length;++k) {
                let p = 0;
                for (let jj=Math.max(0, j-1);jj<=Math.min(g[0].length-1, j+1);++jj) {
                    for (let kk=Math.max(0, k-1);kk<=Math.min(g[0].length-1, k+1);++kk) {
                        p = Math.max(p, f[i-1][jj][kk]);
                    }
                } 
                if (j===k) {
                    f[i][j][k] = p+g[i][j];
                } else {
                    f[i][j][k] = p+g[i][j] + g[i][k];
                }
            }
        }
    }
    
    // console.log(f[g.length-1])
    let ret=0;
    for (let i=0;i<g[0].length;++i) {
        for (let j=0;j<g[0].length;++j) {
            ret=Math.max(ret, f[g.length-1][i][j]);
        }
    }
    return ret;
};

//Fastest
/**
 * @param {number[][]} grid
 * @return {number}
 */
var cherryPickup = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    
    let dpCache = new Array(m);
    
    for(let i = 0; i < dpCache.length; i++){
        dpCache[i] = new Array(n);
        for(let j =0; j < dpCache[0].length; j++){
            dpCache[i][j] = new Array(n);
        }
    }
    
    for(let i=0; i < m; i++){
        for(let j =0; j < n; j++){
            for(let k =0; k < n; k++){
                dpCache[i][j][k] = -1;
            }
        }
    }
    return dp(0,0,n-1, grid, dpCache);
    
};

function dp(row, col1, col2, grid, dpCache){
    if(col1 < 0 || col1 >= grid[0].length || col2<0 || col2 >= grid[0].length){
        return 0;
    }
    //check cache
    if(dpCache[row][col1][col2] != -1){
        return dpCache[row][col1][col2];
    }
    
    //current cell
    let result = 0;
    result += grid[row][col1];
    if(col1 != col2){
        result+= grid[row][col2];
    }
    
    //transition
    if(row != grid.length -1){
        let max = 0;
        for(let newCol1 = col1-1; newCol1<= col1+1; newCol1++){
            for(let newCol2 = col2 -1; newCol2 <= col2 +1; newCol2++){
                max = Math.max(max, dp(row+1, newCol1, newCol2, grid, dpCache));
            }
        }
        result += max;
    }
    
    dpCache[row][col1][col2] = result;
    return result;
}