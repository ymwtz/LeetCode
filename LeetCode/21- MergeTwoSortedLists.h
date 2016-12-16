#pragma once

#include"stdafx.h"

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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head=new ListNode(-1);

		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *ans = head;

		while (p1 || p2) {
			if (!p1) {
				head->next = p2;
				p2 = p2->next;
				head = head->next;
			}
			else if (!p2) {
				head->next = p1;
				p1 = p1->next;
				head = head->next;
			}
			else if (p1->val >= p2->val) {
				head->next = p2;
				p2 = p2->next;
				head = head->next;
			}
			else if (p1->val < p2->val) {
				head->next = p1;
				p1 = p1->next;
				head = head->next;
			}
		}

		return ans->next;
	}
};