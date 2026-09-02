class Solution {
private:
    unordered_map<int, string> memo;

    int highestSetBit(int value) const {
        return 31 - __builtin_clz(value);
    }

    string buildLargestString(int value) const {
        string result;

        while (value > 0) {
            int highestBit = highestSetBit(value);

            if (highestBit > 25) {
                int zCount = value >> 25;
                result.append(zCount, 'z');
                value -= zCount << 25;
                continue;
            }

            result += static_cast<char>('a' + highestBit);
            value -= 1 << highestBit;
        }

        return result;
    }

public:
    vector<string> largestString(const vector<int>& nums) {
        vector<string> result;
        result.reserve(nums.size());
        for (int value : nums) {
            auto [iterator, inserted] = memo.try_emplace(
                value,
                buildLargestString(value)
            );
            result.push_back(iterator->second);
        }
        return result;
    }
};
