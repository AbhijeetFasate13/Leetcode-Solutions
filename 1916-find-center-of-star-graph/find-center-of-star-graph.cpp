class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = (int)edges.size();
        int maxi = -1;
        for(int i=0;i<n;i++){
            maxi = max({maxi,edges[i][0],edges[i][1]});
        }
        vector<int>hash(maxi+1);
        for(int i=0;i<n;i++){
            hash[edges[i][0]]++;
            hash[edges[i][1]]++;
        }
        int ans;
        for(int i=0;i<maxi+1;i++){
            // cout<<i<<" "<<hash[i]<<endl;
            if(hash[i]==maxi-1){
                ans = i;
                break;
            }
        }
        // cout<<maxi<<endl;
        return ans;
    }
};