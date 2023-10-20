class Solution {
public:
    string reverseVowels(string s) {
        // e e o e
        // e o e e
        vector<char> container;
        vector<int> idx;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]== 'E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                container.push_back(s[i]);
                idx.push_back(i);
            }
        }
        
        reverse(container.begin(), container.end());
        
        // for(int i=0;i<idx.size();i++){
        //     cout<<idx[i]<<" "<<container[i]<<endl;
        // }
        for(int i=0;i<idx.size();i++){
            s[idx[i]]=container[i];
        }
        return s;
        
    }
};