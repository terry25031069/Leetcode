// https://leetcode.com/problems/reshape-the-matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size() * mat[0].size() != r * c) return mat;
        vector<vector<int>> ans;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(ans.size() == 0 || ans.back().size() == c){
                    ans.push_back({});
                }
                vector<int> &last = *(ans.rbegin());
                last.push_back(mat[i][j]);
            }
        }
        return ans;
    }
};