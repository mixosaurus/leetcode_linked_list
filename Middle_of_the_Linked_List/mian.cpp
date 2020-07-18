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

//876. 链表的中间结点
//测试样例实际上并无头结点
int main() {
    Solution solution;
    ListNode* head = nullptr;
    vector<int> arr = { 1,2,3,4,5,6 };
    head = createLinkedListR(arr);
    traverseLinkedList(solution.middleNode(head));
    return 0;
}