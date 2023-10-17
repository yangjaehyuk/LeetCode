class Solution {
public:
    int maxi=0;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int visited[51][51]={0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    int cnt=1;
                    queue<pair<int,int>> q;
                    grid[i][j]=0;
                    visited[i][j]=1;
                    q.push({i,j});
                    while(!q.empty()){
                        int front=q.front().first;
                        int back=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nx=front+dx[k];
                            int ny=back+dy[k];
                            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1 && visited[nx][ny]==0){
                                q.push({nx,ny});
                                grid[nx][ny]=0;
                                visited[nx][ny]=1;
                                cnt++;
                            }
                        }
                    }
                    maxi=max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};