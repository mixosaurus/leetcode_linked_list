#include "Solution.h"

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    return add(l1, l2, false);
}

// carry 表示低位是否向高位进位
ListNode* Solution::add(ListNode* l1, ListNode* l2, bool carry) {
    // sum为两个链表的对应两位及借位之和
    int sum = 0;
    // 先将进位加到和中
    if (carry) {
        sum = sum + 1;
    }
    if (l1 == nullptr && l2 == nullptr) {
        // l1、l2均为null时，且无低位的进位时，结束运算
        // l1、l2均为null时，且有低位的进位时，说明本位为结果的最高位
        // 如998+2=1000，结果1000的最高位为1，此时sum为1
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
        // 两位之和=10时，如7+9=16，则该位应为16-10即6，且同时向高位进位
        ListNode* node = new ListNode(sum - 10);
        // sum>=10，需要进位，将carry设为true
        // 判断l1、l2是否为null，防止空指针异常
        node->next = add(l1 == nullptr ? nullptr : l1->next, l2 == nullptr ? nullptr : l2->next, true);
        return node;
    } else {
        ListNode* node = new ListNode(sum);
        // sum<10，不需要进位，将carry设为false
        // 判断l1、l2是否为null，防止空指针异常
        node->next = add(l1 == nullptr ? nullptr : l1->next, l2 == nullptr ? nullptr : l2->next, false);
        return node;
    }
}
