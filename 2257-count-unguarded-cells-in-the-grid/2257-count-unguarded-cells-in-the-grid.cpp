class Solution {
public:
    // down up right left
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int cnt=0;
        vector<vector<int>> arr(m, vector<int>(n));
        for(int i=0;i<guards.size();i++){
            arr[guards[i][0]][guards[i][1]]=1;
        }
        for(int i=0;i<walls.size();i++){
            arr[walls[i][0]][walls[i][1]]=2;
        }
        for(int i=0;i<guards.size();i++){
            for(int j=guards[i][0]-1;j>=0;j--){
                // north
                if(arr[j][guards[i][1]]==2 || arr[j][guards[i][1]]==1) break;
                arr[j][guards[i][1]]=3;
            }
            for(int j=guards[i][0]+1;j<m;j++){
                // south
                if(arr[j][guards[i][1]]==2 || arr[j][guards[i][1]]==1) break;
                arr[j][guards[i][1]]=3;
            }
            for(int j=guards[i][1]+1;j<n;j++){
                // east
                if(arr[guards[i][0]][j]==2 || arr[guards[i][0]][j]==1) break;
                arr[guards[i][0]][j]=3;
            }
            for(int j=guards[i][1]-1;j>=0;j--){
                // west
                if(arr[guards[i][0]][j]==2 || arr[guards[i][0]][j]==1) break;
                arr[guards[i][0]][j]=3;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==0) cnt++;
            }
        }
        return cnt;
        
    }
};