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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p = head;
		vector<ListNode*> list;

		while (p) {
			list.push_back(p);
			p = p->next;
		}

		size_t pos = list.size() - n;
		if (pos == 0) {
			p = head;
			head = head->next;
			delete p;
		}
		else{
			list[pos - 1]->next = list[pos]->next;
			delete list[pos];
		}

		return head;
	}
};