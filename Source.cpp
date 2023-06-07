#include <iostream>

using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
     ListNode(ListNode* head) : val(head->val), next(head->next) {}
};

 void printList(ListNode* head) {
     while (head) {
         cout << head->val << "->";
         head = head->next;
     }
     cout << "nullptr\n";
 }

 ListNode*  mergeTwoLists(ListNode* list1, ListNode* list2) {
     ListNode* head = nullptr;
     if (list1 && list2 ) {
         if (list1->val < list2->val) {
             head = list1;
             list1 = list1->next;
         }
         else {
             head = list2;
             list2 = list2->next;
         }
     }
     else {
         list1 != nullptr ? head = list1 : list2 != nullptr ? head = list2 : head;
     }


     //printList(head);
     ListNode* cur = head;
     while (list1 != nullptr && list2 != nullptr) {
         if (list1->val < list2->val) {
             cur->next = list1;
             list1 = list1->next;
         }
         else {
             cur->next = list2;
             list2 = list2 -> next;
         }
         cur = cur->next;
     }
     if (!list1 && list2) {
         cur->next = list2;
     }
     if (!list2 && list1) {
         cur->next = list1;
     }
     //printList(head);
     return head;
 }


ListNode* reverseList(ListNode* head) {
    if (!head || head->next == nullptr)
        return head;
    ListNode* next = nullptr;
    ListNode* cur = head;

    while (cur) {
        ListNode* tmp = cur->next;
        cur->next = next;
        next = cur;
        cur = tmp;
    }
    return next;
}

int countNodes(ListNode* head) {
    int count = -1;
    while (head) {
        head = head->next;
        ++count;
    }
    return count;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (head->next == nullptr || !head)
        return head;
    int count = countNodes(head);
    int i = 0;
    ListNode* prev = head;
    while (i < k % count) {

        while (prev)
        {
            if (prev->next)
            {
                if (prev->next->next == NULL)
                    break;
            }
            prev = prev->next;
        }
        if (prev != NULL) {
            ListNode* tmp = prev->next;
            prev->next = NULL;
            tmp->next = head;
            head = tmp;
            prev = head;
            ++i;
        }
    }
    return head;
}

void deleteList(ListNode* head) {
    while (head)
    {
        ListNode* next = head->next;
        delete head;
        head = next;
    }

}

int main() {
    int n, m;
    std::cin >> n;
    std::cin >> m;
    ListNode* list1 = new ListNode(1);
    ListNode* head1 = list1;
    for (int i = 2; i <= n ; ++i) {
        //if (i % 2 == 0) {
            ListNode* cur = new ListNode(i);
            list1->next = cur;
            list1 = list1->next;
        //}
    }
    //printList(head1);
    ListNode* list2 = new ListNode;
    ListNode* head2 = list2;
    list2->val = 0 ;
    for (int i = 1; i <= m; ++i) {
        if (i % 2 != 0) {
            ListNode* tmp = new ListNode(i);
            list2->next = tmp;
            list2 = list2->next;
        }
    }
    //printList(head2);
    ListNode* head = mergeTwoLists(head1, head2);
    printList(head);
    deleteList(head);

    //head1 = reverseList(head1);
    //printList(head1);

    //head1 = rotateRight(head1, 2);
    //printList(head1);

}
