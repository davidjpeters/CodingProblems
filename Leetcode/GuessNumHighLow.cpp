

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

    Solution(int pick) : _pick(pick) {}

    int guessNumber(int n) {

        int l = 1;
        int r = n;

        while (true) {
            int mid = l + (r - l) / 2;
            int g = guess(mid);
            if (g == 0)
                return mid;
            if (g == -1) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return -1;
    }

    int guess(int num) {
        if (num > _pick)
            return -1;
        if (num < _pick)
            return 1;
        return 0;
    }

    private:
        int _pick;
};