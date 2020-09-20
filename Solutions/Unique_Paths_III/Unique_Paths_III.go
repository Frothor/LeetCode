func uniquePathsIII(grid [][]int) int {
    zeros:=0
    sx,sy:=0,0
    for i:=0;i<len(grid);i++{
        for j:=0;j<len(grid[0]);j++{
            if grid[i][j]==0{
                zeros+=1
            } else if grid[i][j]==1{
                sx,sy=i,j
            }
        }
    }
    
    res:=0
    
    var dfs func(int,int,int)
    dfs=func(px,py,path int){
        directions:=[][]int{{0,1},{1,0},{0,-1},{-1,0}}
        
        for _,d:=range directions {
            newX,newY:=px+d[0],py+d[1]
            if newX>=0 && newX<len(grid) && newY>=0 && newY<len(grid[0]){
                if grid[newX][newY]==0 {
                    grid[newX][newY]=3
                    dfs(newX,newY,path+1)
                    //backtrack
                    grid[newX][newY]=0
                }
                if grid[newX][newY]==2 && path==zeros{
                    res+=1
                }
            }
        }
    }
    dfs(sx,sy,0)
    
    return res
}

//Another
func dfs(grid, visited *[][]int, x, y, steps, totalTraversable int, result *int){
    if x < 0 || y < 0 || x >= len((*grid)[0]) || y >= len(*grid) || (*grid)[y][x] == -1 || (*visited)[y][x] == -1{
        return
    }

    if steps + 1 == totalTraversable && (*grid)[y][x] == 2 {
        *result++
        return
    }else if (*grid)[y][x] == 2{
        return
    }
    
    steps++
    (*visited)[y][x] = -1
    dfs(grid, visited, x+1, y, steps, totalTraversable, result)
    dfs(grid, visited, x, y+1, steps, totalTraversable, result)
    dfs(grid, visited, x, y-1, steps, totalTraversable, result)
    dfs(grid, visited, x-1, y, steps, totalTraversable, result)
    // backtrack
    (*visited)[y][x] = 0
    steps--
}

func uniquePathsIII(grid [][]int) int {
    var startX, startY, result int
    m := len(grid)
    n := len(grid[0])
    totalTraversable := m*n
    
    visited := make([][]int, m)
    
    for i:=0; i<m;i++{
        visited[i] = make([]int, n)
        for j:=0; j<n;j++{
            if grid[i][j] == 1{
                startX = j
                startY = i
            }else if grid[i][j] == -1{
                totalTraversable--
            }
        }
    }
    dfs(&grid, &visited, startX, startY, 0, totalTraversable, &result)
    return result
}