class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> arr;
        int maxi=0;
        for(int i=0;i<candies.size();i++){
            if(maxi<candies[i]) maxi=candies[i];
        }
        for(int i=0;i<candies.size();i++){
            candies[i]+=extraCandies;
            if(maxi<=candies[i]) arr.push_back(true);
            else arr.push_back(false);
        }
        return arr;

    }
};