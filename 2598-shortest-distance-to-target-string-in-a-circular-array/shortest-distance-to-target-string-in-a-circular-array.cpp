class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if(words[startIndex]==target)return 0;
        int n = words.size();
        int left = (startIndex - 1 + n) % n;
        int moves = 1, minMoves = INT_MAX;
        while (left != startIndex) {
            if (words[left] == target) {
                minMoves = min(minMoves, moves);
                break;
            }
            left = (left - 1 + n) % n;
            moves++;
        }
        int right = (startIndex + 1) % n;
        moves = 1;
        while (right != startIndex) {
            if (words[right] == target) {
                minMoves = min(minMoves, moves);
                break;
            }
            right = (right + 1) % n;
            moves++;
        }
        return minMoves == INT_MAX ? -1 : minMoves;
    }
};