class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int l = 0, r = (int)arr.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] == target) {
                return true;
            }
            if(arr[l]==arr[mid] and arr[mid]==arr[r]){
                l++;
                r--;
                continue;
            }
            if (arr[l] <= arr[mid]) {
                if (arr[l] <= target and target <= arr[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (arr[mid] <= target and target <= arr[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};