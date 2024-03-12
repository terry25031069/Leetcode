// https://leetcode.com/problems/check-if-the-sentence-is-pangram

class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char>yee;
        for(char i:sentence)yee.insert(i);
        if(yee.size()==26)return 1;
        return 0;
    }
};