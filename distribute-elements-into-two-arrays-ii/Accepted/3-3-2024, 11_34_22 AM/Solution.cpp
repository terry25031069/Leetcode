// https://leetcode.com/problems/distribute-elements-into-two-arrays-ii

#define pb(x) emplace_back(x)

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2, ans1, ans2;
        for(int i = 0; i < n; i++){
            if(i == 0) arr1.pb(nums[i]), ans1.pb(nums[i]);
            else if(i == 1) arr2.pb(nums[i]), ans2.pb(nums[i]);
            else{
                auto it1 = upper_bound(arr1.begin(), arr1.end(), nums[i]);
                auto it2 = upper_bound(arr2.begin(), arr2.end(), nums[i]);
                int c1 = distance(arr1.begin(), it1);
                int c2 = distance(arr2.begin(), it2);
                //cout << nums[i] << ' ' << c1 << ' ' << c2 << endl;
                if(arr1.size() - c1 > arr2.size() - c2 || 
                    arr1.size() - c1 == arr2.size() - c2 && arr1.size() <= arr2.size()) 
                    arr1.insert(it1, nums[i]), ans1.pb(nums[i]);
                else arr2.insert(it2, nums[i]), ans2.pb(nums[i]);
            }
        }
        ans1.reserve(ans1.size() + ans2.size());
        ans1.insert(ans1.end(), ans2.begin(), ans2.end());
        return ans1;
    }
};