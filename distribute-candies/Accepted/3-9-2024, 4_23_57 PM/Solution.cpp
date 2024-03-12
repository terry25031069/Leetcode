// https://leetcode.com/problems/distribute-candies

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int, int> m;
        for(int i: candyType) m[i]++;
        return min(m.size(), candyType.size()/2);
    }
};