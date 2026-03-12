class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0]=1;
        int prefix_sum=0;
        int count=0;

        for(int i=0; i<nums.size(); i++){
            prefix_sum+=nums[i];
            int k_removed= prefix_sum-k;
            count+=mpp[k_removed];
            mpp[prefix_sum]++;
        }
        return count;
    }
};