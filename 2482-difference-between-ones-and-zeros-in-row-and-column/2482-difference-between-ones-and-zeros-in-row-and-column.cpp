class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<int> rowVal;
        vector<int> colVal;
        int row=grid[0].size();
        int col=grid.size();
        for(int i=0;i<col;i++){
            int cnt1=count(grid[i].begin(), grid[i].end(), 1);
            int cnt0=count(grid[i].begin(), grid[i].end(), 0);
            int res=cnt1-cnt0;
            rowVal.push_back(res);
        }
        
        for(int i=0;i<row;i++){
            int cnt1=0;
            int cnt0=0;
            for(int j=0;j<col;j++){
                if(grid[j][i]==1){
                    cnt1++;
                }
                else if(grid[j][i]==0){
                    cnt0++;
                }
            }
            int res=cnt1-cnt0;
            colVal.push_back(res);
        }
        
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                tmp.push_back(rowVal[i]+colVal[j]);
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};