class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n= nums.size();
        int count=1;
        for(int j=0; j<n; j++){
            int maxi=1;
            for(int i=j+1; i<n; i++){
                if(nums[i-1]<nums[i]){
                    maxi++;
                }else{
                    break;
                }
            }
            count= max(count,maxi);
        }
        return count;
    }
};