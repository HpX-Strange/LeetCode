class Solution {
public:
    bool hasAlternatingBits(int n) {
        string binary=" ";
        while(n>0){
            binary= char((n%2)+'0') + binary;
            n= n/2;
        }
        cout<<binary;
        for(int i=0; i<binary.length()-1; i++){
            if(binary[i]==binary[i+1]){
                return false;
            }
        }
        return true;
    }
};