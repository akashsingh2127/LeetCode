#include <bits/stdc++.h>
using namespace std;

/*
Rotates a singly linked list to the right by k places.
We first find the length, make the list circular,
then break it at the correct position to get new head.
Time Complexity: O(n), Space Complexity: O(1)
*/


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr) return head;

    // find length so that we can find the new tail and new head
    int n = 1;
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
        n++;
    }

    k = k % n;
    if (k == 0) return head;

    
    temp->next = head; //creating the cycle

    
    ListNode* newTail = head;
    for (int i = 0; i < n - k - 1; i++) {// find new tail (n-k-1)
        newTail = newTail->next;
    }

    
    ListNode* newHead = newTail->next;//we need to get the new head before we break the cycle

    
    newTail->next = nullptr;//breaking the cycle

    return newHead;
}


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}


int main() {
    int n, k;
    cin >> n >> k;

    // create linked list
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ListNode* newNode = new ListNode(x);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = rotateRight(head, k);

    printList(head);

    return 0;
}


/*The challenge i faced was related to the edge cases like when there r only two nodes and k=1 and as i was using while loop i wasn't able to able to break the cycle before in a few test cases......
so after that i used for loop and got the answer.*/