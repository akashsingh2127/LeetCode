#include <bits/stdc++.h>
using namespace std;

/*
Checks if parentheses are valid using stack.
Push opening brackets, and match with closing brackets.
If mismatch or stack not empty at end → invalid.
Time Complexity: O(n), Space Complexity: O(n)
*/

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        
        if (c == '(' || c == '{' || c == '[') {// Push opening brackets
            st.push(c);
        }
        else {
            
            if (st.empty()) return false;// If stack empty → invalid

            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string s;
    cin >> s;

    if (isValid(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}