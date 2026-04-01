#include<bits/stdc++.h>
using namespace std;

/*
Counts common factors of two numbers by checking all values from 1 to min(a,b).
If a number divides both a and b, it is counted.
Time Complexity: O(min(a,b)) due to single loop.
Space Complexity: O(1) as no extra space is used.
*/

int commonFactors(int a, int b) {
    int count = 0;
    for(int i = 1; i <= min(a, b); i++){
        if(a % i == 0 && b % i == 0){
            count++;
        }
    }
    return count;     
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << commonFactors(a, b);

    return 0;
}