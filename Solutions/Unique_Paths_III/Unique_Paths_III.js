const dirs = [ [0, 1], [1, 0], [-1, 0], [0, -1] ];

const uniquePathsIII = grid => {
    let res = 0, traversable = 1, sx, sy;
    let m = grid.length, n = grid[0].length;
    
    for (let i = 0; i < m; i++)
        for (let j = 0; j < n; j++)
            if (grid[i][j] === 0)
                traversable++;
            else if (grid[i][j] === 1)
                sx = i, sy = j;

    dfs(sx, sy);
    
    return res;

    function dfs(r, c) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] < 0)
            return;

        if (grid[r][c] === 2)
            return res += !traversable;

        grid[r][c] = -2, traversable--;

        for (let [dR, dC] of dirs)
            dfs(r + dR, c + dC);

        grid[r][c] = 0, traversable++;
    }
};

//Fastest
/**
 * @param {number[][]} grid
 * @return {number}
 */
var uniquePathsIII = function(board) {
  let n = board.length;
  let m = board[0].length;
  let count = 0;
  
  // Pre-process board (count zeroes, find x,y start)
  let startX = 0
  let startY = 0;
  let zeroes = 1;
  for (let x = 0; x < n; x++) {
    for (let y = 0; y < m; y++) {
      if (board[x][y] === 0) zeroes += 1;
      if (board[x][y] === 1) {
        startX = x;
        startY = y;
      }
    } 
  }
  
  const dfs = (x, y, zeroes) => {
    if (x < 0 || x >= n) return;
    if (y < 0 || y >= m) return;
    if (board[x][y] === -1) return;
    
    //  if we reach the end with 0 zeroes left, add to path count
    if (board[x][y] === 2) {
      if (zeroes === 0) count += 1;
      return;
    }
    
    //  mark node as -1
    //  dfs in all 4 directions
    let orig = board[x][y];
    board[x][y] = -1;
    
    dfs(x + 1, y, zeroes - 1);
    dfs(x - 1, y, zeroes - 1);
    dfs(x, y + 1, zeroes - 1);
    dfs(x, y - 1, zeroes - 1);
    
    board[x][y] = orig;
  }
  
  // Recursively DFS from x,y of start
  dfs(startX, startY, zeroes);
  
  return count;
}