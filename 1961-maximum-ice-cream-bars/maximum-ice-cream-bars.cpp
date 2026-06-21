class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans=0;
        for(int i=0; i<costs.size(); i++){
            if(coins==0){
                return ans;
            }
            if(coins < costs[i]){
                return ans;
            }
            coins-= costs[i];
            ans++;
        }
        return ans;
    }
};