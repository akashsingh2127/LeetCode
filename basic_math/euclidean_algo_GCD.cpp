#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2;
    cin>>n1>>n2;
    int maximum=max(n1,n2);
    int minimum=min(n1,n2);
    int remainder=maximum%minimum;
    while(minimum!=0){  
        remainder=maximum % minimum;     
        maximum = minimum;
        minimum=remainder;        
    }
    cout<<maximum;

    return 0;
}
/*
Euclidean Algorithm finds GCD using: GCD(a, b) = GCD(b, a % b).
We repeatedly replace (maximum, minimum) with (minimum, maximum % minimum).
The loop continues until minimum becomes 0.
The final value of maximum is the GCD.

Time Complexity:
O(log(min(a, b))) 

Space Complexity: 
O(1)

*/