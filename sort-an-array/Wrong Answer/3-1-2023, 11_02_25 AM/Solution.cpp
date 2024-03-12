// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    int choosePivot(vector<int>& arr, int start, int end){
        int mid = (start + end) / 2;
        if (arr[start] > arr[end]) swap(arr[start], arr[end]);
        if (arr[mid] < arr[start]) swap(arr[mid], arr[start]);
        if (arr[end] < arr[mid]) swap(arr[end], arr[mid]);
        return mid;
    }

    int partition(vector<int>& arr, int start, int end){
        int r = choosePivot(arr, start, end);
        int pivot = arr[r], cnt = 0;
        for(int i = start; i < r; i++) {
            if(arr[i] <= pivot) cnt++;
        }
        int pivotidx = start + cnt;
        swap(arr[r], arr[pivotidx]);
        int i = start, j = end;
        while(i < pivotidx && pivotidx < j){
            while(arr[i] < pivot) i++;
            while(arr[j] >= pivot) j--;
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