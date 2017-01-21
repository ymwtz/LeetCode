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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *ans = new ListNode(0);

		if (lists.size() == 0)
			return ans->next;

		vector<ListNode*> p;
		int n = 0;
		for (int i = 0;i < lists.size();++i) {
			ListNode *t;
			t = lists[i];
			p.push_back(t);
			if (t != NULL)
				n++;
		}

		ListNode *q = ans;
		int init = 0;
		while (n > 0) {
			n = 0;

			while (init<p.size() && p[init] == NULL) {
				init++;
			}

			int j = init;
			int k = p[init]->val;
			for (int i = 0;i < p.size();++i) {
				if (p[i] == NULL)
					continue;
				n++;
				if (p[i]->val < k) {
					k = p[i]->val;
					j = i;
				}
			}

			p[j] = p[j]->next;
			if (p[j] == NULL)
				n--;
			
			ListNode *t = new ListNode(k);
			q->next = t;
			q = q->next;
		}

		return ans->next;
	}
};