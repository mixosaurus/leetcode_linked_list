#include <iostream>
#include <stack> 
#include "solution.h"

using namespace std;

ListNode* Solution::deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* p = head;
    ListNode* q = head;
    //该条件限制了单个节点的情况
    while (p->next != nullptr) {
        //无需使p所指元素与其自身比较
        q = p->next;
        while (q != nullptr) {
            if (p->val == q->val) {
                if (q->next != nullptr) {
                    //当q指向最后一个节点时，无法用改方式删除
                    *q = *(q->next);
                } else {
                    //当q指向最后一个节点时，此时p所指节点恰好为q所指节点的前驱
                    //由于无法用*q = *(q->next)删除最后一个节点，直接将p所指节点作为最后一个节点
                    p->next = nullptr;
                    return head;
                }
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
    return head;
}
