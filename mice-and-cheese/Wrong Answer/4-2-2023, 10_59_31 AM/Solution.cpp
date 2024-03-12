// https://leetcode.com/problems/mice-and-cheese

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int curk = 0, ans = 0;
        vector<int> tmp;
        for(int i = 0; i < n; i++){
            if(reward1[i] >= reward2[i]) curk++, ans += reward1[i];
            else{
                ans += reward2[i];
                tmp.push_back(reward2[i] - reward1[i]);
            }
        }
        sort(tmp.begin(), tmp.end());
        for(int i = 0; i < tmp.size() && k - curk - i - 1 > 0; i++) ans -= tmp[i];
        return ans;
    }
};