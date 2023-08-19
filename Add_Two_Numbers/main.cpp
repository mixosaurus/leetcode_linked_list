#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;

void traverseLinkedList(ListNode* node) {
    if (node == nullptr) {
        cout << "链表为空" << endl;
    }
    while (node != nullptr) {
        if (node->next == nullptr) {
            cout << node->val;
        } else {
            cout << node->val << ",";
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

// 2. 两数相加
int main(){
    Solution solution;
    traverseLinkedList(solution.addTwoNumbers(createLinkedListR({ 8,9,9 }), createLinkedListR({ 2 })));
}
