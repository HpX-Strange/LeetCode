class Solution {
public:

    int query(int idx, int l, int r, int ql, int qr, vector<int>& seg){
        if(r<ql || qr<l){
            return 0;
        }
        if(ql<=l && r<=qr){
            return seg[idx];
        }
        int mid=l+ (r-l)/2;
        int left= query(2*idx+1, l, mid, ql, qr, seg);
        int right= query(2*idx+2, mid+1, r, ql, qr, seg);
        return max(left, right);
    }
    void update(int idx, int l, int r, int target, int nv, vector<int> &seg){
        if(l==r){
            seg[idx]=max(seg[idx], nv);
            return;
        }
        int mid= l+(r-l)/2;
        if(target<=mid){
            update(2*idx+1, l, mid, target, nv, seg);
        }
        else{
            update(2*idx+2, mid+1, r, target, nv, seg);
        }
        seg[idx]= max(seg[2*idx+1], seg[2*idx+2]);
    }

    int lengthOfLIS(vector<int>& nums, int k) {
        int maxVal= *max_element(nums.begin(), nums.end());
        vector<int> seg(4*(maxVal+1),0);

        int ans=0;
        for(int x: nums){
            int left = max(0, x-k);
            int right = x-1;

            int best = 0;

            if(left <= right)
                best = query(0,0,maxVal,left,right,seg);
            int curr = best + 1;

            update(0,0,maxVal,x,curr,seg);

            ans = max(ans,curr);
        }

        return ans;
        }
    
};