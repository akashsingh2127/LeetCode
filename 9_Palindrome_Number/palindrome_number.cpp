#include <bits/stdc++.h>
using namespace std;

/*
Checks whether a number is a palindrome by reversing it.
Digits are extracted using modulus (%) and rebuilt in reverse.
If reversed number equals original, it is a palindrome.

Time Complexity: O(log n), Space Complexity: O(1)
*/

bool isPalindrome(long long x) {
    if (x < 0) return false;

    long long newnum = 0;
    long long temp = x;

    while (temp > 0) {
        int remainder = temp % 10;
        newnum = (newnum * 10) + remainder;
        temp = temp / 10;
    }

    return newnum == x;
}

int main() {
    long long x;
    cin >> x;

    if (isPalindrome(x))
        cout << "true";
    else
        cout << "false";

    return 0;
}