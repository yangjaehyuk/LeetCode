class Solution {
public:
    int groupcnt=0;
    int count=0;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    
    int arr[301][301];
    int boss[100001];
    
    int find(int n){
        if(boss[n]==0) return n;
        return boss[n]=find(boss[n]);
    }
    
    void setUnion(int t1, int t2){
        
        int a=find(t1);
        int b=find(t2);
        if(a==b) return;
        
        boss[b]=a;
        groupcnt++;
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt=1;

        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]-='0';
                arr[i][j]=grid[i][j];
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1){
                    arr[i][j]=cnt;
                    cnt++;
                    count++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]!=0){
                    for(int k=0;k<4;k++){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                        if(arr[nx][ny]==0) continue;
                        setUnion(arr[i][j], arr[nx][ny]);
                    }
                }
            }
        }
        return count-groupcnt;
    }
};