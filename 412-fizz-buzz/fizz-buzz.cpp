class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans(n);
        for(int j=0;j<n;j++){
            int i = j+1;
            if(i%3 == 0 and i%5 == 0){
                ans[j]="FizzBuzz";
            }
            else if(i%3==0){
                ans[j]="Fizz";
            }
            else if(i%5==0){
                ans[j]="Buzz";
            }
            else{
                ans[j]=to_string(i);
            }
        }
        return ans;
    }
};