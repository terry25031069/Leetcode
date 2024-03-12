// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit

class Solution {
public:
    int chg(string s, int f, int t){
        for(auto &c: s){
            if(c == f + '0') c = '0' + t;
        }
        return stoi(s);
    }
    int minMaxDifference(int num) {
        string s = to_string(num);
        int ma = -1, mi = 1e9;
        for(int i = 0; i < 9; i++){
            ma = max(ma, chg(s, i, 9));
        }
        for(int i = 1; i < 10; i++){
            mi = min(mi, chg(s, i, 0));
        }
        //cout << ma << ' ' << mi << endl;
        return ma - mi;
    }
};