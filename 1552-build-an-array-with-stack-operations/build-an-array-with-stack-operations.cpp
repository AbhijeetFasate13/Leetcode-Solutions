class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> stackOps;
        const string push = "Push";
        const string pop = "Pop";
        int sum = 0, stream = 1;
        for (int i = 0; i < target.size(); i++) {
            while (stream < target[i]) {
                stackOps.push_back(push);
                stackOps.push_back(pop);
                stream++;
            }
            stackOps.push_back(push);
            stream++;
        }
        return stackOps;
    }
};