#include <bits/stdc++.h>
using namespace std;

/*
Finds GCD string using Euclidean Algorithm and pattern check.
If str1 + str2 != str2 + str1, no common divisor string exists.
Otherwise, GCD length = gcd(len1, len2) and substring is returned.

Time Complexity: O(n + m), Space Complexity: O(n + m)
*/

int gcd(int n1, int n2){
    int maximum = max(n1, n2);
    int minimum = min(n1, n2);

    while(minimum != 0){  //most imp logic
        int remainder = maximum % minimum;     
        maximum = minimum;
        minimum = remainder;        
    }
    return maximum;
}

string gcdOfStrings(string str1, string str2) {
    if(str1 + str2 != str2 + str1){
        return "";
    }

    int len = gcd(str1.length(), str2.length());
    return str1.substr(0, len);
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    cout << gcdOfStrings(str1, str2);

    return 0;
}



/*I wrote the entire code for gcd instead of using the function directly because i wasn't able to recall it that moment, so it might show beats 22.27% something like this but the code is exactly the same as others*/