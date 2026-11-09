class Solution {
    struct Job {
        long long at;
        int server;

        auto operator<=>(const Job&) const = default;
    };

    template <class T> using MinHeap = priority_queue<T, vector<T>, greater<>>;

public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> turns(k);
        iota(turns.begin(), turns.end(), 0);

        MinHeap<int> free(greater<>(), std::move(turns));
        MinHeap<Job> busy;

        vector<int> handled(k, 0);

        for (int i = 0; i < arrival.size(); i++) {
            while (!busy.empty() && busy.top().at <= arrival[i]) {
                int x = busy.top().server;
                busy.pop();

                free.push(i + (x - i % k + k) % k);
            }

            if (free.empty())
                continue;

            int x = free.top() % k;
            free.pop();

            busy.push({(long long)arrival[i] + load[i], x});

            ++handled[x];
        }

        int most = *max_element(handled.begin(), handled.end());

        vector<int> ans;

        for (int x = 0; x < k; x++) {
            if (handled[x] == most)
                ans.push_back(x);
        }

        return ans;
    }
};