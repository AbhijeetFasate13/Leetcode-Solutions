class Solution {
    int calcDist(vector<int>&x,vector<int>&y){
        return (x[0]-y[0])*(x[0]-y[0])+(x[1]-y[1])*(x[1]-y[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int>sides;
        sides.push_back(calcDist(p1,p2));
        sides.push_back(calcDist(p1,p3));
        sides.push_back(calcDist(p1,p4));
        sides.push_back(calcDist(p2,p3));
        sides.push_back(calcDist(p2,p4));
        sides.push_back(calcDist(p3,p4));
        sort(begin(sides),end(sides));
        if(sides[0]==0)return false;
        if(sides[0]!=sides[1])return false;
        if(sides[1]!=sides[2])return false;
        if(sides[2]!=sides[3])return false;
        return sides[4]==sides[5];
    }   
};