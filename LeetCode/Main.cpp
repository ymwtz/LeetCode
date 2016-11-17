#include"10-RegularExpressionMatching.h"
using namespace std;

int main() {
	while (true)
	{
		string s, p;
		cin >> s >> p;
		Solution sol;
		bool f = sol.isMatch(s, p);
		if (f)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}

	return 0;
}