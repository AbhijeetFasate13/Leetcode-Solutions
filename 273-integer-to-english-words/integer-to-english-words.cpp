class Solution {
    const vector<string> threeDigitInterval = {"", "Thousand", "Million",
                                               "Billion"};
    const vector<string> unitDigit = {"One", "Two",   "Three", "Four", "Five",
                                      "Six", "Seven", "Eight", "Nine"};
    const vector<string> tensDigit = {"Ten",     "Twenty", "Thirty",
                                      "Forty",   "Fifty",  "Sixty",
                                      "Seventy", "Eighty", "Ninety"};
    const vector<string> specialCase = {"Eleven",    "Twelve",   "Thirteen",
                                        "Fourteen",  "Fifteen",  "Sixteen",
                                        "Seventeen", "Eighteen", "Nineteen"};
    unordered_map<int, string> represent;

    void fillSpellingMap() {
        for (int i = 1; i < 10; i++) {
            represent[i] = unitDigit[i - 1];
        }
        for (int i = 10; i < 100; i += 10) {
            represent[i] = tensDigit[i / 10 - 1];
        }
        for (int i = 11; i < 20; i++) {
            represent[i] = specialCase[i - 11];
        }
    }
    string spellThreeDigits(int n) {
        if (!n)
            return "";
        string spelling;
        string numString = to_string(n);
        while (numString.size() < 3) {
            numString = "0" + numString;
        }
        for (int i = 0; i < 3; i++) {
            if (numString[i] == '0')
                continue;
            if (i == 1 and numString[i] == '1') {
                spelling += represent[stoi(numString.substr(1))] + " ";
                break;
            }
            if (i == 0) {
                spelling += represent[numString[i] - '0'] + " " + "Hundred ";
            } else if (i == 1) {
                spelling += represent[(numString[i] - '0') * 10] + " ";
            } else {
                spelling += represent[numString[i] - '0'] + " ";
            }
        }
        spelling.pop_back();
        return spelling;
    }

public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        fillSpellingMap();
        stack<int> threeDigits;
        while (num) {
            threeDigits.push(num % 1000);
            num /= 1000;
        }
        string word, adder;
        while (!threeDigits.empty()) {
            adder = spellThreeDigits(threeDigits.top());
            word += adder;
            if (threeDigits.size() > 1 and adder != "")
                word += " " + threeDigitInterval[threeDigits.size() - 1] + " ";
            threeDigits.pop();
        }
        while (word.back() == ' ') {
            word.pop_back();
        }
        return word;
    }
};