class Solution {
public:
    int dx[8]={-1,1,0,0,-1,1,1,-1};
    int dy[8]={0,0,-1,1,1,1,-1,-1};
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> arr;
        vector<int> subarr;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                subarr.push_back(0);
            }
            arr.push_back(subarr);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                int cnt=0;
                for(int k=0;k<8;k++){
                    int ndx=i+dx[k];
                    int ndy=j+dy[k];
                    if(ndx<0 || ndx>=board.size() || ndy<0 || ndy>=board[i].size()) continue;
                    if(board[ndx][ndy]==1) cnt++;
                }
                if(board[i][j]==0){
                    if(cnt==3) arr[i][j]=1;
                }
                else{
                    if(cnt<2) arr[i][j]=0;
                    else if(cnt==2 || cnt==3) arr[i][j]=1;
                    else if(cnt>3) arr[i][j]=0;
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                board[i][j]=arr[i][j];
            }
        }
    }
};