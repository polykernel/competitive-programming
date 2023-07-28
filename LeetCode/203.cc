/*
    Problem: 203. Remove Linked List Elements
    Difficulty: Easy
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res = new ListNode(0, head);
        ListNode* prev = res;
        ListNode* ptr = head;

        while (ptr != NULL) {
            if (ptr->val != val) {
                prev->next = ptr;
                prev = prev->next;
            }
            ptr = ptr->next;
        }

        prev->next = ptr;

        return res->next;
    }
};
