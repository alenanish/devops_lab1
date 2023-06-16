/*
# Copyright (c) https://github.com/alenanish/devops_lab1 . All rights reserved.
*/
#include <iostream>
#include <string>
#include "LinkedList.hpp"

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << "->";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

std::string getResult(ListNode* head) {
    std::string res = "";
    while (head) {
        std::string num = std::to_string(head->val);
        res.append(num);
        res.append("->");
        head = head->next;
    }
    res.append("nullptr");

    return res;
}

ListNode* createList(int n, int d) {
    ListNode* list = new ListNode(d);
    ListNode* head = list;
    for (int i = 1; i < n; i++) {
        ListNode* cur = new ListNode(d + 2 * i);
        list->next = cur;
        list = list->next;
    }
    return head;
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

std::string mergeTwoLists(int n, int m) {
    ListNode* list1 = createList(n, 0);
    printList(list1);

    ListNode* list2 = createList(m, 1);
    printList(list2);


    ListNode* head = nullptr;
    if (list1 && list2) {
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
    } else {
      list1 != nullptr ? head = list1 : list2 != nullptr ? head = list2 : head;
    }

    ListNode* cur = head;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            cur->next = list1;
            list1 = list1->next;
        } else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    if (!list1 && list2) {
        cur->next = list2;
    }
    if (!list2 && list1) {
        cur->next = list1;
    }
    std::string result = getResult(head);
    deleteList(head);
    return result;
}


std::string reverseList(int n) {
    ListNode* head = createList(n, 0);
    if (!head)
        return "nullptr";
    if (head->next == nullptr) {
        std::string result = getResult(head);
        deleteList(head);
        return result;
    }
    ListNode* next = nullptr;
    ListNode* cur = head;

    while (cur) {
        ListNode* tmp = cur->next;
        cur->next = next;
        next = cur;
        cur = tmp;
    }
    std::string result = getResult(next);
    deleteList(head);
    return result;
}

int countNodes(int n) {
    ListNode* head = createList(n, 0);
    int count = 0;
    while (head) {
        head = head->next;
        ++count;
    }
    deleteList(head);
    return count;
}

int countNodes(ListNode* head) {
    int count = 0;
    while (head) {
        head = head->next;
        ++count;
    }
    deleteList(head);
    return count;
}



std::string rotateRight(int n, int k) {
    ListNode* head = createList(n, 0);
    if (!head) {
        return "nullptr";
    }
    if (head->next == nullptr) {
        std::string result = getResult(head);
        deleteList(head);
        return result;
    }
    int count = countNodes(head);
    int i = 0;
    ListNode* prev = head;
    while (i < k % count) {
        while (prev) {
            if (prev->next) {
                if (prev->next->next == nullptr)
                    break;
            }
            prev = prev->next;
        }
        if (prev != nullptr) {
            ListNode* tmp = prev->next;
            prev->next = nullptr;
            tmp->next = head;
            head = tmp;
            prev = head;
            ++i;
        }
    }
    std::string result = getResult(head);
    deleteList(head);
    return result;
}


