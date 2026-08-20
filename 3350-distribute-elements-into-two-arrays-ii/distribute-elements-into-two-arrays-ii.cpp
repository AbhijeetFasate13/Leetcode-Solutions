#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Define the ordered_multiset macro/typedef using a unique pair
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;

class Solution {
    int greaterCount(int a, ordered_multiset& oms) {
        return oms.size() - oms.order_of_key({a, INT_MAX});
    }

public:
    vector<int> resultArray(vector<int>& nums) {
        ordered_multiset omsA, omsB;
        vector<int> a = {nums[0]}, b = {nums[1]};
        omsA.insert({nums[0], 0});
        omsB.insert({nums[1], 1});
        int n = nums.size();
        for (int i = 2; i < n; i++) {
            int c1 = greaterCount(nums[i], omsA);
            int c2 = greaterCount(nums[i], omsB);
            if (c1 > c2) {
                a.push_back(nums[i]);
                omsA.insert({nums[i], i});
            } else if (c1 < c2) {
                b.push_back(nums[i]);
                omsB.insert({nums[i], i});
            } else {
                if (a.size() <= b.size()) {
                    a.push_back(nums[i]);
                    omsA.insert({nums[i], i});
                } else {
                    b.push_back(nums[i]);
                    omsB.insert({nums[i], i});
                }
            }
        }
        vector<int> result(n);
        int aSize = a.size();
        for (int i = 0; i < n; i++) {
            if (i < aSize) {
                result[i] = a[i];
            } else {
                result[i] = b[i - aSize];
            }
        }
        return result;
    }
};