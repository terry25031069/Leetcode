// https://leetcode.com/problems/determine-the-winner-of-a-bowling-game

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int ans, tot0, tot1, d;
        tot0 = tot1 = d = 0;
        for(auto i: player1){
            tot0 += i * (d ? 2: 1);
            if(d) d--;
            if(i == 10) d = 2;
        }
        d = 0;
        for(auto i: player2){
            tot1 += i * (d ? 2: 1);
            if(d) d--;
            if(i == 10) d = 2;
        }
        cout << tot0 << ' ' << tot1 << endl;
        return tot0 > tot1? 1: tot0 == tot1? 0: 2;
    }
};