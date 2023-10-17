class Solution {
public:
    vector<string> ans;
    char path[10];
    int visited[10];
    int cnt=0;
    void run(int lev, int level, string tiles, int len){
        
        if(lev==level){
            ans.push_back(path);
            return;
        }
        
        for(int i=0;i<len;i++){
            if(visited[i]==1) continue;
            path[lev]=tiles[i];
            visited[i]=1;
            run(lev+1, level, tiles, len);
            path[lev]=0;
            visited[i]=0;
        }
    }
    int numTilePossibilities(string tiles) {
        int len=tiles.length();
        for(int i=1;i<=len;i++){
            run(0, i, tiles, len);
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans.size();
    }
};