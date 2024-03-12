// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--){
            if(i == digits.size() - 1)digits[i]++;
            if(digits[i] > 9 && i > 0) digits[i] -= 10, digits[i - 1]++;
        }
        if(digits[0] > 9) digits[0] -= 10, digits.insert(digits.begin(), 1);
        return digits;
    }
};