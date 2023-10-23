class Solution {
public:
    int visited[21];
    vector<vector<int>> ans;
    vector<int> tmp;
    int path[21];
    void dfs(int level,int lev,int num,int end){
        if(lev==level){
            for(int i=0;i<lev;i++){
                tmp.push_back(path[i]);
            }
            ans.push_back(tmp);
            tmp.clear();
            return;
        }
        
        for(int i=num;i<=end;i++){
            if(visited[i]==1) continue;
            path[lev]=i;
            visited[i]=1;
            dfs(level,lev+1,i+1,end);
            visited[i]=0;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        dfs(k,0,1,n);
        return ans;
    }
};