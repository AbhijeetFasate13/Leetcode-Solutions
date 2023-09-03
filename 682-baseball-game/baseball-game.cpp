class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>check;
        int sum = 0, n = operations.size();
        int a,b;
        for(int i=0;i<n;i++){
            if(operations[i]=="+"){
                a=check.top();
                check.pop();
                b=check.top();
                check.push(a);
                check.push(a+b);
            }
            else if(operations[i]=="D"){
                check.push(2*check.top());
            }
            else if(operations[i]=="C"){
                check.pop();
            }
            else{
                check.push(stoi(operations[i]));
            }
        }
        while(!check.empty()){
            sum+=check.top();
            check.pop();
        }
        return sum;
    }
};