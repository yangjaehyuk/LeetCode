class Solution {
public:
    priority_queue<int> q;
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        
        for(int i=1;i<k;i++) q.pop();
        return q.top();
    }
};