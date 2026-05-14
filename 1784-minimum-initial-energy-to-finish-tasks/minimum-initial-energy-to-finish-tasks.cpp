class Solution {
public:
bool solve(vector<vector<int>>& tasks, int mid){
    for(int i = 0; i < tasks.size(); i++) {

            
            if(mid < tasks[i][1]) {
                return false;
            }

        
            mid -= tasks[i][0];
        }

        return true;
}
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1]-a[0]>b[1]-b[0];
        });
        int high=0;
        for(int i=0; i<tasks.size(); i++){
            high+=tasks[i][1];
        }
        int low=0;
        int ans=0;
        while(low<=high){
            int mid= low + (high - low)/2;
            if(solve(tasks, mid)){
                ans=mid;
                high= mid-1; 
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};