class Solution {
public:
    bool isPalindrome(int x) {
        bool check=true;
        string str=to_string(x);
        int i=0;
        int j=str.length()-1;
        while(i<j){
            if(str[i]==str[j]){
                i++;
                j--;
            }
            else{
                check=false;
                break;
            }
        }
        return check;
    }
};