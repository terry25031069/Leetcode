// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        m--, n--, m += n;
        if(n > m / 2) n = m - n;
        vector<long long> ans = {1};
        for(int i = 1; i <= m; i++){
            ans.push_back(1);
            for(int j = i - 1; j > 0; j--){
                ans[j] += ans[j-1];
            }
            //for(int j = 0; j < ans.size(); j++) cout << ans[j] << ' '; cout << endl;
        }
        return ans[n];
    }
};