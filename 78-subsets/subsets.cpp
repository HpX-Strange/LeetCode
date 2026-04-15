class Solution {
public:

    void solve(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int> temp){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        solve(i+1, nums, ans, temp);

        int element= nums[i];
        temp.push_back(element);
        solve(i+1, nums, ans, temp);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums,ans, temp);
        return ans;
    }
};