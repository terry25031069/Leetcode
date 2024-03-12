// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(auto it : grid){
            int i = 0, j = it.size()-1;
            if(it[0]<0) ans += j+1;
            else if(it[j] > 0) ans += 0;
            else {
                while(i<=j){
                    int mid =(i+j)/2;
                    if(it[mid] < 0 && it[mid - 1] >= 0){
                        ans += it.size() - mid;
                        cout<<mid<<endl;
                        break;
                    }
                    else if(it[mid] < 0) j = mid-1;
                    else i = mid+1;
                }
            }
        }
        return ans;
    }
};