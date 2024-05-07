/*
    Problem: 2816. Double a Number Represented as a Linked List
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
private:
    int rem[10] = {0, 2, 4, 6, 8, 0, 2, 4, 6, 8};
public:
    ListNode* doubleIt(ListNode* head) {
        if (head->val >= 5) {
            head = new ListNode(0, head);
        }

        ListNode* fp = head;
        while (fp != NULL) {
            int r = rem[fp->val];
            if (fp->next != NULL && fp->next->val >= 5) r++;
            fp->val = r;
            fp = fp->next;
        }

        return head;
    }
};
