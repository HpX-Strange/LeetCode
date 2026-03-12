class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0]=1;

        int prefix_sum=0; 
        int count=0;

        for(int i=0; i<nums.size(); i++){
            prefix_sum+=nums[i];
            int remain= prefix_sum%k;

            if(remain<0){
                remain+=k;
            } 

            if(mpp.find(remain)!=mpp.end()){
                count+=mpp[remain];
                mpp[remain]++;
            }else{
                mpp[remain]=1;
            }
        }
        return count;
    }
};