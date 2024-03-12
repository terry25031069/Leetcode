// https://leetcode.com/problems/k-items-with-the-maximum-sum

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k <= numOnes + numZeros) return numOnes;
        return numOnes - (k - numOnes - numZeros);
    }
};