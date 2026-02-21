class Solution {
    void add(string& ans, string curr, int mult) {
        while (mult--) {
            curr.push_back('0');
        }
        int i = ans.size() - 1, j = curr.size() - 1;
        int sum = 0, carry = 0;
        while (i >= 0 && j >= 0) {
            sum = (ans[i] - '0') + (curr[j] - '0') + carry;
            ans[i] = (sum % 10) + '0';
            carry = sum / 10;
            i--;
            j--;
        }
        while (i >= 0) {
            sum = (ans[i] - '0') + carry;
            ans[i] = (sum % 10) + '0';
            carry = sum / 10;
            i--;
        }
        while (j >= 0) {
            sum = (curr[j] - '0') + carry;
            ans = (char)((sum % 10) + '0') + ans;
            carry = sum / 10;
            j--;
        }

        if (carry)
            ans = (char)(carry + '0') + ans;
    }

public:
    string multiply(string nums1, string nums2) {
        if (nums1 == "0" || nums2 == "0")
            return "0";
        int n = nums1.size(), m = nums2.size();
        int mult = 0;
        string result = "0";
        for (int i = n - 1; i >= 0; i--) {
            int carry = 0;
            string curr;
            for (int j = m - 1; j >= 0; j--) {
                int prod = (nums1[i] - '0') * (nums2[j] - '0') + carry;
                curr = (char)((prod % 10) + '0') + curr;
                carry = prod / 10;
            }
            if (carry)
                curr = (char)(carry + '0') + curr;

            add(result, curr, mult);
            mult++;
        }

        return result;
    }
};