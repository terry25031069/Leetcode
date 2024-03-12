// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n, mid;
        while(low <= high){
            mid = (high - low) / 2 + low;
            bool result = isBadVersion(mid);
            cout << mid  << ' ' << result << endl;
            if(result){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
            if(!isBadVersion(mid)) return mid + 1;
            return mid;
        }
        return mid;
    }
};