// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)) return 1;
        int low = 2, high = n, mid;
        while(low <= high){
            mid = (high - low) / 2 + low;
            bool result = isBadVersion(mid), prev = isBadVersion(mid - 1);
            if(!prev && result) return mid;
            if(result){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return mid;
    }
};