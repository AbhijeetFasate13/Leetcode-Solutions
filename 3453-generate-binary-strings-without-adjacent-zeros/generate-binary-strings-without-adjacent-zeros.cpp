class Solution {
    string getBinaryString(int n, int sz) {
        string bin;
        while (n) {
            bin = (n & 1 ? "1" : "0") + bin;
            n >>= 1;
        }
        while (bin.size() < sz) {
            bin = "0" + bin;
        }
        return bin;
    }

public:
    vector<string> validStrings(int n) {
        if(n==1){
            return {"0","1"};
        }
        vector<string> result;
        for (int i = 1; i < (1 << n); i++) {
            bool check = true;
            for (int j = 0; j < n - 1; j++) {
                int prevBit = (i & (1 << j)) > 0;
                int currBit = (i & (1 << (j + 1))) > 0;
                if (!prevBit and !currBit) {
                    check = false;
                    break;
                }
            }
            if (check) {
                result.push_back(getBinaryString(i, n));
            }
        }
        return result;
    }
};
