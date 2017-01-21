#include"24-SwapNodesinPairs.h"
using namespace std;

int main() {
	while (true)
	{
		ListNode *head = new ListNode(0);
		ListNode *p = head;

		int n;
		cin >> n;
		
		for (int i = 0;i < n;++i) {
			int a;
			cin >> a;
			ListNode *t = new ListNode(a);
			p->next = t;
			p = p->next;
		}

		Solution sol;
		p = sol.swapPairs(head->next);

		int i = 0;
		while(p!=NULL){
			if (i != 0)
				cout << "->";
			cout << p->val;
			p = p->next;
		}
		cout << endl;
	}

	return 0;
}