#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    
    ListNode* mid_Linkedlist(ListNode* head) {
        ListNode* temp = head;
        ListNode* slow = temp;
        ListNode* fast = temp;
        ListNode* prev = nullptr;

        
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        
        if (prev != nullptr) {
            prev->next = nullptr;
        }

        return slow; 
    }

   
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }

        return prev;
        
    }

  
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        
        ListNode* mid = mid_Linkedlist(head);

        // Step 2: Reverse the second half of the list
        ListNode* secondHalf = reverseList(mid);

        // Step 3: Merge the two halves
        ListNode* firstHalf = head;
        while (secondHalf != nullptr) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            if (temp1 == nullptr) {
                break;
            }
            secondHalf->next = temp1;

            firstHalf = temp1;
            secondHalf = temp2;
        }
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

    // sol.reorderList(head);

    // cout << "Reordered List: ";
    // sol.printList(head);

    return 0;
}
