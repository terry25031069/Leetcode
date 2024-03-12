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
                for(int j = 0; j < prime.size() && prime[j] < nums[i]; j++){
                    if(nums[i] - prime[j] < nums[i-1]) nums[i] -= prime[j];
                }
                if(nums[i] <= 0 || nums[i] >= nums[i-1]) return false;
            }
        }
        //for(auto i: nums) cout << i << ' '; cout << endl;
        return true;
    }
};