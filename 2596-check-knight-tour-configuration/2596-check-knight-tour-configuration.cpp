class Solution {
public:
    int dx[8]={2,2,1,1,-1,-1,-2,-2};
    int dy[8]={-1,1,-2,2,-2,2,-1,1};
    int move=1;
    
    bool bfs(int x, int y, vector<vector<int>> grid, int curr, vector<vector<bool>> visited){
        queue <pair<int, int>> q;
        q.push({x,y});
        visited[x][y]=true;
        int move=0;
        while(!q.empty()){
            pair<int,int>top=q.front();
            q.pop();
            int tx=top.first;
            int ty=top.second;
            for(int i=0;i<8;i++){
                int nx=tx+dx[i];
                int ny=ty+dy[i];
                if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]==move+1 && visited[nx][ny]==false){
                    move++;
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                    }
                }
        }
        if(move==grid.size()*grid[0].size()-1) return true;
        else return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int x=0;
        int y=0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
        return bfs(x,y,grid,0,visited);
    }
};