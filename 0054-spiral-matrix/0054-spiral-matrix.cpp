class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> arr;
        
        
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0, right=n-1, top=0, bottom=m-1;

        while(left<=right&&top<=bottom) {
            for(int j=left;j<=right;++j) {
                arr.push_back(matrix[top][j]);
            }
            ++top;

            for(int i=top;i<=bottom;++i) {
                arr.push_back(matrix[i][right]);
            }
            --right;
            
            if(top<=bottom) {
                for (int j=right;j>=left;--j) {
                    arr.push_back(matrix[bottom][j]);
                }
                --bottom;
            }
            if(left<=right){
                for (int i=bottom; i>=top;--i) {
                    arr.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        

        
        return arr;
    }
};