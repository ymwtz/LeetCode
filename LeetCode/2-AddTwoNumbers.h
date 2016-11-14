#pragma once

#include"stdafx.h"

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int c = 0;
		ListNode *h = new ListNode(-1);
		ListNode *l = h;
		while (l1 != NULL || l2 != NULL || c != 0) {
			if (l1 == NULL&&l2 != NULL) {
				l->next = new ListNode((l2->val + c) % 10);
				c = (l2->val + c) / 10;
				l2 = l2->next;
			}
			else if (l2 == NULL&&l1 != NULL) {
				l->next = new ListNode((l1->val + c) % 10);
				c = (l1->val + c) / 10;
				l1 = l1->next;
			}
			else if (l2 == NULL&&l1 == NULL) {
				l->next = new ListNode(c % 10);
				c = c / 10;
			}
			else {
				l->next = new ListNode((l1->val + l2->val + c) % 10);
				c = (l1->val + l2->val + c) / 10;
				l1 = l1->next;
				l2 = l2->next;
			}
			l = l->next;
		}
		return h->next;
	}
};