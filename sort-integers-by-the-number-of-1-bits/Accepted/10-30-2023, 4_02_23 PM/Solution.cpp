// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
            bitset<16>na(a), nb(b);
            if(na.count() != nb.count()) return na.count() < nb.count();
            return a < b;
        });
        return arr;
    }
};