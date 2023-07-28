/*
    Problem: 206. Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode* current_node = head;
        ListNode* next_node = current_node->next;
        current_node->next = NULL;

        while (next_node != NULL) {
            ListNode* aux_node = next_node->next;
            next_node->next = current_node;
            current_node = next_node;
            next_node = aux_node;
        }

        return current_node;
    }
};
