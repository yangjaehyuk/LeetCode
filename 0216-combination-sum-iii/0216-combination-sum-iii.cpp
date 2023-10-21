class Solution {
public:
    vector<int> container;
    vector<int> tmp;
    vector<vector<int>> ans;

    void run(int lev,int level,int target,int num) {
        if (lev==level) {
            int sum=accumulate(tmp.begin(), tmp.end(), 0);
            if (sum==target) {
                ans.push_back(tmp);
            }
            return;
        }

        for (int i=num; i<container.size();i++) {
            tmp.push_back(container[i]);
            run(lev+1,level,target,i+1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        for (int i=1;i<=9;i++) {
            container.push_back(i);
        }
        run(0,k,n,0);
        return ans;
    }
};
