class Solution {
public:

    bool check(int num){
        bool flag= false;
        while(num>0){
            int digit= num%10;
            if(digit== 3 || digit== 4|| digit== 7)  return false;
            if(digit== 2 || digit==5 || digit==6|| digit==9)    flag=true;
            num= num/10;
        }
        return flag;
    }

    int rotatedDigits(int n) {
        int count=0;
        for(int i=1; i<=n; i++){
            if(check(i)){
                count++;
            }
        }
        return count;
    }
};