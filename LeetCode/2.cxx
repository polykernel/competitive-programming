/*
    Problem: 2. Add Two Number
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
        int carry = 0;
        ListNode* ans = new ListNode();
        ListNode* res = ans;

        while (l1 != NULL && l2 != NULL) {
            ans->next = new ListNode((l1->val + l2->val + carry) % 10);
            if (l1->val + l2->val + carry < 10) carry = 0;
            else carry = 1;
            l1 = l1->next;
            l2 = l2->next;
            ans = ans->next;
        }

        while (l1 != NULL) {
            ans->next = new ListNode((l1->val + carry) % 10);
            if (l1->val + carry < 10) carry = 0;
            else carry = 1;
            l1 = l1->next;
            ans = ans->next;
        }

        while (l2 != NULL) {
            ans->next = new ListNode((l2->val + carry) % 10);
            if (l2->val + carry < 10) carry = 0;
            else carry = 1;
            l2 = l2->next;
            ans = ans->next;
        }

        if (carry > 0) ans->next = new ListNode(carry);

        return res->next;
    }
};
