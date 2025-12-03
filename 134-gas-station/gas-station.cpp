class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> extraGas(n);
        for (int i = 0; i < n; i++) {
            extraGas[i] = gas[i] - cost[i];
        }
        bool gasWillExhaustExactly = true;
        for (int start = 0; start < n; start++) {
            if (extraGas[start] > 0) {
                int trip = n;
                int j = start;
                int gasLeft = 0;
                bool tripWillComplete = true;
                while (trip--) {
                    gasLeft += extraGas[j];
                    if (gasLeft < 0) {
                        tripWillComplete = false;
                        break;
                    }
                    j = (j + 1) % n;
                }
                if (tripWillComplete) {
                    return start;
                }
            }
            if (extraGas[start] < 0) {
                gasWillExhaustExactly = false;
            }
        }
        return gasWillExhaustExactly ? 0 : -1;
    }
};