#include <bits/stdc++.h>
using namespace std;

// Sliding window using hashmap to store last index of characters.
// If duplicate found, move start to max(current start, last_index + 1).
// Update max length using current window size (i - start + 1).
// Time Complexity: O(n), Space Complexity: O(min(n, charset)).

class Solution {
public:


/* this is more optimized than my concept . even though the tc is the same still it uses fixed array so it's better*/
int lengthOfLongestByarray(string s){//will use a kinda two pointer approach
    int freq[256] = {0};  //all characters value assigned to 0
        int l = 0, max_len = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r]]++;//the freq will increase by 1

            while (freq[s[r]] > 1) {//the moment a freq goes more that 1... max freq can go till 2
                freq[s[l]]--; //it will make the freq back to 1
                l++;// and the left pointer will start pointing to next character
            }
            max_len = max(max_len, r - l + 1);//to calculate the max length
        }
        return max_len;
    }



    //using unordered_map
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int maxx = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            //same concept but i have used hashing
            if (m.find(s[i]) != m.end()) {
                start = max(start, m[s[i]] + 1);
            }
            m[s[i]] = i;
            maxx = max(maxx, i - start + 1);
        }

        return maxx;
    }
};

int main() {
    Solution obj;
    string s;
    cin >> s;
    cout << obj.lengthOfLongestSubstring(s) << endl;
    return 0;
}


/*
The challenge i was facing was like instead of moving the start pointer ahead i was deleting all the keys from unordered_map untill i get thisthe duplicate pointer then the next pointer used to be my start but there it was messing up.............. so i had to take a start pointer tooooo*/