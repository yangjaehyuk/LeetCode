class Solution {
public:
    int boss[201];
    int find(int n){
        if(boss[n]==-1) return n;
        return boss[n]=find(boss[n]);
    }
    void setUnion(int t1, int t2){
        
        int a=find(t1);
        int b=find(t2);
        
        if(a==b) return;
        
        boss[b]=a;
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            boss[i]=-1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    setUnion(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(boss[i]==-1) cnt++;
        }
        return cnt;
    }
};