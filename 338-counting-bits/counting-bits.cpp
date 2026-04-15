class Solution {
public:
    int count_bit(int n){
        int count=0;
        while(n){
            count+= (n&1);
            n>>=1;
        }
        return count;
    }

    vector<int> countBits(int n) {
        // vector<int> ans;
        // for (int i=0; i<=n; i++){
        //     ans.push_back(count_bit(i));
        // }
        // return ans;
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i=1; i<=n; i++){
            ans[i]= ans[i>>1] + (i & 1);
        }
        return ans;
    }
};