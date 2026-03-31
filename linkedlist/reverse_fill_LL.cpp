#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    

    ListNode* reverseList(ListNode* head) {
        if(head != nullptr && head->next != nullptr ){
            return head;
        };
       ListNode* newHead = reverseList(head->next) ;
       head->next = front;
       front->next = head ;
       head->next = nullptr;

       
       return newHead;
       
    }

    // Function to print the linked list (for testing purposes)
    void printList(ListNode* head) {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* temp = head;
    for (int i = 1; i < values.size(); ++i) {
        temp->next = new ListNode(values[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    Solution sol;

    
    ListNode* head = createList({1, 2, 3, 4, 5});

    cout << "Original List: ";
    sol.printList(head);

   
    head = sol.reverseList(head);

    cout << "Reversed List: ";
    sol.printList(head);

    return 0;
}
