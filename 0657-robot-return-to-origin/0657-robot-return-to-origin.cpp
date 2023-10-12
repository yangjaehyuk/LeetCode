class Solution {
public:
    int upDown=0;
    int leftRight=0;
    bool judgeCircle(string moves) {
        for(int i=0;i<moves.length();i++){
            cout<<moves[i]<<endl;
            if(moves[i]=='U') upDown--;
            else if(moves[i]=='D') upDown++;
            else if(moves[i]=='L') leftRight--;
            else leftRight++;
        }
        if(upDown==0 && leftRight==0) return true;
        else return false;
    };
};