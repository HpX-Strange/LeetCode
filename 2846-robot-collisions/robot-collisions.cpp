class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n= positions.size();

        vector<tuple<int, int, char, int>> robots;
        //position, health, directions, index

        for(int i=0; i<n; i++){
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(robots.begin(), robots.end(), [](auto &a, auto &b){
            return get<0>(a) < get<0>(b);
        });
        stack<int> st;
        
        for(int i=0; i<n; i++){
            auto &[position, health, direction, index]= robots[i];
            if(direction=='R'){
                st.push(i);
            }
            else{
                while(!st.empty() && health>0){
                    auto &[posR, healthR, dirR, idxR] = robots[st.top()];
                    if(healthR<health){
                        st.pop();
                        health-=1;
                        healthR=0;
                    }
                    else if(healthR>health){
                        healthR-=1;
                        health=0;
                    }
                    else{
                        healthR=0;
                        health=0;
                        st.pop();
                    }
                }
            }
        }
        vector<pair<int,int>> survivors;
        for(auto &r: robots){
            auto &[pos, health, dir, idx]=r;
            if(health>0){
                survivors.push_back({idx, health});
            }
        }
        sort(survivors.begin(), survivors.end());
        vector<int> ans;
        for(auto& p: survivors){
            ans.push_back(p.second);
        }
        return ans;
    }
};