#include <bits/stdc++.h>
using namespace std;

/*
Sorts a linked list using Merge Sort.
Splits list using slow-fast pointers, then merges sorted halves.
Efficient for linked lists as it avoids random access.
Time Complexity: O(n log n), Space Complexity: O(log n)
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};


ListNode* findMid(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;  //imp part don't relate it with cycle detection concept

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;    // this is the mid node
}


ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);  //this is just to connnect the rest of the sorted list with itself and while returning we won't return it 
    ListNode* temp = &dummy;

    while (l1 && l2) { // simple logic as merge sort
        if (l1->val < l2->val) { 
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    if (l1) temp->next = l1;  // if any nodes in l1 is left then just add it as it is in the end.
    if (l2) temp->next = l2;  // if any nodes in l2 is left then just add it as it is in the end.

    return dummy.next; // seee here we r not returning the dummy node
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;  ///base case

    ListNode* mid = findMid(head); //helps to find the mid as done in basic merge sort
    ListNode* right = mid->next;  //it's something like mid+1 in merge sort
    mid->next = NULL;    // to break the list u need this

    ListNode* left = sortList(head);    //breaking for the left part
    right = sortList(right);     // breaking for the right part

    return merge(left, right);     //now merging part will be done
}

int main() {
    
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    head = sortList(head);

    ListNode* temp = head;
    //to print the sorted list
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}

/*the challenge i faced was that i was using fast=head as i was thinking it would be the same as for cycle detection.

i was unnecessarily trying to put mid node in merge functiona like we do in basic merge sort like :- merge(arr,low,mid,high)...  so keep this in ur mind while solving it. */