#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        q.push({sr, sc});
        int prev = image[sr][sc];
        image[sr][sc] = color;
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();     
            for (const auto& d : dir) {
                int xn = x + d[0], yn = y + d[1];
                if (xn >= 0 && xn < image.size() && yn >= 0 && yn < image[0].size() && image[xn][yn] == prev) {
                    image[xn][yn] = color;
                    q.push({xn, yn});
                }
            }
        }
        
        return image;
    }
};
