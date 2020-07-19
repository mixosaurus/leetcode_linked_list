#include <iostream>
#include "solution.h"

using namespace std;

ListNode* Solution::oddEvenList(ListNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	ListNode* odd = head;
	//奇数子链表头节点
	ListNode* oddHead = odd;
	ListNode* even = head->next;
	//偶数子链表头节点
	ListNode* evenHead = even;
	//循环条件为分为原链表长度为奇数和偶数两种情况
	//even!=nullptr对应长度为偶数情况，even->next!=nullptr对应长度为奇数情况
	while (even!= nullptr && even->next!= nullptr) {
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	//由于一次循环执行两次划分操作，因此odd总是even前驱
	odd->next = evenHead;
	return head;
}
