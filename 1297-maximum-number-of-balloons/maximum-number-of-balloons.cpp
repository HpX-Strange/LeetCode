class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[5]= {0};
        for(char ch: text){
            if(ch=='b'){
                freq[0]+=1;
            }
            else if(ch=='a'){
                freq[1]+=1;
            }
            else if(ch=='l'){
                freq[2]+=1;
            }
            else if(ch=='o'){
                freq[3]+=1;
            }
            else if(ch=='n'){
                freq[4]+=1;
            }
        }
        return min({freq[0], freq[1], freq[2]>>1, freq[3]>>1, freq[4]});
    }
};