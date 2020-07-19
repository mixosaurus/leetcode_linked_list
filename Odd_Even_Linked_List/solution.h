#pragma once
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() :val(0),next(nullptr){}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head);
};