class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0,iter=-1;
        vector<vector<int>>grid2=grid;
        do
        {
            
            iter++;
            count=0;
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(grid[i][j]==2)
                    {
                        if(i>0 &&grid[i-1][j]==1)
                        {
                            grid2[i-1][j]=2;
                            count++;
                        }
                        if(i<grid.size()-1 &&grid[i+1][j]==1)
                        {
                            grid2[i+1][j]=2;
                            count++;
                        }    
                        
                        if(j>0 &&grid[i][j-1]==1)
                        {   
                            grid2[i][j-1]=2;
                            count++;
                        }
                        
                        if(j<grid[0].size()-1 &&grid[i][j+1]==1)
                        {    
                            grid2[i][j+1]=2;
                            count++;
                        }
                        
                    }
                }
            }
            grid=grid2;
            
            
            
        }while(count!=0);
        
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        iter=-1;
                        break;
                            
                    }
                }
            }
        
        return iter;
    }
};

//BFS
class Solution {
public:
    int dx[4]={-1,1,0,0,};
    int dy[4]={0,0,-1,1};
    
    vector<vector<int>> grd;
    int ans=0,n,m;
    
    void bfs(){
        queue<pair<int,int>> qu;
        
        //pushing every rotten orange in queue
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grd[i][j]==2) qu.push({i,j});
        
        while(!qu.empty()){
            int sz=qu.size();
            //pushed is used to know whether next level of fresh oranges (next layer of bfs) are there
            bool pushed=false;
            
            //loop used to traverse all rotten oranges which are in queue
            for(int i=0;i<sz;i++){
                int x=qu.front().first,y=qu.front().second;
                qu.pop();
                for(int k=0;k<4;k++){
                    //if coordinates are invalid then skip
                    if(x+dx[k]<0 or y+dy[k]<0 or x+dx[k]>=grd.size() or y+dy[k]>=grd[0].size()) continue;
                    //if they are and valid and we encounter fresh orange then push that into queue
                    if(grd[x+dx[k]][y+dy[k]]==1){
                        //pushed is also made true confirming there is another layer also
                        qu.push({x+dx[k],y+dy[k]}),pushed=true;
                        //fresh orange converted into rotten orange 
                        grd[x+dx[k]][y+dy[k]]=2;    
                    } 
                }
            }
            //confirming that this is not last layer and increamenting ans
            if(pushed) ans++;
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        grd=grid,n=grd.size(),m=grd[0].size();
        //breadth first search over the grid
        bfs();
        //if there is still some fresh oranges return -1 else return the ans
        for(auto it:grd) for(auto jt:it) if(jt==1) return -1;
        return ans;
    }
};

//Fastest
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0,iter=-1;
        vector<vector<int>>grid2=grid;
        do
        {
            
            iter++;
            count=0;
            for(int i=0;i<grid.size();i++)
            {
                //cout<<"\n";
                for(int j=0;j<grid[0].size();j++)
                {
                    //cout<<grid[i][j]<<" ";
                    if(grid[i][j]==2)
                    {
                        if(i>0 &&grid[i-1][j]==1)
                        {
                            grid2[i-1][j]=2;
                            count++;
                        }
                        if(i<grid.size()-1 &&grid[i+1][j]==1)
                        {
                            grid2[i+1][j]=2;
                            count++;
                        }    
                        
                        if(j>0 &&grid[i][j-1]==1)
                        {   
                            grid2[i][j-1]=2;
                            count++;
                        }
                        
                        if(j<grid[0].size()-1 &&grid[i][j+1]==1)
                        {    
                            grid2[i][j+1]=2;
                            count++;
                        }
                        
                    }
                }
            }
            grid=grid2;
            
            
            
        }while(count!=0);
        
        cout<<"\nNew:";
            for(int i=0;i<grid.size();i++)
            {
                cout<<"\n";
                for(int j=0;j<grid[0].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        iter=-1;
                        break;
                            
                    }
                }
            }
        
        return iter;
    }
};