// https://leetcode.com/problems/flip-string-to-monotone-increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        if(!s.size()) return 0;
        int countFilp, countOne;
        countFilp = countOne = 0;
        for(char c: s){
            if(c == '0'){
                if(countOne == 0) continue;
                else countFilp++;
            }else{
                countOne++;
            }
            if(countFilp > countOne) countFilp = countOne;
        }
        return countFilp;
    }
};