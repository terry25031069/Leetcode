// https://leetcode.com/problems/unique-binary-search-trees

class Solution {
public:
    int numTrees(int n) {
        vector<int> ans = {0, 1, 2, 5};
        for(int i = 4; i <= 19; i++){
            int tmp = ans[i-1];
            //cout << ans[i - 1] << endl;
            for(int j = 1; j <= i - 1 - j; j++){
                tmp += ans[i - j - 1] * ans[j];
            }
            tmp *= 2;
            if((i - 1) % 2 == 0) tmp -= ans[(i-1)/2] * ans[(i-1)/2];
            ans.push_back(tmp);
        }
        return ans[n];
    }
};