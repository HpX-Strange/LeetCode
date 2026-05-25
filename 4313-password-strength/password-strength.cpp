class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> unique;
        for(char ch: password){
            unique.insert(ch);
        }
        int ans=0;
        for(char ch: unique){
            if(ch>='a' && ch<='z'){
                ans+=1;
            }
            else if(ch>='A' && ch<='Z'){
                ans+=2;
            }
            else if(ch>='0' && ch<='9'){
                ans+=3;
            }
            else if(ch=='!' || ch=='@' || ch=='#' || ch=='$'){
                ans+=5;
            }
        }
        return ans;
    }
};