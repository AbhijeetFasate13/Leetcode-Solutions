class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;

        for (auto &seat : reservedSeats)
            mp[seat[0]].push_back(seat[1]);
        
        //if a row is not at all booked
        int ans = 2 * (n - mp.size());
        
        for (auto &[row, seats] : mp) {
            bool left = true; 
            bool middle = true;
            bool right = true;

            for (int x : seats) {
                if (x >= 2 && x <= 5) left = false;
                if (x >= 4 && x <= 7) middle = false;
                if (x >= 6 && x <= 9) right = false;
            }
            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};