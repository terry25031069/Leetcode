// https://leetcode.com/problems/sum-of-number-and-its-reverse

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i < num; i++){
            string re = to_string(i);
            reverse(re.begin(), re.end());
            int rev = stoi(re);
            if(rev + i == num) return true;
        }
        return false;
    }
};