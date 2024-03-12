// https://leetcode.com/problems/apple-redistribution-into-boxes

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int k = accumulate(apple.begin(), apple.end(), 0);
        cout << k << endl;
        int ans = 0;
        while(ans < capacity.size()){
            k -= capacity[ans];
            if(k <= 0) break;
            ans++;
        }
        return min(int(capacity.size()), ans + 1);
    }
};