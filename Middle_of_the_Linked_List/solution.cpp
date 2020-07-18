#include <iostream>
#include <stack> 
#include <cmath>
#include "solution.h"

using namespace std;

ListNode* Solution::middleNode(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast!=nullptr&&fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
