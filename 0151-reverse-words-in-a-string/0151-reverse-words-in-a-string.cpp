class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int leftidx=0;
        int rightidx=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                leftidx=i;
                break;
            }
        }
        s.erase(0,leftidx);
        
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                rightidx=i;
                break;
            }
        }
        for(int i=0;i<s.length()-rightidx;i++){
            s.erase(rightidx+1,1);
        }
        
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==' ' && s[i+1]==' '){
                s.erase(s.begin()+i);
                i--;
            }
        }
        
        reverse(s.begin(), s.end());
        
        string tmp; 
        
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                tmp+=s[i];
            }
            else{
                reverse(tmp.begin(), tmp.end());
                ans+=tmp+" ";
                tmp="";
            }
        }
        
        reverse(tmp.begin(), tmp.end());
        ans+=tmp;
        
        for(int i=0;i<ans.length();i++){
            if(s[i]!=' '){
                leftidx=i;
                break;
            }
        }
        ans.erase(0,leftidx);
        
//         for(int i=ans.length()-1;i>=0;i--){
//             if(s[i]!=' '){
//                 rightidx=i;
//                 break;
//             }
//         }
//         for(int i=0;i<ans.length()-rightidx;i++){
//             ans.erase(rightidx+1,1);
//         }
        
        
        return ans;
    }
};