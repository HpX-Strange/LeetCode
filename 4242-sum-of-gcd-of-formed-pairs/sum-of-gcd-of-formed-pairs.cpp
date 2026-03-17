class Solution {
public:
    int gcd(int a, int b){
        while(b!=0){
            int temp= b;
            b=a%b;
            a=temp;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n= nums.size();
        int mxi= INT_MIN;
        vector<int> temp(n);
        for(int i=0; i<n; i++){
            mxi= max(mxi,nums[i]);
            temp[i]= gcd(nums[i],mxi);
        }

        sort(temp.begin(), temp.end());
        int left= 0;
        int right= n-1;
        long long sum=0;
        while(left<right){
            sum+=gcd(temp[left],temp[right]);
            left++;
            right--;
        }
        return sum;
    }
};