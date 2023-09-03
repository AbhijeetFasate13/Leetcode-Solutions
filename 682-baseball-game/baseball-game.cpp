class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>check;
        int sum = 0, n = operations.size();
        for(int i=0;i<n;i++){
            int flag=0;
            if(operations[i][0]=='-'){
                operations[i]=operations[i].substr(1);
                flag=1;
            }
            if(operations[i][0]>='0' and operations[i][0]<='9'){
                int k = stoi(operations[i]);
                if(flag){
                    k*=-1;
                }
                check.push(k);
                sum+=k;
            }
            else if(operations[i]=="+"){
                int temp = check.top();
                check.pop();
                int temp1 = check.top();
                check.push(temp);
                check.push(temp+temp1);
                sum+=temp+temp1;
            }
            else if(operations[i]=="C"){
                sum-=check.top();
                check.pop();
            }
            else{
                sum+=2*check.top();
                check.push(2*check.top());
            }
        }
        return sum;
    }
};