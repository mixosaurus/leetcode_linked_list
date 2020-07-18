#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;

void traverseLinkedList(ListNode* node) {
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

//234. ╩ьнда╢╠М
int main() {
    Solution solution;
    ListNode* head = nullptr;
    vector<int> arr = { 1,2,3,3,2,1 };
    head = createLinkedListR(arr);
    cout<<"is palindrome: "<<boolalpha<<solution.isPalindrome(head);
    return 0;
}