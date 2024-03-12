// https://leetcode.com/problems/bag-of-tokens

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1;
        int ma_score = 0, score = 0;
        while(i <= j){
            if(power >= tokens[i]) {
                power -= tokens[i];
                score++, ma_score = max(score, ma_score), i++;
            }else{
                power += tokens[j];
                score--; j--;
            }
            //cout << i << ' ' << j << ' ' << score << ' ' << power << endl;
        }
        return ma_score;
    }
};