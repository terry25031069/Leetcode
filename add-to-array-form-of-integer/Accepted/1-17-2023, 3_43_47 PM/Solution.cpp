// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        num[0] += k;
        for(int i = 0; i < num.size() - 1; i++){
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
        while(num.back() > 9){
            int tmp = num.back() / 10;
            *&(num.back()) %= 10;
            num.push_back(tmp);
        }
        reverse(num.begin(), num.end());
        return num;
    }
};