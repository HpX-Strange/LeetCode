class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> plant;
        for(int i=0; i<plantTime.size(); i++){
            plant.push_back({growTime[i], plantTime[i]});
        }
        sort(plant.rbegin(), plant.rend());
        int curr=0;
        int ans=0;

        for(auto& p: plant){
            int grow= p.first;
            int plant= p.second;

            curr+=plant;
            ans= max(ans, curr+grow);
        }
        return ans;
    }
};