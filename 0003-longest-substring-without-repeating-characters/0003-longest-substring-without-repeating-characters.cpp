class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int len=s.length();
        int maxi=0;
        unordered_set <char> str;
        while(i<len && j<len){
            if(str.find(s[j])==str.end()){
                str.insert(s[j]);
                j++;
                if(j-i>maxi) maxi=j-i;
            }
            else{
                str.erase(s[i]);
                i++;
            }
        }
        return maxi;
    }
};