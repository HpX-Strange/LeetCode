class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<26> small=0, caps=0;
        for(char ch: word){
            if(ch>='a'){
                small[ch-'a']=1;
            }else{
                caps[ch-'A']=1;
            }
        }
        small= small&caps;
        return small.count();
    }
};