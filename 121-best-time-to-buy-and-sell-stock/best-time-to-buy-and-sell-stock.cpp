class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> large(prices.size());
        int largest= INT_MIN;
        int ans= INT_MIN;
        for(int i=prices.size()-1; i>=0; i--){
            largest= max(largest, prices[i]);
            large[i]=largest;
        }
        for(int i=0; i<large.size(); i++){
            ans= max(ans, large[i]-prices[i]);
        }
        return ans;
    }
};