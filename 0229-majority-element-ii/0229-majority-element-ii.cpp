class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int enough = nums.size()/3;
        int cnt=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                cnt++;
                if(cnt>enough){
                    ans.push_back(nums[i]);
                
                }
            }
            
            else{
                cnt=1;
                if(cnt>enough){
                    ans.push_back(nums[i]);
                    ans.push_back(nums[i+1]);
                }
            }
        }
        
        if(nums.size()==1) return nums;
        else{
            ans.erase(unique(ans.begin(),ans.end()),ans.end());
            return ans;
        }
    }
};