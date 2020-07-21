#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;

void traverseLinkedList(ListNode* node) {
    while (node != nullptr) {
        if (node->next == nullptr) {
            cout << node->val << endl;
        } else {
            cout << node->val <<",";
        }
        node = node->next;
    }
}

ListNode* createLinkedListR(vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }
    ListNode* head = nullptr;
    ListNode* r = nullptr;
    ListNode* p = nullptr;
    for (int val : arr) {
        if (head == nullptr) {
            head = new ListNode(val);
            r = head;
        } else {
            p = new ListNode();
            p->val = val;
            r->next = p;
            r = r->next;

        }
    }
    return head;
}

//141. ª∑–Œ¡¥±Ì
int main() {
    Solution solution;
    ListNode* head = nullptr;
    vector<int> arr = {-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,21,5 };
    head = createLinkedListR(arr);
    cout<<"has cycle: "<<solution.hasCycle(head);
    return 0;
}