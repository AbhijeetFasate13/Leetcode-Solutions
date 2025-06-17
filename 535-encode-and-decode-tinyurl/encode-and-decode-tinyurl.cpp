class Solution {
    int counter = 1;
    unordered_map<string, int> urlToId;
    unordered_map<int, string> idToUrl;
    const string base62 =
        "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string toBase62(int n) {
        string code;
        while (n) {
            code = base62[n % 62] + code;
            n /= 62;
        }
        while (code.size() < 6) {
            code = "0" + code;
        }
        return code;
    }

    int toBase10(const string& code) {
        int id = 0;
        for (char c : code) {
            id = id * 62 + base62.find(c);
        }
        return id;
    }

public:
    string encode(string longUrl) {
        if (urlToId.count(longUrl)) {
            int id = urlToId[longUrl];
            return "https://leetcode.com/problems/" + toBase62(id);
        }
        urlToId[longUrl] = counter;
        idToUrl[counter] = longUrl;
        return "https://leetcode.com/problems/" + toBase62(counter++);
    }

    string decode(string shortUrl) {
        int idx = shortUrl.find_last_of('/');
        string code = shortUrl.substr(idx + 1);
        int id = toBase10(code);
        return idToUrl.count(id) ? idToUrl[id] : "";
    }
};
