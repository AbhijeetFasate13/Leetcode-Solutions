class SegmentTreeNode {
public:
    int minimumValue;
    int maximumValue;
    int lazyValue;

    SegmentTreeNode() {
        minimumValue = INT_MAX;
        maximumValue = INT_MIN;
        lazyValue = 0;
    }
};

class SegmentTree {
public:
    vector<SegmentTreeNode> treeNodes;
    int itemCount;

    SegmentTree(vector<int>& initialValues) {
        itemCount = initialValues.size();
        treeNodes.resize(4 * itemCount);
        buildTree(0, 0, itemCount - 1, initialValues);
    }

    void buildTree(int nodeIndex, int rangeStart, int rangeEnd,
                   vector<int>& initialValues) {
        if (rangeStart == rangeEnd) {
            treeNodes[nodeIndex].minimumValue =
                treeNodes[nodeIndex].maximumValue = initialValues[rangeStart];
            return;
        }

        int middleIndex = (rangeStart + rangeEnd) / 2;

        buildTree(2 * nodeIndex + 1, rangeStart, middleIndex, initialValues);
        buildTree(2 * nodeIndex + 2, middleIndex + 1, rangeEnd, initialValues);

        treeNodes[nodeIndex].minimumValue =
            min(treeNodes[2 * nodeIndex + 1].minimumValue,
                treeNodes[2 * nodeIndex + 2].minimumValue);

        treeNodes[nodeIndex].maximumValue =
            max(treeNodes[2 * nodeIndex + 1].maximumValue,
                treeNodes[2 * nodeIndex + 2].maximumValue);
    }

    void pushDown(int nodeIndex, int rangeStart, int rangeEnd) {
        if (treeNodes[nodeIndex].lazyValue == 0)
            return;

        int lazy = treeNodes[nodeIndex].lazyValue;

        treeNodes[nodeIndex].minimumValue += lazy;
        treeNodes[nodeIndex].maximumValue += lazy;

        if (rangeStart != rangeEnd) {
            treeNodes[2 * nodeIndex + 1].lazyValue += lazy;
            treeNodes[2 * nodeIndex + 2].lazyValue += lazy;
        }

        treeNodes[nodeIndex].lazyValue = 0;
    }

    void updateRange(int updateStart, int updateEnd, int nodeIndex,
                     int rangeStart, int rangeEnd, int adjustmentValue) {
        pushDown(nodeIndex, rangeStart, rangeEnd);

        if (rangeStart > updateEnd || rangeEnd < updateStart ||
            rangeStart > rangeEnd)
            return;

        if (rangeStart >= updateStart && rangeEnd <= updateEnd) {
            treeNodes[nodeIndex].lazyValue += adjustmentValue;
            pushDown(nodeIndex, rangeStart, rangeEnd);
            return;
        }

        int middleIndex = (rangeStart + rangeEnd) / 2;

        updateRange(updateStart, updateEnd, 2 * nodeIndex + 1, rangeStart,
                    middleIndex, adjustmentValue);

        updateRange(updateStart, updateEnd, 2 * nodeIndex + 2, middleIndex + 1,
                    rangeEnd, adjustmentValue);

        treeNodes[nodeIndex].minimumValue =
            min(treeNodes[2 * nodeIndex + 1].minimumValue,
                treeNodes[2 * nodeIndex + 2].minimumValue);

        treeNodes[nodeIndex].maximumValue =
            max(treeNodes[2 * nodeIndex + 1].maximumValue,
                treeNodes[2 * nodeIndex + 2].maximumValue);
    }

    int findRightMostZero(int nodeIndex, int rangeStart, int rangeEnd) {
        pushDown(nodeIndex, rangeStart, rangeEnd);

        int currentMinimum = treeNodes[nodeIndex].minimumValue;
        int currentMaximum = treeNodes[nodeIndex].maximumValue;

        if (currentMinimum > 0 || currentMaximum < 0)
            return -1;

        if (rangeStart == rangeEnd)
            return rangeStart;

        int middleIndex = (rangeStart + rangeEnd) / 2;

        int rightResult =
            findRightMostZero(2 * nodeIndex + 2, middleIndex + 1, rangeEnd);

        if (rightResult != -1)
            return rightResult;

        return findRightMostZero(2 * nodeIndex + 1, rangeStart, middleIndex);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> valueToIndexMap;
        vector<int> nextOccurrenceIndices(n, n);

        for (int i = n - 1; i >= 0; i--) {
            if (valueToIndexMap.count(nums[i]))
                nextOccurrenceIndices[i] = valueToIndexMap[nums[i]];

            valueToIndexMap[nums[i]] = i;
        }

        vector<int> balancePrefixSums(n, 0);
        unordered_set<int> encounteredValues;

        for (int i = 0; i < n; i++) {
            if (i > 0)
                balancePrefixSums[i] = balancePrefixSums[i - 1];

            if (encounteredValues.count(nums[i]))
                continue;

            if (nums[i] % 2 == 0)
                balancePrefixSums[i]--;
            else
                balancePrefixSums[i]++;

            encounteredValues.insert(nums[i]);
        }

        SegmentTree balanceTree(balancePrefixSums);

        int maxBalancedLength = balanceTree.findRightMostZero(0, 0, n - 1) + 1;

        for (int i = 1; i < n; i++) {
            int updateEndRange = nextOccurrenceIndices[i - 1] - 1;
            int adjustmentValue = (nums[i - 1] % 2 == 0 ? 1 : -1);

            balanceTree.updateRange(i, updateEndRange, 0, 0, n - 1,
                                    adjustmentValue);

            int rightMostZeroIndex = balanceTree.findRightMostZero(0, 0, n - 1);

            if (rightMostZeroIndex != -1) {
                maxBalancedLength =
                    max(maxBalancedLength, rightMostZeroIndex - i + 1);
            }
        }

        return maxBalancedLength;
    }
};
