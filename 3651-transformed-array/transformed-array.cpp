class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();

        vector<int> result(n);

        for(int i=0; i<n; i++){
            if(nums[i]>0){
                int index=(i+ nums[i])%n;
                result[i]= nums[index];
            }
            else if(nums[i]<0){
                int index = abs(nums[i]) % n;
                if(i - index >= 0){
                    result[i] = nums[i - index];
                }
                else{
                    result[i] = nums[n - (index - i)];
                }
            }
            else{
                result[i]=nums[i];
            }
        }
        return result;
    }
};