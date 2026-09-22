class Solution {
    struct Info {
        array<int, 5> ways{};
        int whole = 1;
    };

    int k;

    Info combine(const Info& left, const Info& right) {
        Info res;

        for (int r = 0; r < k; r++) {
            res.ways[r] = left.ways[r];
        }

        for (int r = 0; r < k; r++) {
            if (right.ways[r]) {
                int nr = (left.whole * r) % k;
                res.ways[nr] += right.ways[r];
            }
        }

        res.whole = (left.whole * right.whole) % k;

        return res;
    }

    struct SegmentTree {
        int size;
        int k;
        vector<Info> tree;

        SegmentTree(vector<int>& nums, int k) : k(k) {
            size = 1;

            while (size < (int)nums.size())
                size <<= 1;

            tree.resize(2 * size);

            for (int i = 0; i < (int)nums.size(); i++) {
                int rem = nums[i] % k;

                tree[size + i].ways[rem] = 1;
                tree[size + i].whole = rem;
            }

            for (int i = size - 1; i > 0; i--) {
                tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
            }
        }

        Info combine(const Info& left, const Info& right) {
            Info res;

            for (int r = 0; r < k; r++) {
                res.ways[r] = left.ways[r];
            }

            for (int r = 0; r < k; r++) {
                if (right.ways[r]) {
                    int nr = (left.whole * r) % k;
                    res.ways[nr] += right.ways[r];
                }
            }

            res.whole = (left.whole * right.whole) % k;

            return res;
        }

        void update(int index, int value) {
            int pos = size + index;
            int rem = value % k;

            tree[pos].ways.fill(0);
            tree[pos].ways[rem] = 1;
            tree[pos].whole = rem;

            pos >>= 1;

            while (pos) {
                tree[pos] = combine(tree[pos << 1], tree[pos << 1 | 1]);

                pos >>= 1;
            }
        }

        Info query(int left, int right) {
            Info leftPart;
            Info rightPart;

            left += size;
            right += size;

            while (left < right) {

                if (left & 1) {
                    leftPart = combine(leftPart, tree[left]);
                    left++;
                }

                if (right & 1) {
                    --right;
                    rightPart = combine(tree[right], rightPart);
                }

                left >>= 1;
                right >>= 1;
            }

            return combine(leftPart, rightPart);
        }
    };

public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        SegmentTree tree(nums, k);

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            tree.update(q[0], q[1]);

            Info result = tree.query(q[2], nums.size());

            answer.push_back(result.ways[q[3]]);
        }

        return answer;
    }
};