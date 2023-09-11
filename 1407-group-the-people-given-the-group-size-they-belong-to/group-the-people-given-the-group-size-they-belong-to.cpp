class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>>ans(501);
        priority_queue<pair<int,int>>grouping;
        for(int i=0;i<n;i++){
            grouping.push({groupSizes[i],i});
        }
        int ptr=0;
        while(!grouping.empty()){
            int batchSize = grouping.top().first;
            while(batchSize--){
                ans[ptr].push_back(grouping.top().second);
                grouping.pop();
            }
            ptr++;
        }
        ans.resize(ptr);
        return ans;
        
    }
};