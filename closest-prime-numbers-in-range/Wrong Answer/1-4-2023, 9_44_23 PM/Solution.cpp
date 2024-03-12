// https://leetcode.com/problems/closest-prime-numbers-in-range

class Solution {
public:
    bool checkPrime(int n){
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }

    int nextPrime(int n){
        n++;
        while(n){
            if(checkPrime(n)) return n;
            n++;
        }
        return -1;
    } 

    vector<int> closestPrimes(int left, int right) {
        vector<int>tmp;
        if(checkPrime(left)) tmp.push_back(left);
        int n = nextPrime(left);
        while(n <= right){
            tmp.push_back(n);
            n = nextPrime(n);
        }
        for(auto i: tmp) cout << i << ' '; cout << endl;
        if(tmp.size() < 2) return {-1, -1};
        int minimum = 1e9; vector<int> ans;
        for(int i = 1; i < tmp.size(); i++){
            if(tmp[i] - tmp[i - 1] < minimum) ans = {tmp[i - 1], tmp[i]}, minimum = tmp[i] - tmp[i-1];
        }
        return ans;
    }
};