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
	ListNode* swapPairs(ListNode* head) {
		ListNode *ans = new ListNode(0); 
		ListNode *p = ans;
		p->next = head;
		
		while (p->next != NULL) {
			ListNode *l = p->next;
			ListNode *r = l->next;
			if (r == NULL)
				break;
			ListNode *q = r->next;
			p->next = r;
			l->next = q;
			r->next = l;

			p = l;
		}

		return ans->next;
	}
};