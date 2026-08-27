class Solution {
public:

    void merge(vector<int> &arr, int L, int MID, int R){
        vector<int> left(arr.begin() + L, arr.begin() + MID + 1);
        vector<int> right(arr.begin() + MID + 1, arr.begin() + R + 1);

        int i = L;
        int j = 0; 
        int k = 0;

        while(j < left.size() && k < right.size()){
            if(left[j] < right[k]){
                arr[i] = left[j];
                i++;
                j++;
            }
            else{
                arr[i] = right[k];
                i++;
                k++;
            }
        }

        while(j < left.size()){
            arr[i] = left[j];
            i++;
            j++;
        }

        while(k < right.size()){
            arr[i] = right[k];
            i++;
            k++;
        }
    }

    void mergeSort(vector<int> &arr, int l, int r){
        if(l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};