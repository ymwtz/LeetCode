#include"10-RegularExpressionMatching.h"
using namespace std;

int main() {
	string s, p;
	cin >> s >> p;
	Solution sol;
	cout << sol.isMatch(s, p) << endl;
	return 0;
}