#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		vector<string> a;
		string ans;

		if (numRows == 1) {
			return s;
		}

		for (int i = 0;i<numRows;i++) {
			string t;
			a.push_back(t);
		}

		for (size_t i = 0;i<s.size();i++) {
			int r = i % (2 * numRows - 2);

			if (r<numRows) {
				a[r].push_back(s[i]);
			}
			else {
				a[2 * numRows - 2 - r].push_back(s[i]);
			}
		}

		for (int i = 0;i < numRows;++i) {
			ans += a[i];
		}

		return ans;
	}
};