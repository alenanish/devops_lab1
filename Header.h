#pragma once

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ListNode(ListNode* head) : val(head->val), next(head->next) {}
};

void printList(ListNode* head);

std::string getResult(ListNode* head);

ListNode* createList(int n, int d);

void deleteList(ListNode* head);
std::string mergeTwoLists(int n, int m);

std::string reverseList(int n);

int countNodes(int n);

int countNodes(ListNode* head);

std::string rotateRight(int n, int k);
