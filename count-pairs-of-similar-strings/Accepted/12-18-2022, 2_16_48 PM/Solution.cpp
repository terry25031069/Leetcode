// https://leetcode.com/problems/count-pairs-of-similar-strings

class Solution {
public:
    int hash(string s){
        int ans = 0;
        for(auto i: s){
            ans |= 1 << (i -'a');
        }
        return ans;
    }
    int similarPairs(vector<string>& words) {
        map<int, int>m; m.clear();
        for(auto i: words){
            m[hash(i)]++;
        }
        int ans = 0;
        for(auto i: m){
            cout << i.first << ' ' << i.second << endl;
            ans += i.second * (i.second - 1) / 2;
        }
        return ans;
    }
};