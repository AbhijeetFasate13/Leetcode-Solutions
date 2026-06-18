class Solution {
public:
    double angleClock(int hour, int minutes) {
        int totalMin = hour * 60 + minutes;
        double hAngle = totalMin * 0.5;
        double mAngle = totalMin * 6 % 360;
        double diff = abs(hAngle - mAngle);
        return min(diff, 360.0 - diff);
    }
};