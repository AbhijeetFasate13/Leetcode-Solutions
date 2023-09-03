/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long low = 0, high = n;
        long long ans=0;
        while(high-low>=0){
            long long mid = low + (high-low)/2;
            if(guess(mid)==0){
                ans= mid;
                break;
            }
            else if(guess(mid)==1){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};