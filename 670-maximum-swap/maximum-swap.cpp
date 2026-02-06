class Solution {
public:
    int maximumSwap(int num) {
        string number = to_string(num);
        string original = number;
        sort(number.rbegin(), number.rend());
        int n = number.size();
        for (int i = 0; i < n; i++) {
            if (number[i] == original[i])
                continue;
            int idx = i;
            for (int j = n - 1; j >= i; j--) {
                if (original[j] == number[i]) {
                    idx = j;
                    break;
                }
            }
            swap(original[i], original[idx]);
            break;
        }
        return stoi(original);
    }
};