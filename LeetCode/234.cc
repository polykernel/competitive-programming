/*
    Problem: 234. Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* rev = NULL;

        if (fast == NULL) return true;

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
            if (slow->val != rev->val) return false;
            slow = slow->next;
            rev = rev->next;
        }

        return true;
    }
};
