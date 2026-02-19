class Solution {
public:
int n;
vector<vector<int>> directions ={{-1,0}, {0,-1}, {1,0}, {0,1}};

    bool solve(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visited, int mid){
        if(i<0 || i>=n || j<0 || j>=n || visited[i][j] || grid[i][j]>mid){
            return false;
        }
        visited[i][j]=true;
        if(i==n-1 && j==n-1)    return true;
        for(auto &it: directions){
            int i_= i+it[0];
            int j_= j+ it[1];

            if(solve(grid, i_, j_, visited, mid))   return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n= grid.size();
        

        int l= grid[0][0];
        int r= n*n-1;
        int result=0;
        while(l<=r){
            int mid= l+ (r-l)/2;
            vector<vector<bool>> visited(n, vector<bool> (n, false));
            if(solve(grid, 0, 0, visited, mid)){
                result= mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};