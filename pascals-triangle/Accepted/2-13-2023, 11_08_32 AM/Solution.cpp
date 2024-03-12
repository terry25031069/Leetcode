// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<int> trans(vector<int> tmp){
        auto v = tmp;
        tmp.push_back(0); v.insert(v.begin(), 0);
        for(int i = 0; i < tmp.size(); i++){
            tmp[i] += v[i];
        }
        return tmp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<int> tmp{1};
        vector<vector<int>> ans{tmp};
        for(int i = 2; i <= numRows; i++){
            tmp = trans(tmp);
            ans.push_back(tmp);
        }
        return ans;
    }
};