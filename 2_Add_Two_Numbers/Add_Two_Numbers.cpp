#include <bits/stdc++.h>
using namespace std;

/*
Adds two numbers represented as linked lists digit by digit.
Traverses both lists while maintaining carry for sums ≥ 10.
Creates a new result list using a dummy node.
Time Complexity: O(max(n, m)), Space Complexity: O(max(n, m))
*/


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* dummy = new ListNode(0);   //to keep the track of the head( for the new list)
    ListNode* n = dummy;                 

    int carry = 0; // if the sum is >= 10

    while (l1 || l2 || carry) {   //this condition helps us to remove the additional cases where the left out list is added to the new list 

        int sum = carry;

        if (l1) {
            sum += l1->val;// it's for carry+l1->val
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;// and this includes l2 tooo.. i.e.carry+l1->val+l2->val
            l2 = l2->next;
        }

        n->next = new ListNode(sum % 10); // new node is cretaed

        carry = sum / 10; // this is not remainder it's division 
        n = n->next;   
    }

    return dummy->next; 
}

int main() {
    

    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = addTwoNumbers(l1, l2);

    // Print result
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}



/*The challenge i faced was i was using carry=sum%10 which was creating problem when sum=10. */