class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<pair<int,int>> mpp;
        for(int i=0; i<arr.size(); i++){
            int x= __builtin_popcount(arr[i]);
            mpp.push_back({x, arr[i]});
        }
        sort(mpp.begin(), mpp.end());
        for(auto &it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};