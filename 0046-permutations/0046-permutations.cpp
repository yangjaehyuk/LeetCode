class Solution {
public:
    vector<int> arr;
    vector<vector<int>> ans;
    int container[10];
    int path[10];
    int visited[10];
    void dfs(int lev, int level){
        if(lev==level){
            for(int i=0;i<level;i++){
                arr.push_back(path[i]);
            }
            ans.push_back(arr);
            arr.clear();
            return;
        }
        for(int i=0;i<level;i++){
            if(visited[i]==1) continue;
            path[lev]=container[i];
            visited[i]=1;
            dfs(lev+1, level);
            visited[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            container[i]=nums[i];
        }
        dfs(0,nums.size());
        return ans;
    }
};