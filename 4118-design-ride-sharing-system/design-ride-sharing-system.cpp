class RideSharingSystem {
    queue<int> riders, drivers;
    map<int, int> request;

public:
    RideSharingSystem() {}

    void addRider(int riderId) { riders.push(riderId); }

    void addDriver(int driverId) { drivers.push(driverId); }

    vector<int> matchDriverWithRider() {
        if (!riders.empty() and !drivers.empty()) {
            int riderId = riders.front();
            riders.pop();
            int driverId = drivers.front();
            drivers.pop();
            request[riderId] = driverId;
            return {driverId, riderId};
        }
        return {-1, -1};
    }

    void cancelRider(int riderId) {
        // already matched
        if (request.find(riderId) != request.end()) {
            return;
        }
        int size = riders.size();
        for (int i = 0; i < size; i++) {
            if (riders.front() != riderId)
                riders.push(riders.front());
            riders.pop();
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */