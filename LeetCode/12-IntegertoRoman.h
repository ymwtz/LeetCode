#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		char r[4][4] = { {'I','V','X'},{'X','L','C'},{'C','D','M'},{'M'} };
		int t = num;
		vector<int> n;
		string ans;

		while (t != 0) {
			n.push_back(t % 10);
			t /= 10;
		}

		for (int i = n.size() - 1;i >= 0;i--) {
			if (n[i] >= 1 && n[i] <= 3) {
				for (int j = 0;j < n[i];j++) {
					ans.push_back(r[i][0]);
				}
			}
			else if (n[i]==4) {
				ans.push_back(r[i][0]);
				ans.push_back(r[i][1]);
			}
			else if (n[i] >= 4 && n[i] <= 8) {
				ans.push_back(r[i][1]);
				for (int j = 0;j < n[i]-5;j++) {
					ans.push_back(r[i][0]);
				}
			}
			else if (n[i] == 9) {
				ans.push_back(r[i][0]);
				ans.push_back(r[i][2]);
			}
		}

		return ans;
	}
};