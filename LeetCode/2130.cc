/*
    Problem: 2130. Maximum Twin Sum of a Linked List
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
    int pairSum(ListNode* head) {
        int ans = 0;
        ListNode* rev;
        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != NULL) {
            rev = new ListNode(slow->val, rev);
            if (fast->next != NULL) {
                fast = fast->next->next;
                slow = slow->next;
            }
            else {
                fast = fast->next;
            }
        }

        slow = slow->next;

        while (slow != NULL) {
            ans = max(ans, rev->val + slow->val);
            slow = slow->next;
            rev = rev->next;
        }

        return ans;
    }
};
