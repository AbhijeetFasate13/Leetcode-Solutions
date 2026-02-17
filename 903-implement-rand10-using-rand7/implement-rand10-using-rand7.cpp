// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int rand49 = 49;
        while (rand49 > 40) {
            rand49 = (rand7() - 1) * 7 + rand7();
        }
        return (rand49) % 10 + 1;
    }
};