class Solution {
public:
int sz;
const int mod= 1e9+7;
int dp[101][101][101];
    int solve(int i, int n, int minProfit, vector<int>& group, vector<int>& profit){
        if(i>=sz){
            if(minProfit<=0){
                return 1;
            }
            return 0;
        }
        minProfit= max(0, minProfit);
        if(dp[i][n][minProfit]!=-1){
            return dp[i][n][minProfit];
        }
        int take=0;
        if(n>=group[i]){
            take= solve(i+1, n-group[i], minProfit-profit[i], group, profit);
        }
        int skip= solve(i+1, n, minProfit, group, profit);

        return dp[i][n][minProfit]= (take+skip)%mod;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        sz= group.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, minProfit, group, profit);
        
    }
};