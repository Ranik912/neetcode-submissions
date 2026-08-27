class Solution {
public:
    void merge(vector<int>& arr, int L, int M, int R) {
        // FIXED: Python slices converted to C++ vectors
        vector<int> left(arr.begin() + L, arr.begin() + M + 1);
        vector<int> right(arr.begin() + M + 1, arr.begin() + R + 1);

        int i = L;
        int j = 0;
        int k = 0;

        // Merge both sorted arrays
        while (j < left.size() && k < right.size()) {
            if (left[j] <= right[k]) {
                arr[i] = left[j];
                j++;
            }
            else {
                arr[i] = right[k];
                k++;
            }
            i++;
        }

        // Copy remaining elements from left
        while (j < left.size()) {
            arr[i] = left[j];
            j++;
            i++;
        }

        // Copy remaining elements from right
        while (k < right.size()) {
            arr[i] = right[k];
            k++;
            i++;
        }
    }

    void mergeSort(vector<int>& arr, int L, int R) {
        // Base case
        if (L >= R) return;  // FIXED: handles single element

        int M = L + (R - L) / 2;

        // Recursive calls
        mergeSort(arr, L, M);
        mergeSort(arr, M + 1, R);

        // Merge sorted halves
        merge(arr, L, M, R);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};