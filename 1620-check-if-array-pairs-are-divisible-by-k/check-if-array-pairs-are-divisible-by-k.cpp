class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        for(int i=0; i<arr.size(); i++){
            int num= (arr[i]%k+k)%k;
            mpp[num]++;
        }

        for(auto& it: mpp){
            int r= it.first;

            if(r==0){
                if(mpp[r]%2!=0) return false;
            }
            else if(2*r==k){
                if(mpp[r]%2!=0) return false;
            }
            else{
                if(mpp[r]!=mpp[k-r])    return false;
            }
        }
        return true;
    }
};