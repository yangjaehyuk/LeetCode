class Solution {
public:
    vector<char> stack;
    string removeStars(string s) {
        string ans;
        for(int i=0;i<s.length();i++){
            stack.push_back(s[i]);
            if(stack[stack.size()-1]=='*'){
                stack.pop_back();
                stack.pop_back();
            }
        }
        for(int i=0;i<stack.size();i++){
            ans+=stack[i];
        }
        return ans;
    
    };
};