class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());
        int i= nums.size()-1;
        long long ans=0;

        while(k--){
            if(mul>0){
                ans+= 1LL* nums[i]*mul;
            }
            else{
                ans+=nums[i];
            }
            i--;
            mul--;
        }
        return ans;
    }
};