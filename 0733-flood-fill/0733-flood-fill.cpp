class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int arr[51][51]={0};
    int cnt=0;
    vector<vector<int>> ans;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int num=image[sr][sc];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(image[i][j]==num && arr[sr][sc]==-1 && cnt==0){
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push({sr,sc});
                    arr[sr][sc]=image[sr][sc];
                    while(!q.empty()){
                        int front=q.front().first;
                        int back=q.front().second;
                        
                        q.pop();
                        
                        for(int k=0;k<4;k++){
                            int nx=front+dx[k];
                            int ny=back+dy[k];
                            
                            if(nx>=0 && ny>=0 && nx<n && ny<m && image[nx][ny]==num && arr[nx][ny]==-1){
                                q.push({nx,ny});
                                arr[nx][ny]=image[sr][sc];
                            }
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==image[sr][sc]) arr[i][j]=color;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==color){
                    image[i][j]=arr[i][j];
                }
            }
        }
        
        
        return image;
    }
};