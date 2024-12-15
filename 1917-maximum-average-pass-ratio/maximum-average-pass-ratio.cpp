class Solution {
public:
    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            double r1 = (double)(a[0] + 1) / (a[1] + 1) - (double)a[0] / a[1];
            double r2 = (double)(b[0] + 1) / (b[1] + 1) - (double)b[0] / b[1];
            return r1 < r2;
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

        for (const vector<int>& c : classes) {
            pq.push(c);
        }

        while (extraStudents--) {
            vector<int> top = pq.top();
            pq.pop();
            top[0]++;
            top[1]++;
            pq.push(top);
        }
        double ans = 0.0;
        int n = (int)classes.size();
        while (!pq.empty()) {
            ans += (double)pq.top()[0] / pq.top()[1];
            pq.pop();
        }
        return ans / n;
    }
};
