#include <bits/stdc++.h>
using namespace std;

/*
Rotates an array to the right by k steps using reversal algorithm.
First reverse first (n-k) elements, then last k elements, then whole array.
This efficiently shifts elements without using extra space.
Time Complexity: O(n), Space Complexity: O(1)
*/

// helper function to reverse part of array
void reverse(vector<int>& nums,int start,int end){//simple logic for reversing the array
    while(start<=end){
        int temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;

    }
}
// the rotation is from the right side be careful of this point
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
        k=k%n;  //the user may enter rotate the array by 9 even it's size is 7 which actually means rotate it by 2
        int start=0;
        int breaker=n-k;
        int end=n-1;
        reverse(nums,start,breaker-1);
        reverse(nums,breaker,end);
        reverse(nums,start,end);
        
        
    }

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    rotate(nums, k);

    // print rotated array
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}



/*the challenge i faced was initially i was not handling this (k=k%n) case. and also i though we r rotating it fro the left side */