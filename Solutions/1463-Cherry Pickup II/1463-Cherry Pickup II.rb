#https://leetcode.com/problems/cherry-pickup-ii/discuss/977763/Ruby-DFS
# @param {Integer[][]} grid
# @return {Integer}
def cherry_pickup(grid)
  @grid = grid
  @rows = grid.count
  @cols = grid[0].count
  @cache = {}
  
  dfs(0, 0, 0, @cols-1)
end

def get_next_pos(i, j)
  pos = [[i + 1, j]]
  pos << [i + 1, j - 1] if j - 1 >= 0
  pos << [i + 1, j + 1] if j + 1 < @cols
  pos
end
        
def dfs(i1, j1, i2, j2)
  cached = @cache[[i1, j1, i2, j2]]
  return cached if cached
  
  current_cherries = @grid[i1][j1]
  current_cherries += @grid[i2][j2] if i2 != i1 || j2 != j1
  return current_cherries if i1 == @rows - 1 || i2 == @rows - 1

  next_pos1 = get_next_pos(i1, j1)
  next_pos2 = get_next_pos(i2, j2)

  next_cherries = 0
  next_pos1.each do |next_i1, next_j1|
    next_pos2.each do |next_i2, next_j2|
      next_cherries = [
        next_cherries,
        dfs(next_i1, next_j1, next_i2, next_j2)
      ].max
    end
  end

  @cache[[i1, j1, i2, j2]] = next_cherries + current_cherries
end

#Faster
#https://leetcode.com/problems/cherry-pickup-ii/discuss/977861/Ruby-Dynamic-programming-O(n3)-time-O(n2)-space
def cherry_pickup(grid)
    m = grid.size; n = grid[0].size
    dp = Array.new(n) { Array.new(n, -Float::INFINITY) }
    dp[0][n - 1] = grid[0][0] + grid[0][n - 1]
    for row in grid[1...m]
      dp = (0...n).map do |i|
        (0...n).map do |j|
          [i - 1, i, i + 1].product([j - 1, j, j + 1]).
            filter_map { |(i, j)| dp[i][j] if valid?(i, j, n) }.max +
          [i, j].uniq.sum { |i| row[i] }
        end
      end
    end
    dp.flatten.max
  end
  
  def valid?(i, j, n)
    0 <= i && i < n && 0 <= j && j < n
  end
  # Time: O(N**3)
  # Space: O(N**2)
  # Runtime: 2040 ms