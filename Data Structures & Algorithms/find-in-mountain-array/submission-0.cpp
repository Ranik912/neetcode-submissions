class Solution {
public:
    int binarySearch(int l, int r, MountainArray& m, int target){
        int idx = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(m.get(mid) == target){
                idx = mid;
                break;
            }
            else if(m.get(mid) > target) r = mid - 1;
            else l = mid + 1;
        }
        return idx;
    }
    int binarySearchRev(int l, int r, MountainArray& m, int target){
        int idx = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(m.get(mid) == target){
                idx = mid;
                break;
            }
            else if(m.get(mid) > target) l = mid + 1;
            else r = mid - 1;
        }
        return idx;
    }
    int mountainPeak(MountainArray& m){
        int n = m.length();
        int l = 0;
        int r = n - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(m.get(mid) < m.get(mid + 1)) l = mid + 1;
            else r = mid;
        }
        return r;
    }
    int findInMountainArray(int target, MountainArray &m) {
        int n = m.length();
        int peak = mountainPeak(m);
        int ans = binarySearch(0, peak, m, target);
        if(ans != -1) return ans;
        int ans_ = binarySearchRev(peak + 1, n - 1, m, target);
        return ans_;
    }
};