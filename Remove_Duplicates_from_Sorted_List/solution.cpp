#include <iostream>
#include <stack> 
#include "solution.h"

using namespace std;

bool Solution::isPalindrome(ListNode* head) {
    //null链表和一个节点的链表算作回文链表
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    bool isPalindrome = true;
    ListNode* p = head;
    ListNode* fast = head;
    ListNode* slow = head;
    stack<int> stack;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        //将前半段入栈
        stack.push(slow->val);
        fast = fast->next->next;
        slow = slow->next;
    }
    //根据while循环结束时fast指针所处位置判断链表节点个数奇偶，偶数情况下，让slow所指节点入栈
    if (fast->next != nullptr && fast->next->next == nullptr) {
        stack.push(slow->val);
    }
    //使slow从中点（奇数）或中点的上一个节点（偶数）移动到后半段开始位置
    slow = slow->next;
    while (!stack.empty()) {
        if (stack.top() != slow->val) {
            isPalindrome = false;
        }
        slow = slow->next;
        stack.pop();
    }
    return isPalindrome;
}

