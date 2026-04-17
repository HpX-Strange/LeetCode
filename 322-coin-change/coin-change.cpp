class Solution {
public:
int n;
vector<vector<int>> t;
    int solve(int i, vector<int>& coins, int target){
        if(target==0)   return 0;
        if(i<0 || target<0) return 1e5;
        if(t[i][target]!=-1)   return t[i][target];
        int pick= 1+ solve(i, coins, target-coins[i]);
        int skip= solve(i-1, coins, target);

        return t[i][target]=min(pick, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        n= coins.size();
        t.assign(n, vector<int>(amount+1, -1));
        int ans= solve(n-1, coins, amount);
        if(ans==1e5){
            return -1;
        }
        return ans;
    }
};