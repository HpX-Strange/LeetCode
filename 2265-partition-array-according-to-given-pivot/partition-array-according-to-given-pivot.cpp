class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n= nums.size();
        vector<int> ans(n);
        int i=0;
        int j=n-1;

        int l=0;
        int r=n-1;

        while(i<n && j>=0){
            if(nums[i]<pivot){
                ans[l]=nums[i];
                l++;
            }
            if(nums[j]>pivot){
                ans[r]=nums[j];
                r--;
            }
            i++;
            j--;
        }
        for(int k=l; k<=r; k++){
            ans[k]=pivot;
        }
        return ans;
    }
};