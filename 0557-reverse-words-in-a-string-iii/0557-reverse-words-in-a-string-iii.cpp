class Solution {
public:
    string reverseWords(string s) {
        string str="";
        while(true){
            if(s.length()==0){
                str.erase(str.length()-1,1);
                break;
            }
            else{
                string tmp = s.substr(0, s.find(" "));
                for(int j=tmp.length()-1;j>=0;j--){
                    str+=tmp[j];
                }
                str+=" ";
                s.erase(0,tmp.length()+1);
                
            }
            
        }
        return str;
        
    }
};