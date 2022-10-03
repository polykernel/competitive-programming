/*
    Problem: 141. Linked List Cycle
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fp = head;
        ListNode* sp = head;

        while (fp != NULL) {
            fp = fp->next;

            if (fp != NULL) {
                fp = fp->next;
                sp = sp->next;
            }

            if (fp == sp) return true;
        }

        return false;
    }
};
