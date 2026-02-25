class AuctionSystem {
    unordered_map<int, unordered_map<int, int>> allBids;
    unordered_map<int, set<pair<int, int>>> highestBids;

public:
    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        if (allBids[itemId].count(userId)) {
            removeBid(userId, itemId);
        }

        allBids[itemId][userId] = bidAmount;
        highestBids[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        removeBid(userId, itemId);
        addBid(userId, itemId, newAmount);
    }

    void removeBid(int userId, int itemId) {
        if (!allBids[itemId].count(userId))
            return;
        int oldAmount = allBids[itemId][userId];
        highestBids[itemId].erase({oldAmount, userId});
        allBids[itemId].erase(userId);
    }

    int getHighestBidder(int itemId) {
        if (highestBids[itemId].empty())
            return -1;
        return highestBids[itemId].rbegin()->second;
    }
};