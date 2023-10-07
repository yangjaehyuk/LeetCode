const int MOD = 1000000007;

class Solution {
public:
    int path[100] = {0};
    int count = 0;
    int memo[51][101][101];

    int abc(int lev, int goal, int len, int arr[], int k, int maxVal, int searchCost) {
        if (lev == goal) {
            int search_cost = 0;
            int max_element = 0;

            for (int i = 0; i < lev; i++) {
                if (path[i] > max_element) {
                    max_element = path[i];
                    search_cost++;
                }
            }

            if (search_cost == k) {
                return 1;
            }
            return 0;
        }

        if (memo[lev][maxVal][searchCost] != -1) {
            return memo[lev][maxVal][searchCost];
        }

        int ways = 0;

        for (int i = 0; i < len; i++) {
            int newVal = arr[i];
            int newMaxVal = max(maxVal, newVal);
            int newSearchCost = (newVal > maxVal) ? searchCost : searchCost + 1;

            path[lev] = newVal;
            ways = (ways + abc(lev + 1, goal, len, arr, k, newMaxVal, newSearchCost)) % MOD;
        }
        memo[lev][maxVal][searchCost] = ways;
        return ways;
    }

    int numOfArrays(int n, int m, int k) {
        int arr[m];
        for (int i = 0; i < m; i++) {
            arr[i] = i + 1;
        }
        memset(memo, -1, sizeof(memo));
        int result = abc(0, n, m, arr, k, 0, 0);
        return result;
    }
};
