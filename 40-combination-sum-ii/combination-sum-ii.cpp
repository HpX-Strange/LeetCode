class Solution {
public:

    void solve(int i, vector<int>& candidates, int target, vector<int> &curr, vector<vector<int>>& result){
        if(target<0)    return;
        if(target==0){
            result.push_back(curr);
            return;
        }
        for(int idx= i; idx<candidates.size(); idx++){
            if(idx> i && candidates[idx]==candidates[idx-1]){
                continue;
            }
            curr.push_back(candidates[idx]); //do
            solve(idx+1, candidates, target-candidates[idx], curr, result); //explore
            curr.pop_back(); //undo
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, curr, result);
        return result;
    }
};