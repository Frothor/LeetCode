#Third fastest
DIRECTIONS_X = [1, 0, -1, 0]
DIRECTIONS_Y = [0, 1, 0, -1]

def generate_matrix(n)
    result = Array.new(n){Array.new(n, '')}
    
    current_num = 1
    
    fill_matrix(result, current_num, 0, 0, 0, n)
end

def fill_matrix(matr, current_num, x, y, dir_ind, n)
    return matr if current_num > (n*n)
    
    matr[y][x] = current_num
    current_num += 1
    
    next_x = x + DIRECTIONS_X[dir_ind]
    next_y = y + DIRECTIONS_Y[dir_ind]
    next_cell = matr[next_y][next_x] if matr[next_y]
    
    if next_cell != ''
        new_dir = dir_ind + 1
        new_dir = 0 if new_dir > 3
        
        next_x = x + DIRECTIONS_X[new_dir]
        next_y = y + DIRECTIONS_Y[new_dir]
        fill_matrix(matr, current_num, next_x, next_y, new_dir, n)
    else
        fill_matrix(matr, current_num, next_x, next_y, dir_ind, n)
    end
end

#Second fastest
def generate_matrix(n)
    
  result = Array.new(n) { Array.new(n) { Integer(0) } }
  
  y = 0
  x = 0
  result[0][0] = 1
  count = 1
  
  total_cells = n**2
  
  while true do
    DIRS.each do |dir|
      ny = y + dir[0]
      nx = x + dir[1]
      while nx >= 0 && nx < n && ny >= 0 && ny < n && result[ny][nx] == 0
        count += 1
        result[ny][nx] = count
        
        y = ny
        x = nx
        ny = y + dir[0]
        nx = x + dir[1]
      end
    end
    break if count == total_cells
  end
  
  result
end

DIRS = [[0,1], [1,0], [0,-1], [-1,0]]

#Fastest
def next_number()
    @number += 1
    @number
end

def generate_matrix(n)
    m = n
    return [] if m == 0 || n == 0
    matrix = Array.new(m) {Array.new(n)}
    min_row, min_col = 0, 0
    max_row, max_col = m-1, n-1

    @number = 0
    while true
        # right
        (min_col..max_col).each {|col| matrix[min_row][col] = next_number()}
        break if min_row == max_row

        # down
        ((min_row+1)..max_row).each {|row| matrix[row][max_col] = next_number()}
        break if min_col == max_col

        # left
        (min_col..(max_col-1)).reverse_each {|col| matrix[max_row][col] = next_number()}

        # up
        ((min_row+1)..(max_row-1)).reverse_each {|row| matrix[row][min_col] = next_number()}

        min_row += 1
        min_col += 1
        max_col -= 1
        max_row -= 1
        break if min_row > max_row || min_col > max_col
    end
    return matrix
end