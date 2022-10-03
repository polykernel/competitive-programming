/*
    Problem: 86. Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* part1 = new ListNode(0);
        ListNode* part2 = new ListNode(0);
        ListNode* part1head = part1;
        ListNode* part2head = part2;

        while (head != NULL) {
            if (head->val < x) {
                part1->next = new ListNode(head->val);
                part1 = part1->next;
            }
            else {
                part2->next = new ListNode(head->val);
                part2 = part2->next;
            }
            head = head->next;
        }

        part1->next = part2head->next;

        return part1head->next;
    }
};


