#include"23-MergekSortedLists.h"
using namespace std;

int main() {
	while (true)
	{
		int n;
		cin >> n;

		vector<ListNode*> lists;
		for (int i = 0;i < n;i++) {
			ListNode *head=new ListNode(0);
			ListNode *p = head;
			int a;
			while (cin >> a) {
				if (a == -1)
					break;
				ListNode *t = new ListNode(a);
				p->next = t;
				p = p->next;
			}
			lists.push_back(head->next);
		}

		Solution sol;

		ListNode *ans = sol.mergeKLists(lists);

		while (ans != NULL) {
			cout << ans->val<<" ";
			ans = ans->next;
		}
		cout << endl;
	}

	return 0;
}