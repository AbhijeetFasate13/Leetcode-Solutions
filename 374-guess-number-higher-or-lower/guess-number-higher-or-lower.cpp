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
        long long low = 0, high = n*1ll + 1;
        long long ans=0;
        while(high-low>=1){
            long long mid = low + (high-low)/2;
            if(guess(mid)==0){
                ans= mid;
                break;
            }
            else if(guess(mid)==1){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return ans;
    }
};