#include <iostream>
#include <stack> 
#include <cmath>
#include "solution.h"

using namespace std;

ListNode* Solution::swapPairs(ListNode* head) {
	if (head == nullptr||head->next==nullptr) {
		return head;
	}
	ListNode* first= head;
	ListNode* second = head->next;
	//下面两步为交换节点
	//交换后，first指向第二个节点，second指向第一个节点
	first->next = head->next->next;
	second->next = first;
	//使head重新指向第一个节点
	head = second;
	//假设递归返回下一个链表的头结点
	//假设时，代码逻辑并不存在，而是以此为前提构建代码逻辑
	//必须以此为前提进行其他操作，假设返回头节点可使后续操作更加简
	//使当前链表与递归结果连接
	head->next->next=swapPairs(first->next);
	return head;
}
