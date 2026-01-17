class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = 0, emptyBottles = 0;
        while (numBottles + emptyBottles / numExchange != 0) {
            numBottles += emptyBottles / numExchange;
            emptyBottles %= numExchange;
            count += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;
        }
        count += numBottles + emptyBottles / numExchange;
        return count;
    }
};