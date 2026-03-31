#include <iostream>
#include <vector>
using namespace std;


class ListNode {
    public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 
    ListNode* mergeSort_LL(ListNode* list1 , ListNode* list2) {
        ListNode* temp = new ListNode(-1);
        ListNode* ans = temp;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 == nullptr) {
            temp->next = list2;
        } else {
            temp->next = list1;
        }

        return ans->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0) return nullptr;
        if (size == 1) return lists[0];

        ListNode* temp = mergeSort_LL(lists[0], lists[1]);
        ListNode* temp_ans = temp;

        for (int i = 2; i < size; i++) {
            temp_ans = mergeSort_LL(temp, lists[i]);
        }

        return temp_ans;
    }
};


ListNode* createList(const vector<int>& nums) {
    ListNode dummy;
    ListNode* tail = &dummy;

    for (int num : nums) {
        tail->next = new ListNode(num);
        tail = tail->next;
    }

    return dummy.next;
}


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Sample input: [[1,4,5],[1,3,4],[2,6]]
    vector<vector<int>> input = {{-8,-7,-7,-5,1,1,3,4},{-2}, {-10,-10,-7,0,1,3}, {2}};
    vector<ListNode*> lists;

    for (const auto& vec : input) {
        lists.push_back(createList(vec));
    }

    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    cout << "Merged List: ";
    printList(result);

    return 0;
}
