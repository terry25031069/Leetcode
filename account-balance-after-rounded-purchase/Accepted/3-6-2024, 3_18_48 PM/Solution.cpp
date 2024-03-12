// https://leetcode.com/problems/account-balance-after-rounded-purchase

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        return 100 - (purchaseAmount + 5) / 10 * 10; 
    }
};