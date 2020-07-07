#include <iostream>
#include <stack> 
#include "solution.h"

using namespace std;

ListNode* Solution::removeElements(ListNode* head, int val) {
	if (head == nullptr) {
		return head;
	}
	ListNode* p = head;
	//以p->next查找待删除节点
	while (p->next != nullptr) {
		if (p->next->val == val) {
			if (p->next->next != nullptr) {
				//此时，p->next是待删除节点
				*(p->next) = *(p->next->next);
			} else {
				p->next = nullptr;
			}
		} else {
			p = p->next;
		}
	}
	//使用p->next查找，从头节点的后继开始查找，无法删除头结点
	if (head->val == val) {
		head = head->next;
	}
	return head;
}
