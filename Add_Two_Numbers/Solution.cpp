#include "Solution.h"

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    return add(l1, l2, false);
}

// carry 表示低位是否向高位进位
ListNode* Solution::add(ListNode* l1, ListNode* l2, bool carry) {
    // sum为两个链表的对应两位及借位之和
    int sum = 0;
    if (carry) {
        sum = sum + 1;
    }
    if (l1 == nullptr && l2 == nullptr) {
        if (!carry) {
            return nullptr;
        }
    }
    if (l1 == nullptr && l2!=nullptr) {
        sum = sum + l2->val;
    }
    if (l2 == nullptr && l1 != nullptr) {
        sum = sum + l1->val;
    }
    if (l1 != nullptr && l2 != nullptr) {
        sum = sum + l1->val + l2->val;
    }
    if (sum >= 10) { 
        ListNode* node = new ListNode(sum - 10);
        // sum>=10，需要进位，将carry设为true
        node->next = add(l1 == nullptr ? nullptr : l1->next, l2 == nullptr ? nullptr : l2->next, true);
        return node;
    } else {
        // sum<10，不需要进位，将carry设为false
        ListNode* node = new ListNode(sum);
        // 防止空指针异常，
        node->next = add(l1 == nullptr ? nullptr : l1->next, l2 == nullptr ? nullptr : l2->next, false);
        return node;
    }
}
