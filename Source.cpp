#include <iostream>
#include <string>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ListNode(ListNode* head) : val(head->val), next(head->next) {}
};

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
    while (head)
    {
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
        }
        else {
            head = list2;
            list2 = list2->next;
        }
    }
    else {
        list1 != nullptr ? head = list1 : list2 != nullptr ? head = list2 : head;
    }

    ListNode* cur = head;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            cur->next = list1;
            list1 = list1->next;
        }
        else {
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
    return head;
}



int main() {
    int n, m;
    std::cin >> n;
    std::cin >> m;

    std::cout << mergeTwoLists(n, m);
    //printList(head);
    //deleteList(head);

    //head1 = reverseList(head1);
    //printList(head1);

    //head1 = rotateRight(head1, 2);
    //printList(head1);

}