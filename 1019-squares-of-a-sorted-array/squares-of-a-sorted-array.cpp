class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        long long min=INT_MAX,min_ind=-1;
        for(int i=0;i<n;i++){
            if(abs(0-nums[i])<min){
                min=abs(0-nums[i]);
                min_ind=i;
            }
        }
        int low = min_ind,high=n;
        if(min_ind!=n-1){
            high=min_ind+1;
        }
        long long p,q;
        while(low>=0 and high<=n-1){
            p = nums[low]*nums[low],q=nums[high]*nums[high];
            if(p>q){
                ans.push_back(q);
                high++;
            }
            else{
                ans.push_back(p);
                low--;
            }
        }
        while(low>=0){
            p = nums[low]*nums[low];
            ans.push_back(p);
            low--;
        }
        while(high<=n-1){
            q=nums[high]*nums[high];
            ans.push_back(q);
            high++;
        }
        return ans;
    }
};