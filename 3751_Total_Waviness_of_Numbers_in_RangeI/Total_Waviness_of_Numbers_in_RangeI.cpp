#include <iostream>
using namespace std;

/*
Approach:
1. Iterate through every number in the given range.
2. Extract digits from right to left while maintaining a sliding window of three digits.
3. Check if the middle digit is either a local maximum or a local minimum.
4. Increment the waviness count whenever such a pattern is found.
5. Return the total waviness of all numbers in the range.
Time Complexity: O((num2 - num1 + 1) × D), where D is the maximum number of digits.
Space Complexity: O(1), as only three integer variables are used.
*/

class Solution {
public:
    int totalWaviness(int num1, int num2) {

        if(num2 < 100)  //according to the given problem
            return 0;

        int grand_total = 0;

        for(int i = num1; i <= num2; i++) {

            int temp = i;

            int d1 = temp % 10; //last digit
            temp /= 10;

            int d2 = temp % 10;//middle digit or second last digit
            temp /= 10;

            while(temp > 0) {//to seperate the digits and keep sliding the window left side

                int d3 = temp % 10; //first digit or third last digit

                if((d2 > d3 && d2 > d1) ||
                   (d2 < d3 && d2 < d1)){
                    grand_total++;}

                d1 = d2;
                d2 = d3;
                temp /= 10;
            }
        }

        return grand_total;
    }
};

int main() {

    Solution obj;

    int num1 = 100;
    int num2 = 120;

    cout << "Total Waviness = "
         << obj.totalWaviness(num1, num2);

    return 0;
}


/* Initially i was using a vector for storing the digits inside the vector and then performing the count operation but that was taking O(d) space*/