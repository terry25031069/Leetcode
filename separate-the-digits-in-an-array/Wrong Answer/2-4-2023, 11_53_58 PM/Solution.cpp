// https://leetcode.com/problems/separate-the-digits-in-an-array

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto i: nums){
            if(i < 10) ans.push_back(i);
            else{
                while(i > 0){
                    auto tmp = to_string(i);
                    reverse(tmp.begin(), tmp.end());
                    i = stoi(tmp);
                    ans.push_back(i % 10);
                    i /= 10;
                }
            }
        }
        return ans;
    }
};