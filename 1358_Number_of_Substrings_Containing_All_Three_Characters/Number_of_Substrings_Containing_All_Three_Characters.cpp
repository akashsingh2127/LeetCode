#include <iostream>
#include <string>
using namespace std;

/*
Approach:
1. Use a sliding window with two pointers (first and second).
2. Expand the window by moving the second pointer and count the occurrences of 'a', 'b', and 'c'.
3. Once the window contains all three characters, every substring ending at or after 'second' is valid.
4. Add (n - second) to the answer, then shrink the window from the left to find more valid substrings.
5. Repeat until the right pointer reaches the end of the string.
Time Complexity: O(n), as each pointer traverses the string at most once.
Space Complexity: O(1), as only a fixed number of variables are used.
*/

class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();
        int count = 0;
        int a = 0, b = 0, c = 0;
        int first = 0, second = 0;

        while(second < n) {
            //seperately all the element counts will be calculated
            if(s[second] == 'a')
                a++;
            else if(s[second] == 'b')
                b++;
            else
                c++;

            while(a > 0 && b > 0 && c > 0) { //to slide the first 
                count += (n - second);//to compute all the possible only the sufix total has to be added
                //while moving the first we also need to remove the last previous first element from the substring and so with the element count
                if(s[first] == 'a')
                    a--;
                else if(s[first] == 'b')
                    b--;
                else
                    c--;
                first++;
            }
            second++;
        }

        return count;
    }
};

int main() {

    Solution obj;

    string s = "abcabc";

    cout << "Number of valid substrings = "
         << obj.numberOfSubstrings(s) << endl;

    return 0;
}

/* The challenge i faced was with the Outer whie condition. I kept it as (first<=n-3) in the beginning and coded accordingly but that went wrong so it has to be changed to (second<n)
and second point to remember u don't have to include the prefix count in the total because while checking the prefix will be automatically computed*/