// https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three

class Solution {
public:
    int averageValue(vector<int>& num) {
        int tot, n; 
        tot = n = 0;
        for(auto i: num) tot += i * (i % 6 == 0), n += (i % 6 == 0);
        if(!n) return 0;
        return tot / n;
    }
}; 