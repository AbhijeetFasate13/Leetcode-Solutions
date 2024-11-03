class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = -1, r = (int)arr.size();
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] - mid-1 < k) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout<<l<<endl;
        return l+k+1;
    }
};