class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            stack<int> st;
            // if(nums[i]==0)  ans.push_back(0);
            while(nums[i]!=0){
                int digit= nums[i]%10;
                st.push(digit);
                nums[i]= nums[i]/10;
            }
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};