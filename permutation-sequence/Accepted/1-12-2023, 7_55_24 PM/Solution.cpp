// https://leetcode.com/problems/permutation-sequence

class Solution {
public:
    int n;
    vector<bool>used;
    int nextLocation(int n){
        n++;
        while(used[n]) n++;
        return n;
    }
    string getPermutation(int n, int k) {
        string tmp = "", ans = "";
        vector<int>time = {1};
        used.resize(n + 1, 0);
        for(int i = 1; i <= n; i++){
            tmp += ('0' + i);
            if(i < n) time.push_back(time.back() * i);
        }
        reverse(time.begin(), time.end());
        for(int i = 0; i < n - 1; i++){
            int j = nextLocation(0);
            //cout << ' ' << j << endl;
            while(k > time[i]) k -= time[i], j = nextLocation(j);
            ans += j + '0', used[j] = 1;
        }
        for(int i = 1; i <= n; i++){
            if(!used[i]){
                ans += i + '0';
            }
        }
        return ans;
    }
};