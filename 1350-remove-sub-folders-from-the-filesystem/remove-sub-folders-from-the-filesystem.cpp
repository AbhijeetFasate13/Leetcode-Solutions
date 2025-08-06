class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>ans;
        for(auto &i:folder){
            if(ans.empty() or i.find(ans.back()+"/")!=0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};