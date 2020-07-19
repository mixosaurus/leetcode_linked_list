#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;

//遍历链表
void traverseLinkedList(ListNode* node) {
    if (node == nullptr) {
        cout << "链表为空" << endl;
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

//创建链表
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

//24. 两两交换链表中的节点
int main() {
    Solution solution;
    ListNode* head = nullptr;
    vector<int> arr = { 1,2,3,4 };
    head = createLinkedListR(arr);
    traverseLinkedList(solution.swapPairs(head));
    return 0;
}