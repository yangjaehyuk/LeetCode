class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obstaclesSet;
        for(int i=0;i<obstacles.size();i++){
            obstaclesSet.insert(make_pair(obstacles[i][0],obstacles[i][1]));
        }
        int dy[4]={1,0,-1,0};
        int dx[4]={0,1,0,-1};
        // up right down left
        int x=0;
        int y=0;
        int dir=0;
        int nx=0;
        int ny=0;
        int ans=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                // turn right
                dir++;

                dir=dir%4;

            }
            else if(commands[i]==-2){
                // turn left
                if(dir>0) dir--;
                else{
                    dir--;
                    dir*=-1;
                    if(dir%4==1) dir=3;
                    else if(dir%4==3) dir=2;
                    else dir=dir%4;
                }
            }
            else{
                for(int j=0;j<commands[i];j++){
                    nx+=dx[dir];
                    ny+=dy[dir];
                    if(obstaclesSet.find(make_pair(nx, ny))!=obstaclesSet.end()){
                        if(dir==0){
                            ny-=1;
                            break;
                        }
                        else if(dir==1){
                            nx-=1;
                            break;
                        }
                        else if(dir==2){
                            ny+=1;
                            break;
                        }
                        else{
                            nx+=1;
                            break;
                        }
                    }
                }
            }
            
            x=nx;
            y=ny;
            if(ans<pow(x,2)+pow(y,2)){
                ans=pow(x,2)+pow(y,2);
            }
        }
        return ans;
    }
};