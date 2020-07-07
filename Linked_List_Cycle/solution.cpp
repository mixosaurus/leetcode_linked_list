#include <iostream>
#include "solution.h"

using namespace std;

bool Solution::hasCycle(ListNode* head) {
    //可首先排除null、一节点、两节点情况，因为只有三个节点的链表才有可能有环
    //在此处排除null、一节点情况，两节点在下面执行中可排除
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode* fast = head->next;
    ListNode* slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        if (fast == slow) {
            return true;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}
