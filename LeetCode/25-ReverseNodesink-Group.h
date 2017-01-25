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
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *ans = new ListNode(0);
		ListNode *p = ans;
		p->next = head;

		bool fail = false;
		while (p->next != NULL) {
			ListNode *l = p->next;
			ListNode *ll = p;
			ListNode *r, *rl;
			for (int i = 0;i < k / 2;i++) {
				r = l;
				rl = ll;
				for (int j = 0;j < k - 2 * i - 1;++j) {			
					r = r->next;
					rl = rl->next;
					if (r == NULL) {
						fail = true;
						break;
					}	
				}
				if (fail)
					break;

				ListNode *rr;
				rr = r->next;

				if (l->next == r) {
					r->next = l;
					l->next = rr;
				}
				else {
					r->next = l->next;
					l->next = rr;
					rl->next = l;
				}
				
				ll->next = r;

				ll = ll->next;
				l = ll->next;
			}
			if (fail)
				break;

			for (int i = 0;i < k;++i) {
				p = p->next;
			}
		}

		return ans->next;
	}
};