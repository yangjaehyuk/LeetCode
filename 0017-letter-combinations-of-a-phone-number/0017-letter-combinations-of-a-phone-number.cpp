class Solution {
public:
    vector<string> ans;
    char path[100];
    vector<string> container;
    void run(int lev, int level){
        
        if(lev==level){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<container[lev].size();i++){
            path[lev]=container[lev][i];
            run(lev+1,level);
            path[lev]=0;
        }
    }
    vector<string> letterCombinations(string digits) {
        int len=digits.length();
        if(len==0) return ans;
        for(int i=0;i<digits.length();i++){
            if(digits[i]=='2'){
                container.push_back("abc");
            }
            else if(digits[i]=='3'){
                container.push_back("def");
            }
            else if(digits[i]=='4'){
                container.push_back("ghi");
            }
            else if(digits[i]=='5'){
                container.push_back("jkl");
            }
            else if(digits[i]=='6'){
                container.push_back("mno");
            }
            else if(digits[i]=='7'){
                container.push_back("pqrs");
            }
            else if(digits[i]=='8'){
                container.push_back("tuv");
            }
            else if(digits[i]=='9'){
                container.push_back("wxyz");
            }
        }
        run(0,len);
        return ans;
    }
};