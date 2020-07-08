#include <iostream>
#include <stack> 
#include <cmath>
#include "solution.h"

using namespace std;

int Solution::getDecimalValue(ListNode* head) {
	//将base++在此处可获取递归实际执行次数
	if (head->next == nullptr) {
		return head->val;
	}
	//将base++置于此处，base的值正序增长
	int sub_val = getDecimalValue(head->next);
	//将base++置于此处，base的值逆序减少
	base++
	return head->val *pow(2,base) + sub_val;
 }
