/*
    Problem: 2095. Delete the Middle Node of a Linked List
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* res = new ListNode(0, head);
        ListNode* slow = res;
        ListNode* fast = head->next;

        while (fast != NULL) {
            if (fast->next != NULL) {
                fast = fast->next->next;
            }
            else {
                fast = fast->next;
            }
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return res->next;
    }
};
