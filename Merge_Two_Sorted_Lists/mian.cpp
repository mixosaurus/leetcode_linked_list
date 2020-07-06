#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;

void traverseLinkedList(ListNode* node) {
    if (node == nullptr) {
        cout << "Á´±íÎª¿Õ" << endl;
    }
    while (node != nullptr) {
        if (node->next == nullptr) {
            cout << node->val ;
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

int main() {
    Solution solution;
    vector<int> arr1 = {1,2,4};
    vector<int> arr2 = {1,3,4};
    ListNode* l1 = createLinkedListR(arr1);
    ListNode* l2 = createLinkedListR(arr2);
    traverseLinkedList(solution.mergeTwoLists(l1, l2));
    return 0;
}