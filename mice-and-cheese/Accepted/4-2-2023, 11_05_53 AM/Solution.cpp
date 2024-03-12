// https://leetcode.com/problems/mice-and-cheese

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n = reward1.size();
        int curk = 0, ans = 0;
        vector<int> tmp0, tmp1;
        for(int i = 0; i < n; i++){
            if(reward1[i] >= reward2[i]){
                curk++, ans += reward1[i];
                tmp0.push_back(reward1[i] - reward2[i]);
            }
            else{
                ans += reward2[i];
                tmp1.push_back(reward2[i] - reward1[i]);
            }
        }
        sort(tmp0.begin(), tmp0.end());
        sort(tmp1.begin(), tmp1.end());
        cout << curk << endl;
        for(auto i: tmp0) cout << i << ' '; cout << endl;
        for(auto i: tmp1) cout << i << ' '; cout << endl;
        for(int i = 0; i < tmp0.size() && i < curk - k; i++) ans -= tmp0[i], cout << ans << endl;
        for(int i = 0; i < tmp1.size() && i < k - curk; i++) ans -= tmp1[i], cout <<  ' ' << ans << endl;
        return ans;
    }
};