class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n= nums.size();
        int sum= accumulate(nums.begin(), nums.end(), 0);
        int first=0;
        for(int i=0; i<n; i++){
            first+=i*nums[i];
        }

        int ans= first;
        for(int i=1; i<n; i++){
            first= first+sum- n*nums[n-i];
            ans= max(ans, first);
        }
        return ans;
    }
};