// https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        s += 'c';
        vector<int> sub;
        char cur = '0';
        int cnt = 0;
        for(auto c: s){
            if(c != cur){
                sub.push_back(cnt);
                cnt = 1;
                cur = c;
            }else cnt++;
        }
        int ans = 0;
        for(int i: sub) cout << i << ' '; cout << endl;
        for(int i = 0; i < sub.size() - 1; i+=2){
            ans = max(ans, min(sub[i], sub[i + 1]));
        }
        return ans;
    }
};
