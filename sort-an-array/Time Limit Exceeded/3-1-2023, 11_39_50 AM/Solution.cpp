// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    int partition(vector<int>& arr, int start, int end){
        int r = rand() % (end - start + 1);
        int pivot = arr[r + start], cnt = 0;
        for(int i = start; i <= end; i++) if(arr[i] <= pivot) cnt++;
        int pivotidx = start + cnt - 1;
        swap(arr[r + start], arr[pivotidx]);
        int i = start, j = end;
        while(i < pivotidx && pivotidx < j){
            while(arr[i] <= pivot) i++;
            while(arr[j] > pivot) j--;
            if(i < pivotidx && j > pivotidx) swap(arr[i++], arr[j--]);
        }
        return pivotidx;
    }

    void quickSort(vector<int>& arr, int start, int end){
        if(start >= end) return;
        int p = partition(arr, start, end);
        quickSort(arr, start, p-1);
        quickSort(arr, p+1, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};