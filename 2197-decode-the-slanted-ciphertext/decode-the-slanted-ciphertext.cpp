class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;
        string decipheredText;
        for (int c = 0; c < cols; c++) {
            int i = 0, j = c;
            while (i < rows && j < cols) {
                decipheredText.push_back(encodedText[i * cols + j]);
                i++;
                j++;
            }
        }

        while (!decipheredText.empty() && decipheredText.back() == ' ') {
            decipheredText.pop_back();
        }

        return decipheredText;
    }
};