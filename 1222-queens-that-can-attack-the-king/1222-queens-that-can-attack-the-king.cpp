class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<pair<int, int>> arr;
        for(int i=0;i<queens.size();i++){
            arr.insert(make_pair(queens[i][0],queens[i][1]));
        }
        vector<vector<int>> ans;
        vector<int> tmp;
        int dx[8]={1,-1,0,0,1,-1,1,-1};
        int dy[8]={0,0,1,-1,1,-1,-1,1};
        int x=king[0];
        int y=king[1];
        for(int i=0;i<8;i++){
            int nx=x;
            int ny=y;
            for(int j=0;j<8;j++){
                nx+=dx[i];
                ny+=dy[i];
                if(nx<0 || nx>=8 || ny<0 || ny>=8) continue;
                if(arr.find(make_pair(nx,ny))!=arr.end()){
                    tmp.push_back(nx);
                    tmp.push_back(ny);
                    break;
                }
            }
            if(tmp.size()>0){
                ans.push_back(tmp);
                tmp.clear();   
            }
        }
        return ans;
    }
};