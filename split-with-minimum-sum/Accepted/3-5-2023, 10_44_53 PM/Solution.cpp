// https://leetcode.com/problems/split-with-minimum-sum

class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end(), greater<char>());
        string s1 = "", s2 = "";
        int flag = 0;
        for(auto c: s){
            if(flag) s1 = c + s1;
            else s2 = c + s2;
            flag = !flag;
        }
        return stoi(s1) + stoi(s2);
    }
};