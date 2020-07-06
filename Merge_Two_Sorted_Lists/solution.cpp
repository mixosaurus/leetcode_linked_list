#include <iostream>
#include <stack> 
#include "solution.h"

using namespace std;

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* p = l1;
    ListNode* q = l2;
    //尾指针，始终指向结果链表尾部
    //在第一次循环时初始化
    //若其始终为空，说明没有进行过归并操作，即while循环并未执行
    //可将其是否为空作为判断条件
    ListNode* r = nullptr;
    //结果链表，用以接收两链表中的最小节点
    //接收后，可将其与其后链表断开，也可不断开
    ListNode* result = nullptr;
    //在第一次循环时，取下最小值节点作为头结点
    //此处的取下并非必须将头节点与其后断开，也可以不断开
    while (p!=nullptr&&q!=nullptr) {
        //p所指节点为最小值节点
        if (p->val <= q->val) {
            if (r == nullptr) {
                r = p;
                result = r;
                p = p->next;
            } else {
                r->next = p;
                p = p->next;
                r = r->next;
            }
        } 
        //q所指节点为最小值节点
        else {
            if (r == nullptr) {
                r = q;
                result = r;
                q = q->next;
            } else {
                r->next = q;
                q = q->next;
                r = r->next;
            }
        }
    }
    if (p != nullptr && q == nullptr) {
        if (r != nullptr) {
            r->next = p;
        } else {
            return p;
        }
    }
    if (q != nullptr && p == nullptr) {
        if (r != nullptr) {
            r->next = q;
        } else {
            return q;
        }
    }
    return result;
}
