class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        if (numBottles < numExchange)
            return numBottles;
        return numExchange +
               maxBottlesDrunk(numBottles - numExchange + 1, numExchange + 1);
    }
};