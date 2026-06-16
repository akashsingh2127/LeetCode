#include<bits/stdc++.h>
using namespace std;


    // We binary search the eating speed K between 1 and the largest pile.
    // For each speed, we calculate the total hours needed to finish all piles.
    // If the required hours are within h, we try a smaller speed.
    // Otherwise, we increase the speed to reduce the total hours.
    // The smallest valid speed found is the answer.

    // Time Complexity: O(n log M)
    // Space Complexity: O(1)
    // where n = number of piles, M = maximum pile size.

class Solution {
public:
    long long checker(vector<int>& piles, int h, int mid) {
        long long count = 0;
        for(int i = 0; i < piles.size(); i++) {

            if(piles[i] <= mid) {
                count++;
            }
            else {
                int temp = piles[i];
                count += ((temp + mid - 1) / mid);/*either u can use this formula for counting the number of hours or u can jjust seperate the cases*/
            }
        }
        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        //we will go from 1 to max val in the piles because the answer will in this range only .........

        int maxx = piles[0];
        int minn = 1;

        for(int i = 1; i < piles.size(); i++) {// for finding max
            if(piles[i] > maxx) {
                maxx = piles[i];
            }
        }
        int ans = maxx;// for the case where (h=piles.size())

        while(minn <= maxx) {
            int mid = minn + (maxx - minn) / 2;
            long long counter = checker(piles, h, mid);
            if(counter <= h) {
                ans = mid;//no need to use min() because if this cond is staisfied then automatically the next mid will be smaller than the current mid
                maxx = mid - 1;//to check in the left
            }
            else {//to check in the right
                minn = mid + 1;
            }
        }
        return ans;
    }
};

int main() {


    Solution s;

    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << "Minimum Eating Speed = "
         << s.minEatingSpeed(piles, h) << endl;
    return 0;
}


/*Intially, i was not using (long long) for the checker() and count because of which it wasn't able to take care the big values.......*/