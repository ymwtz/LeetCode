#include"22-GenerateParentheses.h"
using namespace std;

int main() {
	while (true)
	{
		int n;
		cin >> n;
		Solution sol;
		vector<string> ans = sol.generateParenthesis(n);
		for (int i = 0;i < n;i++) {
			cout << ans[i] << endl;
		}
	}

	return 0;
}