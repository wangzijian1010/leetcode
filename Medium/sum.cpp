//
// Created by wangzijian on 2023/9/25.
//

// listnode


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        int carry = 0;

        while (l1 || l2 || carry){
           int sum =  (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
           carry = sum / 10;
           current->val = sum % 10;
           current = current->next;
           l1 = l1 ? l1->next : nullptr;
           l2 = l2 ? l2->next : nullptr;
        }

        return dummy->next;
    }
};