#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // constructor
    Node(int val) {
        data = val;
        next = NULL;
    }
};   

bool cycleLinkedList(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {  
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;  // cycle detected
    }
    return false; // no cycle
}
