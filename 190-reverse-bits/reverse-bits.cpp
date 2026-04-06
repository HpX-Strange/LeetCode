class Solution {
public:
    string to_binary(int n){
        string res="";
        for(int i=0; i<32; i++){
            res+=((n>>i) & 1) +'0';
        }
        return res; 
    }
    int to_int(string s){
        int num = 0;
    
        for (char c : s) {
            num = num * 2 + (c - '0');
        }
    
        return num;
    }
    int reverseBits(int n) {
        string s= to_binary(n);
        int ans= to_int(s);
        return ans;
    }
};