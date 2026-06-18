#include<bits/stdc++.h>
using namespace std;




    // We binary search the answer (number of days) between the minimum and maximum bloom day.
    // For a chosen day 'mid', we count how many bouquets can be formed using flowers bloomed by that day.
    // Consecutive flowers are required, so the count resets whenever an unbloomed flower is found.
    // If at least m bouquets can be formed, we try to find a smaller valid day.
    // Otherwise, we need more days, so we search on the right half.

    // Time Complexity: O(n log D)
    // Space Complexity: O(1)
    // where n = number of flowers and D = max bloom day.

class Solution {
public:

    int checker(vector<int>& bloomDay,int k, int mid) {

        int count = 0;
        int con = 0;

        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) {
                count++;
            }
            else {//if it is not adjacent flowers then break
                count = 0;
            }
            if(count == k) {//if one bouquet is ready then increment the con and reset the count to 0 
                count = 0;
                con++;
            }
        }

        return con;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int minn = bloomDay[0];
        int maxx = bloomDay[0];

        for(int i = 1; i < bloomDay.size(); i++) {

            if(minn > bloomDay[i]) {
                minn = bloomDay[i];
            }

            if(maxx < bloomDay[i]) {
                maxx = bloomDay[i];
            }
        }

        int ans = maxx;// this is for the case (m*k==n)
        int n = bloomDay.size();

        if((long long)m * k > n)//make sure u use (long long) data type
            return -1;

        int low = minn;
        int high = maxx;

        while(low <= high) {

            int mid = low + (high - low) / 2;
            int counter = checker(bloomDay,k, mid);

            if(counter >= m) {// we'll be checking with (m)  not with the (k)
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution s;

    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    cout << "Minimum Days = "
         << s.minDays(bloomDay, m, k) << endl;

    return 0;
}