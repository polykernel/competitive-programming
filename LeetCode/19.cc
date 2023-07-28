/*
    Problem: 19. Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fp = head;
        ListNode* sp = head;

        while (n--) {
            fp = fp-> next;
        }

        if (fp == NULL) return sp->next;

        while (fp->next != NULL) {
            sp = sp->next;
            fp = fp->next;
        }

        sp->next = sp->next->next;

        return head;
    }
};
