// https://leetcode.com/problems/prime-subtraction-operation

class Solution {
public:
    vector<int> prime{2, 3};
    void build(){
        for(int i = 5; i < 1001; i++){
            int j;
            for(j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++){
                if(i % prime[j] == 0) break;
            }
            if(j >= prime.size() || prime[j] * prime[j] > i) prime.push_back(i);
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        if(nums.size() == 1) return true;
        build();
        reverse(nums.begin(), nums.end());
        int i;
        for(i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]) continue;
            else{
                int l = lower_bound(prime.begin(), prime.end(), nums[i] - nums[i-1] + 1) - prime.begin();
                if(l == prime.size()) return false;
                nums[i] -= prime[l];
                if(nums[i] <= 0) return false;
            }
        }
        for(auto i: nums) cout << i << ' '; cout << endl;
        return true;
    }
};