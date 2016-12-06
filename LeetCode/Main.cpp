#include"19-RemoveNthNodeFromEndofList.h"
using namespace std;

int main() {
	while (true)
	{
		int n;
		int t;
		ListNode *head = new ListNode(-1);
		ListNode *tail = head;
		while (cin >> t&&t >= 0) {
			ListNode *p = new ListNode(t);
			tail->next = p;
			tail = p;
		}
		cin >> n;
		Solution sol;
		sol.removeNthFromEnd(head->next, n);
	}

	return 0;
}