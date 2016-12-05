#include"18-4Sum.h"
using namespace std;

int main() {
	while (true)
	{
		vector<int> a;
		int n;
		Solution sol;
		int tar;
		cin >> tar;
		cin >> n;
		for (int i = 0;i < n;++i) {
			int t;
			cin >> t;
			a.push_back(t);
		}
		sol.fourSum(a, tar);
	}

	return 0;
}