class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        queue<int> q(arr.begin(), arr.end());
        int maxEl = *max_element(arr.begin(), arr.end());
        int current = q.front();
        q.pop();
        int winCount = 0;

        while (winCount < k) {
            if (current == maxEl)
                break;
            int opponent = q.front();
            q.pop();

            if (current > opponent) {
                winCount++;
                q.push(opponent);
            } else {
                q.push(current);
                current = opponent;
                winCount = 1;
            }
        }

        return current;
    }
};