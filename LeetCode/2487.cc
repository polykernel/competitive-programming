/*
    Problem: 2487. Remove Nodes From Linked List
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
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> ms; // monotonic stack

        ListNode *p = head;
	while (p != NULL) {
            while (!ms.empty() && p->val > ms.back()->val) {
                ms.pop_back();
            }
            ms.push_back(p);
            p = p->next;
        }
        ms.push_back(NULL);

        for (int i = 0; i < ms.size(); i++) {
            ms[i]->next = ms[i+1];
        }
        
        return ms.front();
    }
};
